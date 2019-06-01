# Description : University of Minho Operating Systems 2018/2019 worksheet 1
#               exercise 6 Makefile.
#               Makefile do exercício 6 da ficha 1 de Sistemas Operativos
#               2018/2019 da Universidade do Minho.
# Copyright   : © Oracle, 2019
# License     : MIT
# Maintainer  : oracle.uminho@gmail.com

_CC             = gcc
_WARN_FLAGS     = --std=c11 -pedantic -W -Wall
_OPTIMIZE_FLAGS = -O2 -march=native
_EXE            = nl

$(_EXE): nl.o readln.o
	$(_CC) $^ -o $@

clean:
	rm nl nl.o readln.o



nl.o: nl.c
	$(_CC) -c $(_WARN_FLAGS) $(_OPTIMIZE_FLAGS) $< -o $@

readln.o: ../readln/readln.c
	$(_CC) -c $(_WARN_FLAGS) $(_OPTIMIZE_FLAGS) $< -o $@
