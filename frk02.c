// write a c program to create child process using fork and perform fuction such that, parent should perform read operation from a test file and child should perform write operation on the same file.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    int fd;
    char readBuffer[100];
    const char *writeText = "Hello from child process!\n";

    fd = open("testfile.txt", O_RDWR | O_CREAT, 0666);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    pid = fork();

    if (pid == -1) {
        perror("Fork failed");
        close(fd);
        return 1;
    } else if (pid == 0) {
        lseek(fd, 0, SEEK_END);
        write(fd, writeText, strlen(writeText));
        printf("Child Process: Written to file\n");
    } else {
        wait(NULL);
        lseek(fd, 0, SEEK_SET);
        read(fd, readBuffer, sizeof(readBuffer) - 1);
        readBuffer[sizeof(readBuffer) - 1] = '\0';
        printf("Parent Process: Read from file: %s\n", readBuffer);
    }

    close(fd);
    return 0;
}
