#include <fcntl.h>
#include <unistd.h>

#include <stdlib.h> /* strtoul, possible malloc */

enum ErrorCodes {
    ERR_INV_ARGC     = 1,
    ERR_INV_ARGV     = 2,
    ERR_OPEN_FAILED  = 3,
    ERR_CLOSE_FAILED = 4
};

ssize_t readln(int fildes, void *buf, size_t nbyte) {
    size_t i = 0;

    while (i < nbyte) {
        if (read(fildes, (char *)buf + i, 1) == -1) {
            return -1;
        }

        if ('\n' == ((char *)buf)[i++]) {
            break;
        }
    }

    return i;
}

/*
 * Program must be called with the first argument being the file path, and the
 * second the maximum number of characters to be read.
 * Flag USE_HEAP can be used to use heap instead of stack.
 *
 * Example:
 * gcc readln.c -D USE_HEAP -o readln.elf
 * ./readln.elf myfile.txt 80
 */
int main(int argc, const char *argv[]) {
    if (argc < 2) {
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
    ssize_t read_chars = readln(in, buf, buf_size);

    if (close(in) == -1) {
        return ERR_CLOSE_FAILED;
    }

    write(STDOUT_FILENO, buf, read_chars);
}
