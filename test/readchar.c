
#include "syscall.h"

int
main()
{
  char c;
  
  c = ReadChar();

  Halt();
  /* not reached */
}
