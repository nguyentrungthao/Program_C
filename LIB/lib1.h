#ifndef LIB_1_H
#define LIB_1_H

#include <string.h>
#include <stdlib.h>

typedef struct PersonImpl Person;

Person* person_create(const char* name, const int age);
void person_set_age(Person* person, const int age);
int person_get_age(const Person* person);
void person_destroy(Person* person);



#endif // end define LIB_1_H