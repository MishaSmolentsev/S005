// S005.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    char strf[256]; //вводимая строка
    char Findstr[256];
    char f[] = "%s";//формат строки
    char fd[] = "%d";//формат числа
    cout << "string: ";
    char m[514] = "Search string ";//
    __asm
    {
        lea ebx, strf

        push ebx

        lea ecx, f

        push ecx

        call scanf

        add esp, 8

        lea edx, m

        push edx

        lea ecx, f

        push ecx

        call printf

        add esp, 8

        lea edx, Findstr

        push edx

        lea ecx, f

        push ecx

        call scanf

        add esp, 8

        lea ebx, strf

        dec ebx

        lea ecx, Findstr

        b1 :
        inc ebx

            mov al, [ebx]
            cmp al, 0
            je b5
            cmp al, [ecx]
            jnz b1
            mov edx, ebx

            b2 :
        inc ebx
            inc ecx
            mov al, [ebx]
            cmp al, 0
            je b4
            mov al, [ecx]
            cmp al, 0
            je b7
            cmp al, [ebx]
            je b2
            mov ebx, edx
            lea ecx, Findstr
            jmp b1

            b4 :
        mov al, [ecx]
            cmp al, 0
            jne b5

            b7 :
        lea ebx, strf
            sub edx, ebx
            push edx
            jmp b6

            b5 :
        mov ebx, -1
            push ebx

            b6 :
        lea ebx, fd
            push ebx
            call printf
            add esp, 8
    }
}