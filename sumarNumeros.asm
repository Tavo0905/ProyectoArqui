%include "io.mac"

global sumarNumeros

.CODE
    sumarNumeros:
        enter       0,0
        mov         ebx, [ebp + 8]
        mov         ecx, 10
        sub         eax, eax
    ciclo:
        add         eax, [ebx]
        add         ebx, 4
        loop        ciclo
        leave
        ret