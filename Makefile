DEPDIR := .d
$(shell mkdir -p $(DEPDIR) >/dev/null)
DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.Td

INCLUDE := $(wildcard include/**) include
INCLUDE := $(addprefix -I, $(INCLUDE))
FLAGS = -Wall -std=c++11
SRCS = $(wildcard src/**/*.cpp)
TEST_SRCS = $(wildcard tests/*.cpp)
COMPILE = g++ $(DEPFLAGS) $(FLAGS) $(INCLUDE) -c
LINK = g++ $(FLAGS) $(INCLUDE)
POSTCOMPILE = @mv -f $(DEPDIR)/$*.Td $(DEPDIR)/$*.d && touch $@
OUTPUT_OPTION = -o obj/$*.o
LIB = -pthread -lpthread lib/gtest_main.a

all : dir build

build: $(patsubst src/%.cpp, obj/%.o, $(SRCS)) obj/main.o
	$(LINK) $^ -o bin/exec
	bin/exec

obj/%.o : tests/%.cpp
obj/%.o : tests/%.cpp $(DEPDIR)/%.d
	$(COMPILE) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)

obj/%.o : src/%.cpp
obj/%.o : src/%.cpp $(DEPDIR)/%.d
	$(COMPILE) $(OUTPUT_OPTION) $<
	$(POSTCOMPILE)

test : $(patsubst src/%.cpp, obj/%.o, $(SRCS)) $(patsubst tests/%.cpp, obj/%.o, $(TEST_SRCS))
	$(LINK) $(LIB) $^ -o bin/testing
	bin/testing
	
dir : 
	mkdir -p bin obj $(patsubst src/%/, obj/%, $(dir $(SRCS))) $(patsubst tests/%/, obj/%, $(dir $(TEST_SRCS)))
	mkdir -p .d $(patsubst src/%/, .d/%, $(dir $(SRCS))) $(patsubst tests/%/, .d/%, $(dir $(TEST_SRCS)))

$(DEPDIR)/%.d: ;
.PRECIOUS: $(DEPDIR)/%.d

include $(wildcard $(patsubst %,$(DEPDIR)/%.d,$(basename main $(SRCS))))
include $(wildcard $(patsubst %,$(DEPDIR)/%.d,$(basename $(TEST_SRCS))))