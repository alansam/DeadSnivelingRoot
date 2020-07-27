#include <stdio.h>
#include <ctype.h>

int main(void) {
  int c;
#if defined(_WIN32) || defined(__OS2__) || defined(__vax__)
  char const * ctrl = "CTRL-Z";
#else
  char const * ctrl = "CTRL-D";
#endif
  printf("Note: Use %s to stop.\n", ctrl);
  while ((c = getchar()) != EOF) {
    printf("%3d, %03o, %02x, '%c'\n", c, c, c, (!iscntrl(c) ? c : '.'));
  }
  puts("done!");

  return 0;
}
