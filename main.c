#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/syscall.h>

int main(int argc, char** argv) 
{
    if (argc < 2) {
        printf("Usage: %s <syscall number> <args...>\n", argv[0]);
        return 1;
    }

    // parse arguments
    for (int i=1; i < argc; i++) {
        char is_int = 1;
        int convi = atoi(argv[i]);
        
        // check if the entire string contains non-int chars
        for (int j=0; argv[i][j] != '\x00'; j++) {
            char chr = argv[i][j];
            if (!(chr >= 48 && chr <= 57))
            {
                is_int = 0;
                break;
            }
        }

        // 0x0 is edge case
        if (convi != 0 || is_int == 1) {
            argv[i] = atoi(argv[i]);
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
    unsigned long result = syscall(argv[1], argv[2], argv[3], argv[4], argv[5], argv[6], argv[7], argv[8]);
    printf("0x%lx\n", result);
    return 0;
}