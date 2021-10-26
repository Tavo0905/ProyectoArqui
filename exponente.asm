%include "io.mac"

global exponente

.CODE
    exponente:
        enter       0,0
        mov         ebx, [ebp + 8]
        mov         ecx, [ebp + 12]
        mov         eax, 1
    ciclo1:
        mul         ebx
        loop        ciclo1
        leave
        ret