#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  if (pid == 0) { // In child
    printf("In child\n");
    execlp("ls", "ls", "-a", "-l", "-h", (char *)NULL);
  } else { // In parent
    printf("In parent\n");
    execlp("ls", "ls", "-a", (char *)NULL);
  }

  printf("%d\n", getpid());
  return 0;
}






