# echo -e colors
# WARN : don't put " and use the echo command, not echo -e
LIGHT_ORANGE_COLOR=\e[38;5;216m
TURQUOISE_COLOR=\e[38;5;43m
LIGHT_BLUE_COLOR=\e[38;5;153m
RED_COLOR=\e[38;5;196m
NO_COLOR=\e[0m

# paths
BIN_MAIN=bin/main
INC_MAIN=inc/main

BIN_TEST=bin/test
INC_TEST=inc/test

BINS=$(BIN_MAIN) $(BIN_TEST)

# vars
ECHO = @echo # @echo hides this command in terminal, not its output

CC=g++
GDB_DEBUGGER_FLAGS=-g
PERSONAL_COMPIL_FLAGS=-D DEBUG # use own flags, see util.hpp
CFLAGS=-I $(INC_MAIN) -march=native -O3 $(PERSONAL_COMPIL_FLAGS) $(GDB_DEBUGGER_FLAGS)
LDLIBS=
LDFLAGS=--ansi --pedantic -Wall --std=c++11

SRCS_MAIN=$(wildcard src/main/**/*.cpp) $(wildcard src/main/*.cpp)
SRCS_TEST=$(wildcard src/tests/**/*.cpp) $(wildcard src/tests/*.cpp)
OBJS_MAIN=$(SRCS_MAIN:src/%.cpp=obj/%.o)
OBJS_TEST=$(SRCS_TEST:src/%.cpp=obj/%.o)

# targets
# set default target : https://stackoverflow.com/questions/2057689/how-does-make-app-know-default-target-to-build-if-no-target-is-specified
.DEFAULT_GOAL := default
.PHONY: default build build_test build_all clean run run_test rebuild rebuild_all rr ww dirs

default: build

build: $(BIN_MAIN)

build_test: $(BIN_TEST)

build_all: $(BINS)

$(BIN_MAIN): $(OBJS_MAIN)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

obj/%.o: src/%.cpp
	mkdir -p $(dir $@)
	$(CC) -o $@ -c $^ $(CFLAGS)

$(BIN_TEST): $(OBJS_TEST)
	$(CC) -o $@ $^ $(LDFLAGS) $(LDLIBS)

obj/test/%.o: src/test/%.cpp
	mkdir -p $(dir $@)
	$(CC) -o $@ -c $^ $(CFLAGS) $(INC_TEST)

clean:
	rm -rf bin/* obj/*

run: $(BIN_MAIN)
	$(ECHO) "$(TURQUOISE_COLOR)*** Executing main *** $(NO_COLOR)"
	./$(BIN_MAIN)

run_test: $(BIN_TEST)
	$(ECHO) "$(TURQUOISE_COLOR)*** Executing test *** $(NO_COLOR)"
	./$(BIN_TEST)

# Determine this makefile's path.
# Be sure to place this BEFORE `include` directives, if any.
THIS_FILE := $(lastword $(MAKEFILE_LIST))

rebuild:
	@$(MAKE) -f $(THIS_FILE) clean
	@$(MAKE) -f $(THIS_FILE) build

rebuild_all:
	@$(MAKE) -f $(THIS_FILE) clean
	@$(MAKE) -f $(THIS_FILE) build_all

rr: # rebuild and rerun
	@$(MAKE) -f $(THIS_FILE) clean
	@$(MAKE) -f $(THIS_FILE) build
	@$(MAKE) -f $(THIS_FILE) run

ww: # where and what
	pwd
	ls -alt

dirs:
	mkdir -p bin/
	mkdir -p obj/
