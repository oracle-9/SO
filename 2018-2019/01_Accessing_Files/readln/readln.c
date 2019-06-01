/*
 * Description : University of Minho Operating Systems 2018/2019 worksheet 1
 *               solved exercise 5.
 *               Resolução do exercício 5 da ficha 1 de Sistemas Operativos
 *               2018/2019 da Universidade do Minho.
 * Copyright   : © Oracle, 2019
 * License     : MIT
 * Maintainer  : oracle.uminho@gmail.com
 */

#include "readln.h"

#include <unistd.h>

ssize_t readln(int fildes, void *buf, size_t nbyte) {
    size_t i = 0;

    while (i < nbyte) {
        const ssize_t n = read(fildes, (char *)buf + i, 1);
        if (n <= 0) {
            return n;
        }

        if ('\n' == ((char *)buf)[i++]) {
            break;
        }
    }

    return i;
}
