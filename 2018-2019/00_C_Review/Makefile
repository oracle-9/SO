# Description : University of Minho Operating Systems 2018/2019 worksheet 0
#               Makefile.
#               Makefile da ficha 0 de Sistemas Operativos 2018/2019 da
#               Universidade do Minho.
# Copyright   : © Oracle, 2019
# License     : MIT
# Maintainer  : oracle.uminho@gmail.com
 
_CC             = clang
_WARN_FLAGS     = --std=c11 -pedantic -W -Wall
_OPTIMIZE_FLAGS = -O2 -march=native
_DEBUG_FLAGS    = -g
_PROF_FLAGS 	= -pg

_SOURCE_DIR = src
_HEADER_DIR = include
_BIN_DIR    = bin
_OUT_DIR    = out
_DEBUG_DIR  = debug
_PROF_DIR   = profile
_DOCS_DIR   = docs
_EXE 	    = person

_SOURCES = $(shell find $(_SOURCE_DIR) -name '*.c')
_HEADERS = $(shell find $(_HEADER_DIR) -name '*.h')

_BIN_OBJS   = $(patsubst $(_SOURCE_DIR)/%.c,$(_OUT_DIR)/%.o,$(_SOURCES))
_DEBUG_OBJS = $(patsubst $(_SOURCE_DIR)/%.c,$(_DEBUG_DIR)/%.o,$(_SOURCES))
_PROF_OBJS  = $(patsubst $(_SOURCE_DIR)/%.c,$(_PROF_DIR)/%.o,$(_SOURCES))



all: _bin_dir _out_dir $(_BIN_DIR)/$(_EXE)

debug: _debug_dir $(_DEBUG_DIR)/$(_EXE)

profile: _prof_dir $(_PROF_DIR)/$(_EXE)
	./$(_PROF_DIR)/$(_EXE)
	gprof ./$(_PROF_DIR)/$(_EXE)

docs: $(_HEADERS)
	doxygen Doxyfile

memcheck: debug
	valgrind --tool=memcheck --leak-check=yes ./$(_DEBUG_DIR)/$(_EXE)

clean:
	rm -rf gmon.out $(_BIN_DIR) $(_OUT_DIR) $(_DEBUG_DIR) $(_PROF_DIR) $(_DOCS_DIR)



_bin_dir:
	@mkdir -p $(_BIN_DIR)

_out_dir:
	@mkdir -p $(_OUT_DIR)

$(_BIN_DIR)/$(_EXE): $(_BIN_OBJS)
	$(_CC) $^ -o $@

$(_BIN_OBJS): $(_OUT_DIR)/%.o : $(_SOURCE_DIR)/%.c
	mkdir -p $(dir $@)
	$(_CC) -c -I$(_HEADER_DIR) $(_WARN_FLAGS) $(_OPTIMIZE_FLAGS) $< -o $@


_debug_dir:
	@mkdir -p $(_DEBUG_DIR)

$(_DEBUG_DIR)/$(_EXE): $(_DEBUG_OBJS)
	$(_CC) $^ -o $@

$(_DEBUG_OBJS): $(_DEBUG_DIR)/%.o : $(_SOURCE_DIR)/%.c
	mkdir -p $(dir $@)
	$(_CC) -c -I$(_HEADER_DIR) $(_WARN_FLAGS) $(_DEBUG_FLAGS) $< -o $@


_prof_dir:
	@mkdir -p $(_PROF_DIR)

$(_PROF_DIR)/$(_EXE): $(_PROF_OBJS)
	$(_CC) $^ $(_PROF_FLAGS) -o $@

$(_PROF_OBJS): $(_PROF_DIR)/%.o : $(_SOURCE_DIR)/%.c
	@mkdir -p $(dir $@)
	$(_CC) -c -I$(_HEADER_DIR) $(_WARN_FLAGS) $(_PROF_FLAGS) $< -o $@
