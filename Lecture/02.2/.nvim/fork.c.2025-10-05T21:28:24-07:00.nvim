#define _POSIX_C_SOURCE 200809
#include <stdio.h>
#include <unistd.h>

int main() {
  pid_t pid = fork();
  for (int i = 0; i < 10; i++) {
    if (pid != 0)
      printf("Parent sleeping number: %d\n", i);
    else
      printf("Child sleeping number:  %d\n", i);
    sleep(2);
  }
  printf("\nDone\n");
  return 0;
}
