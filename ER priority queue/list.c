/*
 * linkedlist.c
 *
 * Based on the implementation approach described in "The Practice 
 * of Programming" by Kernighan and Pike (Addison-Wesley, 1999).
 */

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "emalloc.h"
#include "list.h"


Patient *new_patient(char *name, int birth_year, int priority) {
    assert( name != NULL);

    Patient *temp = (Patient *)emalloc(sizeof(Patient));

    temp->name       = strdup(name);
    temp->birth_year = birth_year;
    temp->priority   = priority;
    temp->next       = NULL;

    return temp;
}


Patient *add_front(Patient *list, Patient *new) {
    new->next = list;
    return new;
}


Patient *add_end(Patient *list, Patient *new) {
    Patient *curr;

    if (list == NULL) {
        new->next = NULL;
        return new;
    }

    for (curr = list; curr->next != NULL; curr = curr->next);
    curr->next = new;
    new->next = NULL;
    return list;
}


Patient *add_with_priority(Patient *list, Patient *new) {
	

	//if the list is empty or just started then the node passed will become the first node
 	if (list == NULL) {
        new->next = NULL;
        return new;
	
    }


    // Check if the new patient should be the first in the list
    if (new->priority < list->priority) {
        new->next = list;
        return new;
    }

    Patient *curr = list;

    while (curr->next != NULL && new->priority >= curr->next->priority) {

        // Move to the next patient with lower or equal priority

        curr = curr->next;
    }

    // Insert the new patient into the list
    new->next = curr->next;
    curr->next = new;

    return list;

}


Patient *peek_front(Patient *list) {
    return list;
}


Patient *remove_front(Patient *list) {
    if (list == NULL) {
        return NULL;
    }

    return list->next;
}


void apply(Patient *list,
           void (*fn)(Patient *list, void *),
           void *arg)
{
    for ( ; list != NULL; list = list->next) {
        (*fn)(list, arg);
    }
}
