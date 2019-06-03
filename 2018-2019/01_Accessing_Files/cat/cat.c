/*
 * Description : University of Minho Operating Systems 2018/2019 worksheet 1
 *               solved exercises 2 and 3.
 *               Resolução do exercício 2 da ficha 1 de Sistemas Operativos
 *               2018/2019 da Universidade do Minho.
 * Copyright   : © Oracle, 2019
 * License     : MIT
 * Maintainer  : oracle.uminho@gmail.com
 */

#include <fcntl.h>
#include <unistd.h>

#ifdef USE_HEAP
#    include <stdlib.h> /* possible malloc */
#endif

void cat(void) {
    char buf;
    while (read(STDIN_FILENO, &buf, 1) > 0) {
        write(STDOUT_FILENO, &buf, 1);
    }
}

void cat_buffered(size_t buffer_size) {
#ifdef USE_HEAP
    char *buf = malloc(buffer_size);
#else
    char buf[buffer_size];
#endif

    int n;
    while ((n = read(STDIN_FILENO, buf, buffer_size)) > 0) {
        write(STDOUT_FILENO, buf, n);
    }

#ifdef USE_HEAP
    free(buf);
#endif
}

/*
 * Compile with -D BUFFER_SIZE=x to call cat_buffered with a buffer of x bytes,
 * otherwise cat will be called.
 * Flag USE_HEAP can be used to use heap instead of stack.
 *
 * Example:
 * gcc cat.c -D USE_HEAP -D BUFFER_SIZE=2048
 */
int main(void) {
#ifdef BUFFER_SIZE
    cat_buffered(BUFFER_SIZE);
#else
    cat();
#endif
}
