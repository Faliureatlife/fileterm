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
#include <stdint.h>
const uint16_t MAX_DIR_SIZE = 1024;

//#include <printfile.h> //a-hehe a-haha
//todone: GITHUB
//todont: add step in //nvm thats dumb
//todone: choose between hidden files or not
//todo: run by param
//todo: make a dll (for testing)
//todo: add everything to headers
//todo: deprecate p_dir
//todo: more memory-efficient way of doing dircont w/ larger capacity
//todo: make print function for 'logged' data
//todo: make global "me" include of helper funcs (swap, foreach, own boolean implementation?, etc.)
//todo: make not crash on no input;
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

void logdir(char** log, char* fn) {
DIR *dir; //pointer to the current dir
struct dirent *entry; //struct containing info about the current entry 
uint16_t i = 0; //iterator for l8r
if ((dir = opendir(fn)) == NULL && errno != ENOTDIR)//check to see if its a valid dir
    perror("/t"); //print error out with tab
while((entry = readdir(dir)) != NULL && i < MAX_DIR_SIZE){ //set entry to subsequent entrys in the dir and as long as tbey are not null, continue 
    log[i] = entry->d_name; //adding the name to the log
    i++; //iterate place in log[]
}
}

void printDirLog(char** elem, char* path){ //check to see if sizeof() works to find jt
int file = 0;
while(elem[file+1] != NULL && file < MAX_DIR_SIZE){
    printf("\n|--%s/%s",path, elem[file]);
    file++;
  }
}

void printUnhiddenDirLog(char** elem, char* path){
int file = 0;
while(elem[file+1] != NULL && file < MAX_DIR_SIZE){
    if (elem[file][0] != '.')
    printf("\n|--%s/%s",path, elem[file]);
    file++;
  }
}

void printShortDirLog(char ** elem){
int file = 0;
while(elem[file+1] != NULL && file < MAX_DIR_SIZE){
    printf("\n|--%s",elem[file]);
    file++;
  }  
}

void printBooledDirLog(char** elem, char* path, bool h, bool s){
  int file = 0;
  while(elem[file+1] != NULL && file < MAX_DIR_SIZE){
    if (h && elem[file][0] != '.')
    {
      if(s) {printf("\n|-%s",elem[file]);}
      else printf("\n|-%s/%s",path,elem[file]);
    }
  }
}

int main(int argc, char* argv[]) {
    //real num of args
    //toggle behaviors
  bool hidden = false;
  bool shortened = false;
    if (argc == 1) {puts("No input given; exiting program"); return EXIT_FAILURE;} //if no input then quit
  char* dircont[MAX_DIR_SIZE]; //noninit array of max allowable size
  //argc--;
  char dirplace[1025];
  puts("what");
        //strcpy(dirplace,argv[argn +1]);
        //logdir(dircont,dirplace);
        //printShortDirLog(dircont);
  for (int argn = 1; argn < argc; argn++){
  printf("\n%i\n",argc);
    if (argc == 1) {
      printf("No input given");
      return EXIT_FAILURE;
    } 
    if((strcmp(argv[argn],"-h") == 0) || (strcmp(argv[argn],"--hidden") == 0)){
      printf("Format:  filecheck [args]\n -h      -- print this text\n -hidden -- hide all files prefixed with a '.'\n\n");
    }
    if (strcmp(argv[argn],"-s") == 0) 
      shortened = !shortened;
    
    if (strcmp(argv[argn],"--hidden") == 0)
      hidden = !hidden;
  }
  strcpy(dirplace, argv[argc+1]);
  logdir(dircont,dirplace);
  printBooledDirLog(dircont,dirplace,hidden,shortened);
  puts("");
return EXIT_SUCCESS;
}
