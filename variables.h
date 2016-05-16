#ifndef VARIABLES_H
#define VARIABLES_H

// max string length
#define MAX_STRING 256

typedef struct {
    int type; // indicates which type the variable is
    char name[MAX_STRING];
    int integer;
    float floating;
    char string[MAX_STRING];
} var;

#endif
