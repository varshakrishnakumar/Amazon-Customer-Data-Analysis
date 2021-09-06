EXE = project
TEST = test

OBJS = main.o Graph.o
TEST_OBJS = test.o Graph.o catchmain.o
OBJS_DIR = .objs

# other executables
# EXE_DFS = DFS
# OBJS_DFS = $(OBJS_DIR)/tests/DFStest.o $(OBJS_DIR)/Graph.o
# EXE_DFS = SCC
# OBJS_DFS = $(OBJS_DIR)/tests/SCCtest.o $(OBJS_DIR)/Graph.o

CLEAN_RM = $(EXE_DFS) $(EXE_SCC)

include cs225/make/cs225.mk

# $(EXE_DFS): $(OBJS_DFS)
# 	$(LD) $^ $(LDFLAGS) -o $@

# $(EXE_SCC): $(OBJS_SCC)
# 	$(LD) $^ $(LDFLAGS) -o $@


CXX = clang++
CXXFLAGS = $(CS225) -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm
# Custom Clang version enforcement logic:
ccred=$(shell echo -e "\033[0;31m")
ccyellow=$(shell echo -e "\033[0;33m")
ccend=$(shell echo -e "\033[0m")


IS_EWS=$(shell hostname | grep "ews.illinois.edu") 
IS_CORRECT_CLANG=$(shell clang -v 2>&1 | grep "version 6")
ifneq ($(strip $(IS_EWS)),)
ifeq ($(strip $(IS_CORRECT_CLANG)),)
CLANG_VERSION_MSG = $(error $(ccred) On EWS, please run 'module load llvm/6.0.1' first when running CS225 assignments. $(ccend))
endif
else
ifneq ($(strip $(SKIP_EWS_CHECK)),True)
CLANG_VERSION_MSG = $(warning $(ccyellow) Looks like you are not on EWS. Be sure to test on EWS before the deadline. $(ccend))
endif
endif

.PHONY: all test clean output_msg

all : $(EXE)

$(TEST) : output_msg $(TEST_OBJS)
	$(LD) $(TEST_OBJS) $(LDFLAGS) -o $(TEST)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXE) : output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXE)

main.o : main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

Graph.o : Graph.cpp Graph.h
	$(CXX) $(CXXFLAGS) Graph.cpp

# DFStest.o : tests/DFStest.cpp
# 	$(CXX) $(CXXFLAGS) tests/DFStest.cpp

Graph.o : Graph.cpp Graph.h
	$(CXX) $(CXXFLAGS) Graph.cpp 

test.o : tests/test.cpp Graph.h 
	$(CXX) $(CXXFLAGS) tests/test.cpp

catchmain.o : cs225/catch/catch.hpp cs225/catch/catchmain.cpp
	$(CXX) $(CXXFLAGS) cs225/catch/catchmain.cpp

clean :
	-rm -f *.o $(EXE) $(TEST) 