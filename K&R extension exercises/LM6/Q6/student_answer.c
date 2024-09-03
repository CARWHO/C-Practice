#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    char* name;
    uint8_t age;
    double height;
} Person_t;

Person_t* newPerson(const char* name, uint8_t age, double height) 
//newPerson() function returns a pointer to a newly allocated Person on the heap, with the name, age, and height fields set appropriately
//Here, the name field must be a dynamically allocated copy of the corresponding string parameter name

{
    Person_t* ptr = (Person_t*)calloc(1, sizeof(Person_t));
    
    ptr->name = (char*)calloc(strlen(name) +1, sizeof(char));
    strncpy(ptr->name, name, strlen(name) + 1);

    ptr->age = age;
    ptr->height = height;

    return ptr;
}

void freePerson(Person_t* person) 
//frees all memory that was allocated by newPerson() when creating the Person currently pointed to by the parameter.

{
    if (person != NULL) {
        free(person->name);
        free(person);
        //free(person->height);
        //free(person->age);
    }
}
    
int main(void)

{
    Person_t* employee = newPerson("Billy", 30, 1.68);
    printf("%s is age %d and is %.2f m tall\n", employee->name, employee->age, employee->height);
    freePerson(employee);
}