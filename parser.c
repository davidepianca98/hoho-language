#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"
#include "variables.h"

void print_help() {
    printf("Usage: parser <filename>\n");
}

void savevar(char *line) {
    var *variable = (var *) malloc(sizeof(var));
    char *name = strchr(line, ' ') + 1;
    // remove the \n at the end from fgets
    name[strcspn(name, "\n")] = 0;
    strcpy(variable->name, name);
    list_add(variable);
}

void variable_op(var *variable, char *line) {
    // check if it's an assignment
    if(strncmp(strchr(line, '='), "=", 1) == 0) {
        variable->integer = atoi(strchr(line, '=') + 2);
    }
}

void print(char *line) {
    char *word = strchr(line, ' ') + 1;
    var *vari = list_search(word);
    if(vari) {
        // variable with that name exists, just print the value
        printf("%d", vari->integer);
    } else {
        printf("%s", word);
    }
}

void command(char *line) {
    char *line2;
    line2 = strdup(line);
    char *command = strtok(line, " ");
    
    if(strcmp(command, "print") == 0) {
        print(line2);
    } else if(strcmp(command, "var") == 0) {
        savevar(line2);
    } else {
        // no command found, maybe it's a variable operation
        var *vari = list_search(command);
        if(vari) {
            variable_op(vari, line2);
        }
    }
}

int main(int argc, char **argv) {
    
    if(argc < 2) {
        print_help();
        return 1;
    }
    
    FILE *f = fopen(argv[1], "r");
    if(f) {
        // file exists, start parsing
        char line[100];
        while(fgets(line, sizeof(line), f) != NULL) {
            command(line);
        }
    } else {
        // file doesn't exist
        print_help();
        return 1;
    }
    
    return 0;
}
