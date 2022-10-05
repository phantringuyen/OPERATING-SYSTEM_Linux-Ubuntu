
#include "syscall.h"
#include <stdbool.h>    // thu vien xai kieu du lieu bool

int
main()
{
  int c;    // c la lua chon cua nguoi dung
  int arr[100];     // mang arr toi da 100 phan tu
  int n;    // so luong phan tu
  int i, j; // bien i va j phuc vu cho thuat toan bubble sort
  int idx;  // vi tri trong mang arr
  bool haveSwap;    // bien kiem tra swap
  int tmp;      // bien tam de swap

  PrintString("MY BUBBLE SORT\n1. Tang dan\n2. Giam dan\n");
  PrintString("\nNhap lua chon cua ban (1 or 2): ");
  c = ReadNum();

  while ( c < 1 || c > 2)
  {
      PrintString("\nLua chon khong hop le! Vui long nhap lai: ");
      c = ReadNum();
  }  

  if ( c == 1) {
        PrintString("Lua chon: 1 - Tang dan\n");
        PrintString("Nhap so luong phan tu: ");
        n = ReadNum();

        while ( n > 100 || n < 1)
        {
            PrintString("\nSo luong phan tu khong hop le! Vui long nhap lai: ");
            n = ReadNum();
        }

        // INPUT
        for (idx = 0; idx < n; idx++)
        {
            PrintString("arr[");
            PrintNum(idx);
            PrintString("] = ");
            arr[idx] = ReadNum();
        }

        // BUBBLE SORT

        haveSwap = false;
        for (i = 0; i < n-1; i++) {
            haveSwap = false;
            for (j = 0; j < n-i-1; j++){
                if (arr[j] > arr[j+1]) {
                    // swap(arr[j], arr[j+1]);
                    tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                    haveSwap = true; 
                }
            }
       
        if (haveSwap == false){
            break;
        }
    }
  } 

  if ( c == 2) {
        PrintString("Lua chon: 2 - Giam dan\n");
        PrintString("Nhap so luong phan tu: ");
        n = ReadNum();

        while ( n > 100 || n < 1)
        {
            PrintString("\nSo luong phan tu khong hop le! Vui long nhap lai: ");
            n = ReadNum();
        }

        // INPUT
        for (idx = 0; idx < n; idx++)
        {
            PrintString("arr[");
            PrintNum(idx);
            PrintString("] = ");
            arr[idx] = ReadNum();
        }

        // BUBBLE SORT

        haveSwap = false;
        for (i = 0; i < n-1; i++) {
            haveSwap = false;
            for (j = 0; j < n-i-1; j++){
                if (arr[j] < arr[j+1]) {
                    // swap(arr[j], arr[j+1]);
                    tmp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = tmp;
                    haveSwap = true;
                }
            }
        if (haveSwap == false){
            break;
        }
    }
  } 
  
  PrintString("\nMang sau khi sort: ");

  for (idx = 0; idx < n; idx ++) {
      PrintNum(arr[idx]);
      PrintChar(' ');
  }
       
  Halt();

//   Link tham khảo thuật toán bubble sort: https://nguyenvanhieu.vn/thuat-toan-sap-xep-bubble-sort/
}
