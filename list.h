#ifndef LIST_H
#define LIST_H

#include "variables.h"

typedef struct snode {
    struct snode *next;
    var *variable;
} node;

void list_add(var *variable);
var *list_search(char *name);
void list_remove();

#endif
