#include "../includes/ftc.h"


/*Question 1 : parser
Affiche les options passées en ligne de commande avec leurs paramètres
@param int argc la taille de la ligne de commande
@param char* argv le contenue de la ligne de commande
@return void
*/
int parser(int argc, char* argv[], option* options, bool* is_test){
    int cmp=0;
    int j = 0;
    bool pri = false;
    for (int i = 2; i < argc; i = i+1 ){
        if ( strcmp(argv[i], "-test") == 0 ) {
            pri = true;
            *is_test = true;
        }
    }
    for (int i = 2; i < argc; i = i+2 ){
        if ( strcmp(argv[i], "-test") == 0 ) {
            i=i-1;
        } 
        else 
        if ( strcmp(argv[i], "-color") == 0 ) {
            if(pri)
                printf("La valeur du flag -color est NULL\n");
            options[j].option = argv[i];
            i=i-1;
            j++;
            cmp++;
        }
        else 
        if ( strcmp(argv[i], "-ou") == 0 ) {
            if(pri)
                printf("La valeur du flag -ou est NULL\n");
            options[j].option = argv[i];
            i=i-1;
            j++;
            cmp++;
        }
        else
        if ( strcmp(argv[i], "-name") == 0 ) {
            if(pri)
                printf("La valeur du flag -name est %s\n", argv[i+1]);
            options[j].option = argv[i];
            options[j].param = argv[i+1];
            j++;
            cmp++;
        }
        else
        if ( strcmp(argv[i], "-type") == 0 ) {
            if(pri)
                printf("La valeur du flag -type est %s\n", argv[i+1]);
            options[j].option = argv[i];
            options[j].param = argv[i+1];
            j++;
            cmp++;
        }
        else 
        if ( strcmp(argv[i], "-size") == 0 ) {
            if(pri)
                printf("La valeur du flag -size est %s\n", argv[i+1]);
            options[j].option = argv[i];
            options[j].param = argv[i+1];
            j++;

            cmp++;
        } 
        else 
        if ( strcmp(argv[i], "-date") == 0 ) {
            if(pri)
                printf("La valeur du flag -date est %s\n", argv[i+1]);
            options[j].option = argv[i];
            options[j].param = argv[i+1];
            j++;
            cmp++;
        } 
        else 
        if ( strcmp(argv[i], "-mime") == 0 ) {
            if(pri)
                printf("La valeur du flag -mime est %s\n", argv[i+1]);
            options[j].option = argv[i];
            options[j].param = argv[i+1];
            j++;
            cmp++;
        } 
        else 
        if ( strcmp(argv[i], "-ctc") == 0 ) {
            if(pri)
                printf("La valeur du flag -ctc est %s\n", argv[i+1]);
            options[j].option = argv[i];
            options[j].param = argv[i+1];
            j++;
            cmp++;
        } 
        else 
        if ( strcmp(argv[i], "-dir" ) == 0 ) {
            if(pri)
                printf("La valeur du flag -dir est %s\n", argv[i+1]);
            options[j].option = argv[i];
            options[j].param = argv[i+1];
            j++;
            cmp++;
        } 
        else
        if ( strcmp(argv[i], "-perm") == 0 ) {
            if(pri)
                printf("La valeur du flag -perm est %s\n", argv[i+1]);
            options[j].option = argv[i];
            options[j].param = argv[i+1];
            j++;
            cmp++;
        }
        else
        if ( strcmp(argv[i], "-threads") == 0 ) {
            if(pri)
                printf("La valeur du flag -threads est %s\n", argv[i+1]);
            options[j].option = argv[i];
            options[j].param = argv[i+1];
            j++;
            cmp++;
        }
        else
        if ( strcmp(argv[i], "-link") == 0 ) {
            if(pri)
                printf("La valeur du flag -link est %s\n", argv[i+1]);
            options[j].option = argv[i];
            options[j].param = argv[i+1];
            j++;
            cmp++;
        }
        else
        if ( strcmp(argv[i], "-w") == 0 ) {
            if(pri)
                printf("La valeur du flag -w est %s\n", argv[i+1]);
            options[j].option = argv[i];
            options[j].param = argv[i+1];
            j++;
            cmp++;
        }
        else {    
            printf("Le flag %s n'est pas correct\n", argv[i]);
            exit(1);            
        }
    }
    return cmp;
}

/*Question 2 : browser
Affiche tous les fichiers à partir de la racine passer en ligne de commande
@param char* root, la racine à partir de laquelle on feuillete les repertoires et fichiers
@return void
*/
void browser(char *root, list_of_files* list){
    //if it's the fist time we call browser, we need to fill the list with the root
    if(size_of_list(*list) == 0){
        struct stat st0 = {0};
        lstat(root, &st0);
        long long date_fichier0=st0.st_mtim.tv_sec;
        long long size = st0.st_size;
        int rights = st0.st_mode;
        char *newroot2 = malloc(strlen(root)*2);
        strcpy(newroot2, root);
        add_file(list, newroot2, size,date_fichier0,rights);
    }
    DIR *dir;
    struct dirent *ent;
    int len = strlen(root);
    if(root[len-1] == '/'){
        root[len - 1] = '\0';
    }
    
    if ((dir = opendir (root)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            //ent->d_name est le nom du fichier
            if(strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0){
                char *newroot = malloc(strlen(root)+strlen(ent->d_name)+2);
                strcpy(newroot, root);
                strcat(newroot, "/");
                strcat(newroot, ent->d_name);
                struct stat st = {0};
                lstat(newroot, &st);
                long long size = st.st_size;
                long long date_fichier=st.st_mtim.tv_sec; 
                int rigths = st.st_mode;
                //test if newroot is a file or a directory
                if(!S_ISDIR(st.st_mode)){
                    add_file(list, newroot, size,date_fichier,rigths);
                }
                else{
                    add_file(list, newroot, size,date_fichier,rigths);
                }
                browser(newroot, list);
                //free(newroot);
            }
        }
        closedir (dir);
    }
}


/*is_color
* return true si l'option -color est presente
* @param option* options, la liste des options
* @param int nb_options, le nombre d'options
* @return bool
*/
bool is_color(option* options, int nb_options){
    for(int i=0;i<nb_options;i++){
        if(strcmp(options[i].option, "-color") == 0){
            return true;
        }
    }
    return false;
}


void searcher(option* options, list_of_files list, int cmp){
    bool dossier = false;
    list_of_files new_list = copy_list(list);
    for(int i=0; i<size_of_list(list); i++){
        for(int j=0; j<cmp; j++){
            if(strcmp(options[j].option, "-name")==0){

                check_name(options[j].param, &new_list, get_name(list,i));
            }
            else if(strcmp(options[j].option, "-ctc")==0){
                if(!catch_the_cat(options[j].param, get_name(list,i))){
                    remove_file(&new_list, get_name(list,i));
                }
            }
            else if (strcmp(options[j].option, "-size")==0){
                if(!check_size(options[j].param, get_name(list,i))){
                    remove_file(&new_list, get_name(list,i));
                }
            }else if (strcmp(options[j].option, "-date")==0){
                //recupération date actuelle
                time_t datejour;
                time(&datejour);
                //conversion de la date passée en paramètre en secondes
                long optiondate= date_converter(options[j].param);
                //verification si premier caractère est un plus
                if(options[j].param[0]=='+'){
                    if(datejour - get_date(list,i)<optiondate){
                        remove_file(&new_list, get_name(list,i));
                    }
                }
                else {
                        if(datejour- get_date(list,i)>=optiondate){
                            remove_file(&new_list, get_name(list,i));
                        }
                    }
                
            }else if(strcmp(options[j].option, "-mime")==0){
                //ici on récupère le type mime voulu
                char* mime_type = options[j].param ;
                // on regarde si le mime type possède un sous type en plus du type
                bool is_Type = isType(mime_type) ;
                // récupération de l'extension du fichier courant
                char* extension_file = extension_without_path(get_name(list,i));
                // à l'aide l'extension on récupère son mime type + sous type associé
                char* mime_file = get_mimetype(extension_file);
                
                if(strcmp(mime_file,mime_type)!=0 && !is_Type){ 
                    //si le paramètre est de la forme type/sous type et qu'il y a pas 
                    //correspondance avec le type du fichier alors on supprime le fichier courant
                    remove_file(&new_list, get_name(list,i));
                }

                else if(strstr(mime_file,mime_type)==NULL && is_Type){
                    // si le paramètre est juste un type on regarde si
                    // le type/soustype du fichier courant contient le type recherché
                    remove_file(&new_list, get_name(list,i));
                }
                
            }
            else if(strcmp(options[j].option,"-perm")==0){
                // récupération des droits du fichier courant
                int rights = get_rights(list,i);
                // extraction des permissions = trois derniers octets des droits
                int perm = rights_to_perm(rights);
                char str[10]="";
                //transformation de l'entier en string avec minimum 3 caractères et complétion
                // du string par des 0 si l'entier fait moins de 3 caractères
                sprintf(str,"%03d",perm);
                //
                int egal =strcmp(str,options[j].param);
                if(egal!=0){
                    remove_file(&new_list, get_name(list,i));
                }
            }
            else if (strcmp(options[j].option, "-dir")==0){
                dossier = true;
                check_name(options[j].param, &new_list, get_name(list,i));
            }
        }
        
    }
    if(cmp!=0){
        for(int i= 0; i<size_of_list(new_list); i++){
            if(!dossier){
                struct stat st0 = {0};
                lstat(get_name(new_list, i), &st0);
                
                if(S_ISDIR(st0.st_mode)){
                    remove_file(&new_list, get_name(new_list, i));
                    i=i-1;
                }

            }
            else{
                struct stat st0 = {0};
                lstat(get_name(new_list, i), &st0);
                
                if(!S_ISDIR(st0.st_mode)){
                    remove_file(&new_list, get_name(new_list, i));
                    i=i-1;
                }
            }
        }
    }
    print_list(new_list, is_color(options, cmp));
    free_list(new_list);

}




int main(int argc, char* argv[]){
    //on verifie que le nombre d'arguments est correct
    if(argc<2){
        printf("Erreur : pas assez d'arguments \n");
        exit(1);
    }

    option* options = malloc(sizeof(option)*argc);
    bool is_test = false;
    // question 1
    int cmp = parser(argc, argv, options, &is_test);
    if(!is_test){
        // On récupère le chemin du répertoire passer en paramètre
        char* root = argv[1];
        list_of_files list = NULL;
        browser(root, &(list));
        searcher(options, list, cmp);
    }
    free(options);
    return 0;
}
