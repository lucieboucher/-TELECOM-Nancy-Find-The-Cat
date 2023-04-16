#include "../includes/date.h"

/*date_converter
Convertir une date en min, heure ou jour en secondes
@param char* date, une date
@return long, la date passée en paramètre en min, jour ou heure convertie en secondes
*/
long date_converter(char *date){
    int sizedate=strlen(date);
    long date_convertie = strtol(date,NULL,10);

        if (date[sizedate-1]=='m'){
            date_convertie=date_convertie*60;
        }
        else if (date[sizedate-1]=='h'){
            date_convertie=date_convertie*60*60;
        }
        else if (date[sizedate-1]=='j'){
            date_convertie=date_convertie*60*60*24;
        }
        return date_convertie;
}


