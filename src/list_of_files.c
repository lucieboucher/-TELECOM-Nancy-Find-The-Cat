#include "../includes/list_of_files.h"
#define couleur(param) printf("\033[%sm",param)

void add_file(list_of_files *list, char *name, double size,long long date,int rights) {
    list_of_files new_file = malloc(sizeof(struct list_of_files));
    new_file->name = name;
    new_file->size = size;
    new_file->date=date;
    new_file->rights=rights;
    new_file->next = *list;
    *list = new_file;
}

void print_list(list_of_files list, bool color) {
    char* path;
    char* filename;
    while (list != NULL) {
        filename = filename_with_path(list->name);
        path = path_without_filename(list->name);
        if(color){
            printf("%s/", path);
            couleur("32");
            printf("%s\n", filename);
            couleur("0");
        }else{
            printf("%s/%s\n", path, filename);
        }
        list = list->next;
    }
}

void free_list(list_of_files list) {
    while (list != NULL) {
        list_of_files next = list->next;
        free(list->name);
        free(list);
        list = next;
    }
}

void remove_file(list_of_files *list, char *name) {
    list_of_files prev = NULL;
    list_of_files current = *list;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (prev == NULL) {
                *list = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int size_of_list(list_of_files list) {
    int size = 0;
    while (list != NULL) {
        size++;
        list = list->next;
    }
    return size;
}

list_of_files copy_list(list_of_files list) {
    list_of_files new_list = NULL;
    while (list != NULL) {
        add_file(&new_list, list->name, list->size, list->date,list->rights);
        list = list->next;
    }
    free_list(list);
    list = new_list;
    return new_list;
}

char* get_name(list_of_files list, int index) {
    int i = 0;
    while (list != NULL) {
        if (i == index) {
            char* name = list->name;
            //free_list(list);
            return name;
        }
        i++;
        list = list->next;
    }
    return NULL;
}

double get_size(list_of_files list, int index) {
    int i = 0;
    while (list != NULL) {
        if (i == index) {
            double size = list->size;
            //free_list(list);
            return size;
        }
        i++;
        list = list->next;
    }
    return -1;
}

long get_date(list_of_files list, int index){
    int i=0;
    while (list !=NULL)
    {
        if(i==index){
            long date=list->date;
            //free_list(list);
            return date;
        }
        i++;
        list=list->next;
    }
    return -1;
}


void set_name(list_of_files list, int index, char* name) {
    int i = 0;
    while (list != NULL) {
        if (i == index) {
            list->name = name;
            return;
        }
        i++;
        list = list->next;
    }
}

int get_rights(list_of_files list, int index){
    int i=0;
    while (list !=NULL)
    {
        if(i==index){
            int rights = list->rights;
            return rights;
        }
        i++;
        list=list->next;
    }
    return -1;
}

int rights_to_perm(int rights){
    int octal_rights = decimal_octal(rights);
    int droit= octal_rights/1000;
    droit *=1000;
    droit= octal_rights-droit;
    return droit; 
}



