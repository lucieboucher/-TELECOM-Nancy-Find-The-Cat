#include "util.h"

struct list_of_files {
    char *name;
    double size;
    long long date;
    int rights;
    struct list_of_files *next;
};

typedef struct list_of_files* list_of_files;

void add_file(list_of_files *list, char *name, double size, long long date,int rights);

void print_list(list_of_files list, bool color);

void free_list(list_of_files list);

void remove_file(list_of_files *list, char *name);

int size_of_list(list_of_files list);

list_of_files copy_list(list_of_files list);

char* get_name(list_of_files list, int index);

double get_size(list_of_files list, int index);

long get_date(list_of_files list, int index);

int get_rights(list_of_files list, int index);

void filename_without_initial_root(list_of_files list, char* initial_root);

void set_name(list_of_files list, int index, char* name);

int rights_to_perm(int rights);





