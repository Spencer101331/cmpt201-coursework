#define _POSIX_C_SOURCE 200809
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define storenum 5

char *alist[storenum];
int len = 0;

void remove_oldest() {
  if (len > 0) {
    free(alist[0]);
    for (int i = 1; i < len; i++) {
      alist[i - 1] = alist[i];
    }
    len--;
  }
}

void update(char *str) {
  if (len >= storenum) {
    remove_oldest();
  }
  alist[len] = str;
  len++;
}

void print_list() {
  for (int i = 0; i < len; i++) {
    printf("%s\n", alist[i]);
  }
}

char *get_input() {
  ssize_t characters = 0;
  char *str = NULL;
  size_t length = 0;

  printf("Enter input: ");
  characters = getline(&str, &length, stdin);
  if (characters > 0 && str[characters - 1] == '\n') {
    str[characters - 1] = '\0';
  }

  if (characters == -1) {
    perror("Get line failed.");
    exit(EXIT_FAILURE);
  }
  return str;
}

int main() {
  char *str = NULL;
  while (1) {
    str = get_input();
    update(str);

    if (strcmp(str, "print") == 0) {
      print_list();
    }
  }
  free(str);
  for (int i = 0; i < len; i++)
    free(alist[i]);
  return 0;
}
