/*
** test.c for lkm-syscall
** 
** Made by xsyann
** Contact <contact@xsyann.com>
** 
** Started on  Sun Mar 16 10:35:54 2014 xsyann
** Last update Fri Mar 28 15:03:35 2014 xsyann
*/

#include <sys/syscall.h>

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define HIJACKED_SYSCALL __NR_tuxcall

int main(int argc, char* argv[])
{
    char *string;

    printf("Call syscall at offset %d\n", HIJACKED_SYSCALL);
    string = argc > 1 ? argv[1] : "Foo";
    printf("Syscall return %ld\n", syscall(HIJACKED_SYSCALL, string));
    return 0;
}
