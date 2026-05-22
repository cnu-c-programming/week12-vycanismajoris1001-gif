#include <stdio.h>

int main(int argc, const char* argv[], const char* envp[]) {
  int i = 0;
  int* j = &argc;

  while (envp[i]<j) {
    printf("%s\n", envp[i]);
    i++;
  }

 return 0;
}
