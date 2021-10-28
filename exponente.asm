%include "io.mac"

global exponente

.CODE
    exponente:
        push        ebp         ; inicio
        mov         ebp, esp
        push        ebx         ; final
        mov         ebx, [ebp + 8]
        mov         ecx, [ebp + 12]
        mov         eax, 1
    ciclo1:
        mul         ebx
        loop        ciclo1
        pop         ebx
        pop         ebp
        ret
