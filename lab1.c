#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  char *buff = NULL;
  size_t size = 0;
  ssize_t num_char;

  while (1) {

    printf("Enter a sentence");

    num_char = getline(&buff, &size, stdin);

    // check for error
    if (num_char == -1) {
      perror("getline failed");
      exit(EXIT_FAILURE);
    }

    // part that actually splits the text

    char *saveptr;
    char *ret = strtok_r(buff, " ", &saveptr);

    while (ret != NULL) {
      printf(" %s\n", ret);
      char *ret2 = strtok_r(NULL, " ", &saveptr);
      ret = ret2;
    }
  }

  free(buff);
  return 0;
}
