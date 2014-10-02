#include <stdio.h>

main () { 
  FILE *f = fopen("/tmp/foo", "w");
  fwrite("foo", 4, 1, f);
} 