/*
 * Description : University of Minho Operating Systems 2018/2019 worksheet 1
 *               solved exercise 5.
 *               Resolução do exercício 5 da ficha 1 de Sistemas Operativos
 *               2018/2019 da Universidade do Minho.
 * Copyright   : © Oracle, 2019
 * License     : MIT
 * Maintainer  : oracle.uminho@gmail.com
 */

#ifndef READLN_H
#define READLN_H

#include <stddef.h>
#include <sys/types.h>

ssize_t readln(int fildes, void *buf, size_t nbyte);

#endif
