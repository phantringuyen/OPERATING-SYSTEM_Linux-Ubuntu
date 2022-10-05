
#include "syscall.h"

int
main()
{
    PrintString("Thong Tin Nhom\n1. 20127192 - Tran Anh Huy\n2. 20127578 - Phan Tri Nguyen\n3. 20127590 - Tran Nguyen Phong\n");
    PrintString("\nChuong trinh ASCII\n");
    PrintString("Buoc1: cd vao test \n");
    PrintString("Buoc2: go lenh make \n");
    PrintString("Buoc3: go lenh ../build.linux/nachos -x ascii\n");
    PrintString("Buoc4: Man hinh in ra bang ASCII.\n\n");

    PrintString("Chuong trinh Sort:\n");
    PrintString("Buoc1: cd vao test \n");
    PrintString("Buoc2: go lenh make \n");
    PrintString("Buoc3: go lenh ../build.linux/nachos -x bubblesort\n");
    PrintString("Buoc4: nhap lua chon mang sap xep theo thu tu tang dan hoac giam dan.\n");
    PrintString(" - Nhap 1: tang dan\n");
    PrintString(" - Nhap 2: giam dan\n");
    PrintString("Buoc5: nhap so luong phan tu n cua mang (0<n<101)\n");
    PrintString("  - Luu y: Neu phan tu nhap vao khong phai la so nguyen, thi phan tu do tu dong lay gia tri la 0\n");
    Halt();
}