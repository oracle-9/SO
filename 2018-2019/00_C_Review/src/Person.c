/*
 * Description : University of Minho Operating Systems 2018/2019 worksheet 0
 *               solved exercises.
 *               Resolução da ficha 0 de Sistemas Operativos 2018/2019 da
 *               Universidade do Minho.
 * Copyright   : © Oracle, 2019
 * License     : MIT
 * Maintainer  : oracle.uminho@gmail.com
 */

#define _POSIX_C_SOURCE 200809L /* strndup() */

#include "Person.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Person person_new(const char *name, unsigned int age) {
    return (Person){ .name = strndup(name, MAX_NAME_LEN), .age = age };
}

Person person_copy(const Person p) { return person_new(p.name, p.age); }

void person_delete(Person p) { free(p.name); }

const char *person_get_name(const Person p) { return p.name; }

void person_set_name(Person *p, const char *name) {
    free(p->name);
    p->name = strndup(name, MAX_NAME_LEN);
}

unsigned int person_get_age(const Person p) { return p.age; }

void person_set_age(Person *p, unsigned int age) { p->age = age; }
