#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "student_answer.h"

LinkedListElement_t* findElement(LinkedList_t* list, char data)

{
LinkedListElement_t* current = list->head;

while (current != NULL) {
        if (current->data == data) {
            return current;
        } 
        else {
            current = current->next;
        }
    }
    return NULL;
}


// int main()

// {
//     LinkedList_t alist = {.head = NULL, .tail = NULL};
//     LinkedListElement_t* element;
//     addElement(&alist, 'a');
//     addElement(&alist, 'b');
//     addElement(&alist, 'c');
//     element = findElement(&alist, 'b');
//     printf("Found element: %c\n", element->data); 
// }