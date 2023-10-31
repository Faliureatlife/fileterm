#include <stdlib.h>
#include <stdio.h>
#define _POSIX_SOURCE
#include <dirent.h>
#include <errno.h>
#include <string.h>
//#include <sys/stat.h>
//#include <sys/types.h>
#undef _POSIX_SOURCE
#include <stdbool.h>

//todo: run by param
//todo: add step in //nvm thats dumb
//todo: choose between hidden files or not
//todo: make a dll if i give a shit
//todo: GITHUB
void p_dir(char *fn, bool hidden){
DIR *dir;
struct dirent *entry;
//checking to see if the dir is actually a dir
if ((dir = opendir(fn)) == NULL && errno != ENOTDIR)
    perror("\t");
//checking if the hidden flag is true; prints out non-hidden files
if (hidden) {
    while ((entry = readdir(dir)) != NULL){
    //print insides
        if (entry->d_name[0] != '.'){
            printf("\n|--%s/%s\n|",fn,entry->d_name);
        }
    }
    return;
}
//only reached if hidden flag is false; prints out with the hidden files
while((entry = readdir(dir)) != NULL){
   if (entry->d_name[0] != '.' || strlen(entry->d_name) > 1)
        printf("\n|--%s/%s\n|",fn,entry->d_name);
    }
}


int main(int argc, char* argv[]) {
    //real num of args
    argc--;
    printf("%d",argc);
    bool hide = false;
    //argv will have the format of {path, {user input}, NULL-TERMINATOR, SHELL_PATH, SESSION_MANAGER, QT_ACCESSIBILITY, COLORTERM, XDG_CONFIG_DIR, SSH_AGENT_LAUNCHER}
	puts("Input desired filename");
	char dirplace[1025];
	fgets(dirplace,1025,stdin); //make this work through fgets when its done being brokey //oh hey look i did
	dirplace[strcspn(dirplace, "\n")] = 0;
	p_dir(dirplace,false);
	puts("");
return EXIT_SUCCESS;
}	
