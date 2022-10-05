/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"



void SysHalt()
{
  kernel->interrupt->Halt();
}


int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysSub(int op1, int op2)
{
  return op1 - op2;
}

char SysReadChar()
{
  return kernel->synchConsoleIn->GetChar();
}

void SysPrintChar(char character)
{
  kernel->synchConsoleOut->PutChar(character);
}

int SysRandomNum()
{
  return random();
}

int SysReadNum()
{
  // đọc chuỗi rồi chuyển sang số, sau đó kiểm tra
  char c;
  char buffer[255];
  int i = 0;
  
  do
  {
    c = kernel->synchConsoleIn->GetChar();
    buffer[i++] = c;
  } while(c != ' ' && c != '\n' && c != '\0'); // c != 7 8 9
  i--;

  if (i > 11)
    return 0;

  for(int j = 0; j < 11; j++)
  {
    if (j == 10 && buffer[j] == '8') {
      // cerr << "ok\n";
      return -2147483648;
    }
    if (buffer[j] != "-2147483648"[j]) 
      break;
  }

  if (i == 10 &&  buffer[0] != '-')
  {
    for(int j = 0; j < 10; j++)
      if(buffer[j] > "2147483647"[j]) {
        // cerr << "The number is larger than max int in C\n";
        return 0;
      }
  }

  else if (i == 11)
  {
    if (buffer[0] != '-') 
      return 0;
    else
    {
      for(int j = 0; j < 10; j++) {
        if (buffer[j + 1] > "2147483648"[j])
          return 0;
      }
    }
  }
  int number = 0;
  for(int j = 0; j < i; j++)
  {
    if (buffer[j] < '0' || buffer[j] > '9')
    {
      if(j == 0 && buffer[j] == '-') continue;
      cerr << "Invalid number\n";
      return 0;
    }
    else 
      number = number * 10 + (buffer[j] - '0');
  }
  if (buffer[0] == '-') number = -number;
  return number;
}

void SysPrintNum(int number)
{
  char buffer[255];
  int n = 0;
  int tmp = number;

  if (tmp == -2147483648)
  {
    for(int j = 0; j < 11; j++)
    {
      kernel->synchConsoleOut->PutChar("-2147483648"[j]);
    }
    return;
  }

  if (tmp == 0){
    kernel->synchConsoleOut->PutChar('0');
    return;
  }

  if (tmp < 0) {
    kernel->synchConsoleOut->PutChar('-');
    tmp = abs(tmp);
  }

  while( tmp != 0)
  {
    buffer[n++] = (tmp % 10) + '0';
    tmp /= 10;
  }
  n--;

  for(int i = n; i >= 0 ; i--)
  {
    if(buffer[i] == '-') break;
    kernel->synchConsoleOut->PutChar(buffer[i]);
  }
}

void SysReadString (char buffer[], int length)
{
  if (length > 255 || length < 0) return;
  for (int i = 0; i < length; i++)
  {
    buffer[i] = kernel->synchConsoleIn->GetChar();
  }
  buffer[length] = '\0';
}

void SysPrintString (char buffer[])
{
  int length = strlen(buffer);
  for (int i = 0; i < length; i++)
  {
    kernel->synchConsoleOut->PutChar(buffer[i]);
  }
}
#endif /* ! __USERPROG_KSYSCALL_H__ */
