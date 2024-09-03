#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "student_answer.h"
// #include "student_answer_add.c"
// #include "student_answer_find.c"

void deleteElement(LinkedList_t* list, LinkedListElement_t* element)
// which will delete the element from the linked list. After deletion of 
// the element you should still be able to traverse, or chain, from the head to the tail. ALL dynamic memory must be freed!

// 1.) element being NULL or not actually being a member of the linked list
// 2.) element being at either the head or tail
// 3.) The linked list only having one element, which is going to be deleted.

{
    //LinkedListElement_t* current = list->head;
    if (element == NULL) {
        return;
    }

    // Initialize current to the head of the list
    LinkedListElement_t* current = list->head;
    LinkedListElement_t* previous = NULL;

    // Traverse the list to find the element
    while (current != NULL) {
        if (current == element) {
            // Element found, remove it
            if (previous == NULL) {
                // Element is the head
                list->head = current->next;
            } else {
                // Element is in the middle or end
                previous->next = current->next;
            }

            // If element is the tail, update the tail
            if (current == list->tail) {
                list->tail = previous;
            }

            // Free the memory for the element
            free(element);
            return;
        }

        // Move to the next element
        previous = current;
        current = current->next;
    }

    free(element);
}

int main() 

{
    LinkedList_t alist = {.head = NULL, .tail = NULL};
    LinkedListElement_t* element;
    addElement(&alist, 'a');
    addElement(&alist, 'b');
    addElement(&alist, 'c');
    element = findElement(&alist, 'b');
    deleteElement(&alist, element);
    for (LinkedListElement_t* elem=alist.head; elem != NULL; elem = elem->next) {
        printf("%c", elem->data);
    }
    //Clean up
    while (alist.head != NULL) {
        deleteElement(&alist, alist.head);
    }    
}