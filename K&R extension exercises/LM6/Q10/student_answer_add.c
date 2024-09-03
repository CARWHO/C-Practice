#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "student_answer.h"

void addElement(LinkedList_t* list, char data)
//which is to add a new element to the tail of list, where the element's data is to be given by data.

{
    LinkedListElement_t* newElement = (LinkedListElement_t*)calloc(1, sizeof(LinkedListElement_t));
    newElement->data = data;
    newElement->next = NULL;

    if (list->head == NULL) {
            list->head = newElement;
            list->tail = newElement;
    }

    else {
        list->tail->next = newElement;
        list->tail = newElement;
    }

}

// int main() 

// {
//     LinkedList_t alist = {.head = NULL, .tail = NULL};
//     addElement(&alist, 'a');
//     printf("The head element data is: %c\nThe tail element data is: %c\n", alist.head->data, alist.tail->data); 
// }