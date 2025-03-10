#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid()); /* printf() function is defined in stdio.h
                                                         getpid() function is defined in unistd.h 
                                                            */
    
    int rc = fork();  /*fork() function is defined in unistd.h*/
    
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n"); /* stderr is defined in stdio.h */
        exit(1); /* exit() is define in stdio.h */
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d)\n", (int) getpid());
    } else {
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());
    }
    
    return 0;
}
