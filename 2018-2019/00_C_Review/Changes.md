# Changes made from the original worksheet

## [EN]
- `Person` functions now have the prefix 'person', and have been renamed more consistently:
    - `new_person` -> `person_new`
    - `clone_person` -> `person_copy`
    - `destroy_person` -> `person_delete`
    - `person_age` -> `person_get_age`
    - `person_change_age` -> `person_set_age`
- Functions `person_get_name` and `person_set_name` were implemented to complement the age function variants;
- `const` qualifiers were added where it made sense (see [const correctness](https://isocpp.org/wiki/faq/const-correctness));
- A `Doxyfile` and documentation were added. Use `make docs` to generate it.

## [PT]
- As funções de `Person` têm agora o prefixo 'person', e foram renomeados de uma forma mais consistente:
    - `new_person` -> `person_new`
    - `clone_person` -> `person_copy`
    - `destroy_person` -> `person_delete`
    - `person_age` -> `person_get_age`
    - `person_change_age` -> `person_set_age`
- As funções `person_get_name` e `person_set_name` foram implementadas para complementar as funções 'age' correspondentes;
- Qualificadores `const` foram adicionados onde fazia sentido (ver [const correctness](https://isocpp.org/wiki/faq/const-correctness));
- Um `Doxyfile` e documentação foram adicionados. Usa `make docs` para a gerar.
