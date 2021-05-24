// Simple version of the UNIX utilty cat.

// Copyright (C) 2018-2021 oracle
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

enum {
    SUCCESS,
    ERR_NO_BUF_SIZE,
    ERR_INV_BUF_SIZE,
    ERR_ALLOC_FAIL,
    ERR_READ_FAIL,
    ERR_WRITE_FAIL,
};

int main(int argc, char* argv[]) {
    char const* const prog_name = "mycat";
    int ret = SUCCESS;

    if (argc < 2) {
        fprintf(stderr, "%s: missing buffer size\n", prog_name);
        ret = ERR_NO_BUF_SIZE;
        goto RET;
    }

    size_t const buf_size = (size_t) strtoull(argv[1], NULL, 10);
    if (buf_size == 0) {
        fprintf(stderr, "%s: buffer size cannot be zero\n", prog_name);
        ret = ERR_INV_BUF_SIZE;
        goto RET;
    }

    char* const buf = malloc(buf_size);
    if (!buf) {
        fprintf(
            stderr,
            "%s: dynamic memory allocation failed: %s\n",
            prog_name,
            strerror(errno)
        );
        ret = ERR_ALLOC_FAIL;
        goto RET;
    }

    for (;;) {
        ssize_t const n = read(STDIN_FILENO, buf, buf_size);
        switch (n) {
        case -1:
            fprintf(
                stderr,
                "%s: read failed: %s\n",
                prog_name,
                strerror(errno)
            );
            ret = ERR_READ_FAIL;
            goto CLEANUP_BUF;
        case 0:
            goto CLEANUP_BUF;
        default:
            if (write(STDOUT_FILENO, buf, (size_t) n) == -1) {
                fprintf(
                    stderr,
                    "%s: write failed: %s\n",
                    prog_name,
                    strerror(errno)
                );
                ret = ERR_WRITE_FAIL;
                goto CLEANUP_BUF;
            }
        }
    }

    CLEANUP_BUF:
    free(buf);
    RET:
    return ret;
}
