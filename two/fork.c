// clang fork.c; ./a.out

#include <unistd.h> // fork, getpid, getppid
#include <stdlib.h> // exit
#include <stdio.h> // printf, perror
#include <sys/wait.h> // waitpid

int main(int argc, char *argv[]) {
    int childpid;
    if ((childpid = fork()) == -1) {
        perror("can't fork");
        exit(1);
    } else if (childpid == 0) {
        /* child process */
        printf("child: current pid = %d, parent pid = %d\n", getpid(), getppid());
        exit(0);
    } else {
        /* parent process */
        printf("parent: child pid = %d, current pid = %d\n", childpid, getpid());
        // parent will exit before child prints
        waitpid(childpid, NULL, 0);
        exit(0);
    }
}
