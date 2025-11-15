section .data
    msg db 'Hello, World', 10    ; 'Hello, World' followed by newline (10)
    len equ $ - msg              ; calculate message length

section .text
    global main

main:
    ; write system call
    mov rax, 1                  ; sys_write system call number
    mov rdi, 1                  ; file descriptor (stdout)
    mov rsi, msg                ; pointer to message
    mov rdx, len                ; message length
    syscall                     ; invoke system call

    ; exit system call
    mov rax, 60                 ; sys_exit system call number
    mov rdi, 0                  ; exit status
    syscall                     ; invoke system call
