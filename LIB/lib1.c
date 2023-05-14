#include "lib1.h"

struct PersonImpl {
    char* name;
    int age;
};


Person* person_create(const char* name, const int age) {
    Person* person = (Person * )malloc(sizeof(Person));
    person->name = (char*)strdup(name);
    person->age = age;
    return person;
}

void person_set_age(Person* person, const int age) {
    person->age = age;
}

int person_get_age(const Person* person) {
    return person->age;
}

void person_destroy(Person* person) {
    free(person->name);
    free(person);
}