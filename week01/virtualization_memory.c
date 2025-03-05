// Virtualizing Memory

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[])
{
    int *p = malloc(sizeof(int)); // a1
    assert(p != NULL);
    printf("(%d) address pointed to by p: %p\n", getpid(), p); // a2
    *p = 0; // a3

    while (1) {
        usleep(1);
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p); // a4
    }

    return 0;
}

// cc memo.c
// ./a.out

// output:

// (13801) address pointed to by p: 0x600e9a6e22a0
// (13801) p: 1
// (13801) p: 2
// (13801) p: 3
// (13801) p: 4
// (13801) p: 5
// (13801) p: 6
// (13801) p: 7 
