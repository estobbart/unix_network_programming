// clang files.c; ./a.out /dev/tty /dev/sda /usr/lib /etc/passwd

/*
 * Print the type of file for each of the command line arguments.
 */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int i;
    struct stat statbuff;
    char *ptr;

    for (i = 0; i < argc; i++) {
        printf("%s: ", argv[i]);
        if (stat(argv[i], &statbuff) < 0) {
            printf("stat error: %i", errno);
        }
        switch(statbuff.st_mode & S_IFMT) {
            case S_IFDIR:
              ptr = "directory";
              break;
            case S_IFCHR:
              ptr = "character special";
              break;
            case S_IFBLK:
              ptr = "block special";
              break;
            case S_IFREG:
              ptr = "regular";
              break;
            case S_IFLNK:
              ptr = "symbolic link";
              break;
            case S_IFSOCK:
              ptr = "socket";
              break;
            case S_IFIFO:
              ptr = "named pipe (fifo)";
              break;
            case S_IFWHT:
              ptr = "whiteout";
              break;
            default:
              ptr = "** unknown mode **";
              break;
        }
        printf("%s\n", ptr);
    }
    exit(0);
}
