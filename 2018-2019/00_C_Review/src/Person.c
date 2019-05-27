#include "Person.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Person person_new(const char *name, unsigned age) {
    return (Person){.name = strndup(name, MAX_NAME_LEN), .age = age};
}

Person person_copy(const Person p) {
    return (Person){.name = strndup(p.name, MAX_NAME_LEN), .age = p.age};
}

void person_delete(Person p) { free(p.name); }

char *person_get_name(const Person p) { return strdup(p.name); }

void person_set_name(Person *p, const char *name) {
    free(p->name);
    p->name = strndup(name, MAX_NAME_LEN);
}

unsigned int person_get_age(const Person p) { return p.age; }

void person_set_age(Person *p, unsigned int age) { p->age = age; }
