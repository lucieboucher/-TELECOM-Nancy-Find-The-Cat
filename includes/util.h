#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <assert.h>
#include <regex.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>

enum{

 EXTENSION_POS  ,
 MIMENAME_POS ,
 MIMETYPE_POS ,
 MAGICNUMBER_POS , 
 COMPONENTS_NUMBER ,
 
}  ;


#ifdef __unix__
  #define FILE_PATH_SEP '/'
#else 
  #define FILE_PATH_SEP '\\'
#endif 
#ifdef _WIN32 
	#define THREAD_LOCAL __declspec(thread)
#else
	#define THREAD_LOCAL _Thread_local 
#endif 

#define MAX_LINE_SIZE 256 

extern const char* MegaMimeTypes[][COMPONENTS_NUMBER] ;
 

char* filename_with_path(char* path);
char* path_without_filename(char* path);

char* extension_without_path(char* path);
char* get_mimetype(char* extension_file);
bool isType(char* mimetype);
char* type_without_soustype(char* mimetype);
int decimal_octal (int n);
