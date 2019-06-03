# Description : University of Minho Operating Systems 2018/2019 worksheet 1
#				exercise 5 Makefile.
#               Makefile do exercício 5 da ficha 1 de Sistemas Operativos
#			    2018/2019 da Universidade do Minho.
# Copyright   : © Oracle, 2019
# License     : MIT
# Maintainer  : oracle.uminho@gmail.com
 
_CC             = clang
_WARN_FLAGS     = --std=c11 -pedantic -W -Wall
_OPTIMIZE_FLAGS = -O2 -march=native

_SOURCE_DIR = src
_BIN_DIR    = bin
_OUT_DIR    = out
_EXE 	    = readln

_SOURCES = $(shell find $(_SOURCE_DIR) -name '*.c')

_BIN_OBJS = $(patsubst $(_SOURCE_DIR)/%.c,$(_OUT_DIR)/%.o,$(_SOURCES))



all: _bin_dir _out_dir $(_BIN_DIR)/$(_EXE)

clean:
	rm -rf $(_BIN_DIR) $(_OUT_DIR)



_bin_dir:
	@mkdir -p $(_BIN_DIR)

_out_dir:
	@mkdir -p $(_OUT_DIR)

$(_BIN_DIR)/$(_EXE): $(_BIN_OBJS)
	$(_CC) $^ -o $@

$(_BIN_OBJS): $(_OUT_DIR)/%.o : $(_SOURCE_DIR)/%.c
	mkdir -p $(dir $@)
	$(_CC) -c $(_WARN_FLAGS) $(_OPTIMIZE_FLAGS) $< -o $@
