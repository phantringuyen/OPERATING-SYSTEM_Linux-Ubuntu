
#include "syscall.h"

int
main()
{
  char buffer[255];

  int length;

  PrintString("Nhap do dai chuoi: ");
  length = ReadNum();
  while(length <= 0 || length > 255)
  {
    PrintString("Do dai khong hop le! Vui long nhap lai: ");
    length = ReadNum();
  }
  PrintString("Nhap chuoi: ");
  ReadString(buffer, length); 
  PrintString(buffer); 
  Halt();
  /* not reached */
}
