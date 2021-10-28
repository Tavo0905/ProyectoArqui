%include "io.mac"

global paridad

.CODE
    paridad:
        push        ebp         ; inicio
        mov         ebp, esp
        push        ebx         ; final
        mov         eax, [ebp + 8]
        mov         ebx, 2
        sub         edx, edx
        div         ebx
        cmp         edx, 0
        je          par
        mov         eax, 0
        jmp         final
    par:
        mov         eax, 1
    final:
        pop         ebx
        pop         ebp
        ret