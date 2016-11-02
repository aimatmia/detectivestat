#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <unistd.h>
#include <time.h>

void snooping(char *path){
  struct stat info;
  if ( stat("snoop.c", &info) < 0 )  printf("error: %d - %s \n", errno, strerror(errno));
  printf("Stats for file: %s \n", path);
  if (info.st_size>1000000000) printf("size: %ld GB \n", info.st_size/1000000000);
  if (info.st_size>1000000) printf("size: %ld MB \n", info.st_size/1000000);
  if (info.st_size>1000) printf("size: %ld KB \n", info.st_size/1000);
 else printf("size: %ld B", info.st_size);
     
    //copied from stack overflow
    printf("permissions:     ");
    printf( (S_ISDIR(info.st_mode)) ? "d" : "-");
    printf( (info.st_mode & S_IRUSR) ? "r" : "-");
    printf( (info.st_mode & S_IWUSR) ? "w" : "-");
    printf( (info.st_mode & S_IXUSR) ? "x" : "-");
    printf( (info.st_mode & S_IRGRP) ? "r" : "-");
    printf( (info.st_mode & S_IWGRP) ? "w" : "-");
    printf( (info.st_mode & S_IXGRP) ? "x" : "-");
    printf( (info.st_mode & S_IROTH) ? "r" : "-");
    printf( (info.st_mode & S_IWOTH) ? "w" : "-");
    printf( (info.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");

  time_t tt= info.st_atime;
  char mtime[80];
  time_t t = info.st_mtime; /*st_mtime is type time_t */
  struct tm lt;
  localtime_r(&t, &lt); /* convert to struct tm */
  strftime(mtime, sizeof mtime, "%a, %d %b %Y %T", &lt);
  printf("last time: %s\n", mtime);
}

int main(){ 
  snooping("snoop.c");
  return 0;
}
