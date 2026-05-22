#include <stdio.h>

int main(int argc, const char* argv[], const char* envp[]) {
  int i;

  while (envp[i]<argc) {
    printf("%s\n", envp[i]);
    i++;
  }

 return 0;
}
