#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid) { // In parent
    int wstatus;
    waitpid(pid, &wstatus, 0);

    if (WIFEXITED(wstatus)) {
      printf("Exit reason: %d\n", WEXITSTATUS(wstatus));
    }

    if (WIFSIGNALED(wstatus)) {
      printf("Terminated by signal # %d\n", WTERMSIG(wstatus));
    }
  } else { // In child
    execl("/bin/ls", "ls", "-al", (char *)NULL);
  }

  return 0;
}
