#ifndef PERSON_H
#define PERSON_H

/**
 * Maximum length for the name string.
 */
static const unsigned int MAX_NAME_LEN = 512;

/**
 * A person with a name and age.
 */
typedef struct Person {
    char *name;       /**< The person's name */
    unsigned int age; /**< The person's age */
} Person;

/**
 * Creates a person with the given name and age.
 * Only the first MAX_NAME_LEN characters are copied from the given name to the
 * person's name.
 * @param name the person's name.
 * @param age the person's age.
 * @return the created person.
 */
Person person_new(const char *name, unsigned age);

/**
 * Creates a copy of a person.
 * @param person the person to be copied.
 * @return the copied person.
 */
Person person_copy(const Person p);

/**
 * Frees the memory used by the person's name.
 * @param p the person.
 */
void person_delete(Person p);

/**
 * Returns a copy of a person's name.
 * @param person the person.
 * @return the person's name.
 */
char *person_get_name(const Person p);

/**
 * Sets a person's name to the given name.
 * Only the first MAX_NAME_LEN characters are copied from the given name to the
 * person's name.
 * @param person a pointer to the person.
 * @param new_name the person's new name.
 */
void person_set_name(Person *p, const char *name);

/**
 * Returns a person's age.
 * @param person the person.
 * @return the person's age.
 */
unsigned int person_get_age(const Person p);

/**
 * Sets a person's age to the given age.
 * @param person a pointer to the person.
 * @param new_age the person's new age.
 */
void person_set_age(Person *p, unsigned int age);

#endif
