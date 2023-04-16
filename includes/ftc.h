#include "date.h"

#define num_of_args_max 10
#define num_of_args_min 2

typedef struct option
{
    char* option;
    char* param;
} option;


int parser(int argc, char* argv[], option* options, bool* is_test);

void browser(char *root, list_of_files* list);

char* filename_with_path(char* path);

void searcher(option* options, list_of_files list, int cmp);

