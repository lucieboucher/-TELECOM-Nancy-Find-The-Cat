#include "../includes/ctc.h"

/*catch_the_cat 
*return true if the name n is in the file root
handle if name is a regexp*/

bool catch_the_cat(char* name, char* root){
    FILE* file = fopen(root, "r");
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    bool found = false;
    regex_t reg;
    int reti;
    while ((read = getline(&line, &len, file)) != -1) {
        reti = regcomp(&reg, name, REG_EXTENDED);
        if(reti){
            printf("Erreur de compilation de l'expression régulière \n");
            exit(1);
        }
        reti = regexec(&reg, line, 0, NULL, 0);
        if(!reti){
            found = true;
        }
    }
    fclose(file);
    if (line)
        free(line);
    return found;
}