/*
 * Description : University of Minho Operating Systems 2018/2019 worksheet 0
 *               solved exercises.
 *               Resolução da ficha 0 de Sistemas Operativos 2018/2019 da
 *               Universidade do Minho.
 * Copyright   : © Oracle, 2019
 * License     : MIT
 * Maintainer  : oracle.uminho@gmail.com
 */

#ifndef PERSON_H
#define PERSON_H

#define MAX_NAME_LEN 512 /**< Maximum length for the name string */

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
Person person_new(const char *name, unsigned int age);

/**
 * Creates a copy of a person.
 * @param p person to make a copy of.
 * @return the person copy.
 */
Person person_copy(const Person p);

/**
 * Frees the memory used by the person's name.
 * @param p the person.
 */
void person_delete(Person p);

/**
 * Returns a person's name.
 * @param p the person.
 * @return the person's name.
 */
const char *person_get_name(const Person p);

/**
 * Sets a person's name to the given name.
 * Only the first MAX_NAME_LEN characters are copied from the given name to the
 * person's name.
 * name must be a valid string.
 * @param p a pointer to the person.
 * @param name the name to be set.
 */
void person_set_name(Person *p, const char *name);

/**
 * Returns a person's age.
 * @param p the person.
 * @return the person's age.
 */
unsigned int person_get_age(const Person p);

/**
 * Sets a person's age to the given age.
 * @param p a pointer to the person.
 * @param age the age to be set.
 */
void person_set_age(Person *p, unsigned int age);

#endif
