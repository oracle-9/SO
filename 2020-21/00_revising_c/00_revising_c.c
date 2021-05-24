#include "00_revising_c.h"

#include <stddef.h>

void fill_int(int* begin, int const* const end, int const value) {
    for ( ; begin != end; ++begin) {
        *begin = value;
    }
}

int* find_int(int const* begin, int const* const end, int const key) {
    for ( ; begin != end; ++begin) {
        if (*begin == key) {
            return (int*) begin;
        }
    }
    return NULL;
}
