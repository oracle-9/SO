/*
 * Description : University of Minho Operating Systems 2018/2019 worksheet 1
 *               solved exercise 6.
 *               Resolução do exercício 6 da ficha 1 de Sistemas Operativos
 *               2018/2019 da Universidade do Minho.
 * Copyright   : © Oracle, 2019
 * License     : MIT
 * Maintainer  : oracle.uminho@gmail.com
 */

#include "../readln/readln.h"

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define LINE_CHAR_LIMIT 512

enum ErrorCodes { ERR_OPEN_FAILED = 1, ERR_CLOSE_FAILED = 2 };

int main(int argc, char **argv) {
    const int in = (argc > 1) ? open(argv[1], O_RDONLY) : STDIN_FILENO;

    if (-1 == in) {
        return ERR_OPEN_FAILED;
    }

    char buf[LINE_CHAR_LIMIT];
    ssize_t read_chars;
    size_t line_num = 1;

    while ((read_chars = readln(in, buf, LINE_CHAR_LIMIT)) > 0) {
        if (1 == read_chars) {
            putchar('\n');
        } else {
            buf[read_chars] = '\0';
            printf("     %zu\t%s", line_num++, buf);
        }
    }

    if (close(in) == -1) {
        return ERR_CLOSE_FAILED;
    }
}
