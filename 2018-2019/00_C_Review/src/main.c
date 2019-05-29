#include "Person.h"

#include <fcntl.h>
#include <stdio.h>

#define PERSON1_NAME "Oracle"
#define PERSON1_AGE 791
#define PERSON2_NAME "Roberto"
#define PERSON2_AGE 800

int main(void) {
    Person p1 = person_new(PERSON1_NAME, PERSON1_AGE); /* needs freeing */
    char *const name       = person_get_name(p1);      /* needs freeing */
    const unsigned int age = person_get_age(p1);

    printf("Person 1 {\n"
           "    name: %s\n"
           "    age: %u\n"
           "}\n",
           name,
           age);

    Person p2 = person_copy(p1);
    free(name);
    person_delete(p1);

    person_set_name(&p2, PERSON2_NAME);
    person_set_age(&p2, PERSON2_AGE);
    printf("\nPerson 2 {\n"
           "    name: %s\n"
           "    age: %u\n"
           "}\n",
           p2.name,
           p2.age);

    person_delete(p2);
}
