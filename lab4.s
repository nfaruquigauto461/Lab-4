.global sum_array
.text


sum_array:
    xorq    %rax, %rax      # sum = 0
    xorq    %rcx, %rcx      # i = 0

.L_loop:
    cmpq    %rsi, %rcx      # compares i to the count
    jge     .L_done         # exits loop if i >= N

    movslq  (%rdi, %rcx, 4), %rdx
    addq    %rdx, %rax      

    incq    %rcx            # i++
    jmp     .L_loop

.L_done:
    ret

.section .note.GNU-stack,"",@progbits
