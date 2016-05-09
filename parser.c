#include <stdio.h>
#include <string.h>

void print_help() {
    printf("Usage: parser <filename>\n");
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
        char *line2;
        while(fgets(line, sizeof(line), f) != NULL) {
            line2 = strdup(line);
            char *command = strtok(line, " ");
            if(strcmp(command, "print") == 0) {
                char *word = strchr(line2, ' ') + 1;
                printf("%s", word);
            }
        }
    } else {
        // file doesn't exist
        print_help();
        return 1;
    }
    
    return 0;
}
