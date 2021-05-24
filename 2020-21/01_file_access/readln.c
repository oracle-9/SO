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
        ret = 0;
        goto RET;
    }

    char const* const end = buf + nbyte;
    char* i = buf;
    for ( ; i != end; ++i) {
        ssize_t const n = read(fd, i, 1);
        if (n <= 0) {
            ret = n;
            break;
        }
        if (*i == '\n') {
            ret = i - buf;
            break;
        }
    }
    if (i != end) {
        *i = '\0';
    } else {
        i[-1] = '\0';
        ret = i - buf - 1;
    }

    RET:
    return ret;
}
