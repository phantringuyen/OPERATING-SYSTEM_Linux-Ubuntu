#include "syscall.h"

int
main()
{
  int a;
  a = RandomNum();
  PrintNum(a);
  Halt();
  /* not reached */
}
