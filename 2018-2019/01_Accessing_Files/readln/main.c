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

#include <fcntl.h>
#include <stdlib.h> /* strtoul, possible malloc */
#include <unistd.h>

enum ErrorCodes {
    ERR_INV_ARGC     = 1,
    ERR_INV_ARGV     = 2,
    ERR_OPEN_FAILED  = 3,
    ERR_CLOSE_FAILED = 4,
    ERR_WRITE_FAILED = 5
};

/*
 * Program must be called with the first argument being the file path, and the
 * second the maximum number of characters to be read.
 * Compilation flag USE_HEAP can be used to use heap instead of stack.
 *
 * Example:
 * gcc readln.c main.c -D USE_HEAP -o readln
 * ./readln myfile.txt 80
 */
int main(int argc, const char **argv) {
    if (argc < 3) {
        return ERR_INV_ARGC;
    }

    const size_t buf_size = strtoul(argv[2], NULL, 10);
    if (!buf_size) {
        return ERR_INV_ARGV;
    }

    const int in = open(argv[1], O_RDONLY);
    if (-1 == in) {
        return ERR_OPEN_FAILED;
    }

#ifdef USE_HEAP
    char *const buf = malloc(buf_size);
#else
    char buf[buf_size];
#endif
    const ssize_t read_chars = readln(in, buf, buf_size);

    if (close(in) == -1) {
        return ERR_CLOSE_FAILED;
    }

    if (write(STDOUT_FILENO, buf, read_chars) == -1) {
        return ERR_WRITE_FAILED;
    }

#ifdef USE_HEAP
    free(buf);
#endif
}
