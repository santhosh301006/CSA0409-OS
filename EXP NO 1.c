#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // Create a new process using fork()
    pid = fork();

    if (pid < 0) {
        // If fork() returns a negative value, creation failed
        perror("fork failed");
        return 1;
    } 
    else if (pid == 0) {
        // Child process block
        printf("Child Process:\n");
        printf("  Child PID: %d\n", getpid());
        printf("  Parent PID: %d\n", getppid());
    } 
    else {
        // Parent process block
        printf("Parent Process:\n");
        printf("  Parent PID: %d\n", getpid());
        printf("  Child PID: %d\n", pid);
    }

    return 0;
}
