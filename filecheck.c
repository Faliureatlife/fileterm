#define _POSIX_SOURCE //boilerplate? idk fix it when youre bored of compile messages
#include <dirent.h>
#include <errno.h>
#include <string.h>
//#include <sys/stat.h>
//#include <sys/types.h>
#undef _POSIX_SOURCE
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
//#include <printfile.h> //a-hehe a-haha

//todone: GITHUB
//todont: add step in //nvm thats dumb
//todone: choose between hidden files or not
//todo: run by param
//todo: make a dll if i give a shit
//todo: add everything to headers

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
            printf("\n|--%s%s\n|",fn,entry->d_name);
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
    bool hide = false;
//  printf("%s", argv[1]); //print out arg (make it print out all)
    if (argc > 0 && (strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"--help") == 0)) printf("Format:  filecheck [args]\n -h      -- print this text\n -hidden -- hide all files prefixed with a '.'\n");
    //argv will have the format of {path, {user input}, NULL-TERMINATOR, SHELL_PATH, SESSION_MANAGER, QT_ACCESSIBILITY, COLORTERM, XDG_CONFIG_DIR, SSH_AGENT_LAUNCHER}
	puts("Input desired filename");
	char dirplace[1025];
	fgets(dirplace,1025,stdin); //make this work through fgets when its done being brokey //oh hey look i did
	dirplace[strcspn(dirplace, "\n")] = 0;
	p_dir(dirplace,false);
	printf("\b \b"); //do a delete the last character
return EXIT_SUCCESS;
}	
