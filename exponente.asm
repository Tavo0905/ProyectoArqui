%include "io.mac"

global exponente

.CODE
    exponente:
        push        ebp
        mov         ebp, esp
        push        ebx
        mov         ebx, [ebp + 8]
        mov         ecx, [ebp + 12]
        mov         eax, 1
        cmp         ecx, 0
        je          fin
        jl          error
    ciclo1:
        mul         ebx
        loop        ciclo1
        jmp         fin
    error:
        mov         eax, -1
    fin:
        pop         ebx
        pop         ebp
        ret

