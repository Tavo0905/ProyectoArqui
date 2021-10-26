%include "io.mac"

global paridad

.CODE
    paridad:
        enter       0,0
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
        PutLInt     eax
        nwln
        nwln
        leave
        ret