// write a c program create child process using fork and child should perform (a+b) and parent should perform (a-b)
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    int a = 10, b = 5;
    pid_t pid;

    pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child Process:\n");
        printf("Addition: %d + %d = %d\n", a, b, a + b);
    } else {
        wait(NULL);
        printf("Parent Process:\n");
        printf("Subtraction: %d - %d = %d\n", a, b, a - b);
    }

    return 0;
}

// output:

// Child Process:
// Addition: 10 + 5 = 15
// Parent Process:
// Subtraction: 10 - 5 = 5
