/*
 * Description : University of Minho Operating Systems 2018/2019 worksheet 1
 *               solved exercise 1.
 *               Resolução do exercício 1 da ficha 1 de Sistemas Operativos
 *               2018/2019 da Universidade do Minho.
 * Copyright   : © Oracle, 2019
 * License     : MIT
 * Maintainer  : oracle.uminho@gmail.com
 */

#define _POSIX_C_SOURCE 200809L /* truncate() */

#include <fcntl.h>
#include <unistd.h>

#define FILE_SIZE 1E+7 /* 10 MB */

enum ErrorCodes {
    ERR_INV_ARGC     = 1,
    ERR_OPEN_FAILED  = 2,
    ERR_TRUNC_FAILED = 3,
    ERR_CLOSE_FAILED = 4
};

/*
 * permission to:  user(u)   group(g)   other(o)
 *                 /¯¯¯\      /¯¯¯\      /¯¯¯\
 * octal:            6          6          6
 * binary:         1 1 0      1 1 0      1 1 0
 * what to permit: r w x      r w x      r w x
 *
 * binary         - 1: enabled, 0: disabled
 *
 * what to permit - r: read, w: write, x: execute
 *
 * permission to  - user: the owner that create the file/folder
 *                  group: the users from group that owner is member
 *                  other: all other users
 */

int main(int argc, const char **argv) {
    if (argc < 2) {
        return ERR_INV_ARGC;
    }

    const int out = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    if (-1 == out) {
        return ERR_OPEN_FAILED;
    }

    if (truncate(argv[1], FILE_SIZE) == -1) {
        return ERR_TRUNC_FAILED;
    }

    if (close(out) == -1) {
        return ERR_CLOSE_FAILED;
    }
}
