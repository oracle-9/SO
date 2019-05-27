#include "Person.h"

#include <stdio.h>
#include <stdlib.h>

#define PERSON_NAME "Oracle"
#define PERSON_AGE 791

int main(void) {
    Person p1 = person_new(PERSON_NAME, PERSON_AGE); /* needs freeing */
    char *const name       = person_get_name(p1);    /* needs freeing */
    const unsigned int age = person_get_age(p1);

    printf("Person 1 {\n"
           "    name: %s\n"
           "    age: %u\n"
           "}\n",
           name, age);

    Person p2 = person_copy(p1);
    free(name);
    person_delete(p1);

    person_set_name(&p2, "Roberto");
    person_set_age(&p2, 800);
    printf("\nPerson 2 {\n"
           "    name: %s\n"
           "    age: %u\n"
           "}\n",
           p2.name, p2.age);

    person_delete(p2);
}
