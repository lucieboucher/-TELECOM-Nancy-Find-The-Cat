#include "../includes/size.h"

/*size_converter
Convertir une taille en k,M ou G en octet
@param char* taille, une taille
@return long, la taille passée en paramètre en k, M ou G convertie en octet
*/
long size_converter(char *taille){
    int longueur = strlen(taille);
    long taille_convertie = strtol(taille,NULL,10);
    if(taille[longueur-1] == 'k' || taille[longueur-1] == 'M' || taille[longueur-1] == 'G'){
        if (taille[longueur-1] == 'k')
        {
            taille_convertie = taille_convertie*1024;
        }
        else if (taille[longueur-1] == 'M')
        {
            taille_convertie = taille_convertie*1048576;
        }
        else{
            taille_convertie = taille_convertie*1073741824;
        }
        
    }
    return taille_convertie;
}

/*check_size
Vérifie si la taille du fichier correspond à la taille passée en paramètre
@param char* taille, une taille
@param char* root, le chemin du fichier
@return bool, true si la taille du fichier correspond à la taille passée en paramètre, false sinon
*/
bool check_size(char* taille, char* root){
    bool is_size = false;
    struct stat st;
    stat(root, &st);
    long taille_convertie = size_converter(taille);
    if(taille[0]=='+' || taille[0]=='-'){
        if(taille[0]=='+'){
            if(st.st_size>taille_convertie){
                is_size = true;
            }
        }
        else if(taille[0]=='-'){
            long taille_fichier_courant = st.st_size;
            int critere= -taille_convertie-taille_fichier_courant;
            if(critere>0){
                is_size = true;
            }
        }
    }    
    else{
        if(taille_convertie==st.st_size){
            is_size = true;
        }
    }
    return is_size;
}

