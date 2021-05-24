# Changes made from the original script

- append `int` suffix to both functions as to not give the false impression that they are generic (they're not):
    - `fill` -> `fill_int`;
    - `find` -> `find_int`.
- both functins take contiguous `int` iterators, instead of pointer and (signed) length;
- `find_int` returns the address of the first occurrence of `key` or `NULL` instead of its index;
- `const` qualifiers were added where it made sense (see [const correctness](https://isocpp.org/wiki/faq/const-correctness)).
