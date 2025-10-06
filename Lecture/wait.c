#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid != 0) {
    int state = 0;
    pid_t t = waitpid(pid, &state, 0);
    if (t == -1) {
      perror("waitpid");
      exit(EXIT_FAILURE);
    }
    if (WIFEXITED(state)) {
      printf("Child exist with exit status: %d\n", WEXITSTATUS(state));
    } else {
      printf("Child did not exist normally.\n");
    }
  } else {
    *(volatile int *)NULL;
    if (execl("/usr/bin/ls", "/usr/bin/ls", "-al", NULL) == -1) {
      perror("execl");
      exit(EXIT_FAILURE);
    }
  }
}
