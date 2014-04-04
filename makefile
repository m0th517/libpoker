# compiler
CXX = clang++ -g

# variables for libecalc
INCLUDES=-I ./include/poker \
		 -I ../../dep/decimal_for_cpp/include
CXXFLAGS=-m64 -static -ansi -std=c++11 \
		 -MMD -MP 

ifeq ($(target),debug)
    CXXFLAGS +=-O0 -Weverything -Wno-c++98-compat #-Werror
else
    target = release
	CXXFLAGS +=-O3 -Wall
endif

# name ob linked lib
LIB_OUT = lib/$(target)/libpoker.a

# gobble a files for compilation
CPP_FILES = $(wildcard src/*.cpp)
OBJ_FILES = $(addprefix obj/$(target)/,$(notdir $(CPP_FILES:.cpp=.o)))
DEP_FILES = $(OBJ_FILES:.o=.d)

$(LIB_OUT): $(OBJ_FILES)
	ar rcs $@ $^

obj/$(target)/%.o: src/%.cpp
	$(CXX) $(INCLUDES) $(CXXFLAGS) $(LIBRARIES) -c -o $@ $<

all: $(LIB_OUT)

clean:
	rm -f $(OBJ_FILES)
	rm -f $(DEP_FILES)
	rm -f $(LIB_OUT)

-include $(DEP_FILES)

.PHONY: clean all
