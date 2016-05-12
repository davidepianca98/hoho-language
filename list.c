#include <stdlib.h>

#include "list.h"
#include "variables.h"

node *start = NULL;

void list_add(var *variable) {
    node *new = (node *) malloc(sizeof(node));
    new->variable = variable;
    new->next = start;
    start = new;
}

var *list_search(char *name) {
    node *search = start;
    while(search != NULL) {
        if(strcmp(search->variable->name, name) == 0) {
            return search->variable;
        }
        search = start->next;
    }
    return NULL;
}

void list_remove() {
    
}
