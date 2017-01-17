// clang process.c; ./a.out
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int debug = 1;
char *progname;

int main(int argc, char *argv[]) {
    int i;
    char *ptr;

    progname = argv[0];
    printf("argc = %d\n", argc);
    for (i = 0; i < argc; i++) {
        ptr = malloc(strlen(argv[i]) + 1);
        strcpy(ptr, argv[i]);
        if (debug) {
            printf("%s\n", ptr);
        }
    }
}
