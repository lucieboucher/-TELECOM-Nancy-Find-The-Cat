#include "../includes/name.h"

void check_name(char* name, list_of_files *new_list, char* target_name){
    regex_t reg;
    int reti;

    reti = regcomp(&reg, name, REG_EXTENDED);

    if(reti){
        printf("Erreur de compilation de l'expression régulière \n");
        exit(1);
    }
    reti = regexec(&reg, filename_with_path(target_name), 0, NULL, 0);
    if(reti){
        remove_file(new_list, target_name);
    }
    regfree(&reg);
}