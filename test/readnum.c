
#include "syscall.h"

int
main()
{
  int res;
  res = ReadNum();

  PrintNum(res);
  Halt();
  /* not reached */
}
