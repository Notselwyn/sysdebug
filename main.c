#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/syscall.h>

int main(int argc, char** argv) 
{
    if (argc < 2) {
        printf("Usage: %s <syscall number> <args...>\n", argv[0]);
        return 1;
    }

    for (int i=1; i < argc; i++) {
        if (argv[i][0] != '"' && argv[i][0] != '\'') {
            argv[i] = atoi(argv[i]);
        } else {
            // cut off " and '
            argv[i] = argv[i]+1;
            argv[i][strlen(argv[i])-1] = '\x00';
        }
    }

    if (getenv("SYSDEBUG_DEBUG"))
    {
        printf("argc: %d\n", argc);
        printf("%s|", argv[0]);
        for (int x=1; x < argc; x++)
            printf("%d|", argv[x]);
        puts("");
    }

    // miracously this does not raise any errors and syscalls gracefully accept invalid rest arguments
    unsigned long result = syscall(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7]);
    printf("0x%lx\n", result);
    return 0;
}