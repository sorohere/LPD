//  Virtualizing The CPU

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <assert.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }

    char *str = argv[1];

    while (1) {
        usleep(1);
        printf("%s\n", str);
    }

    return 0;
}

// cc cpu.c
// ./a.out "A" & ./a.out "B" & ./a.out "C" &

// or 

// gcc -o cpu cpu.c -Wall
// ./cpu A & ./cpu B & ./cpu C & ./cpu D &

// output: 

// [1] 12901
// [2] 12902
// [3] 12903
// A
// B
// C
// A
// C
// B
// A
// B
// C
// B
// C
// A
