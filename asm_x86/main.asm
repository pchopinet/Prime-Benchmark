; ----------------------------------------------------------------------------------------
; Writes "Hello, World" to the console using only system calls. Runs on 64-bit Linux only.
; To assemble and run:
;
;     nasm -felf64 hello.asm && ld hello.o && ./a.out
; ----------------------------------------------------------------------------------------

section .text
    global    _start


_start:
    mov     eax, 0
    mov     ebx, 0
    mov     ecx, 10000000

loop:

    add     eax, 2
    cmp     eax, ecx
    jc loop

print:
    mov     ecx, eax
    ;add     ecx, 48
    mov     edx, 10
    mov     ebx,1	        ;file descriptor (stdout)
    mov     eax,4	        ;system call number (sys_write)
    int     0x80	        ;call kernel


exit:
    mov     rax, 60         ; system call for exit
    xor     rdi, rdi        ; exit code 0
    syscall                 ; invoke operating system to exit



section .data
    max: dd '1000'