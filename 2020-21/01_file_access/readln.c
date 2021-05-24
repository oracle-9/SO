// readline utilty function that reads a line from a file.

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

#include <stddef.h>
#include <unistd.h>

ssize_t readln(int fd, char* buf, size_t nbyte) {
    ssize_t ret = 0;

    if (nbyte == 0) {
        goto RET;
    }

    char const* const end = buf + nbyte - 1;
    char* i = buf;
    for ( ; i != end; ++i) {
        ssize_t const n = read(fd, i, 1);
        if (n == -1) {
            // if read fails, we discard the whole line.
            *buf = '\0';
            ret = -1;
            goto RET;
        }
        if (n == 0 || *i == '\n') {
            break;
        }
    }

    ret = i - buf;
    *i = '\0';

    RET:
    return ret;
}
