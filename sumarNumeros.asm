%include "io.mac"

global sumarNumeros

.CODE
    sumarNumeros:
        push        ebp         ; inicio
        mov         ebp, esp
        push        ebx         ; final
        mov         ebx, [ebp + 8]
        mov         ecx, 10
        sub         eax, eax
    ciclo:
        add         eax, [ebx]
        add         ebx, 4
        loop        ciclo
        pop         ebx
        pop         ebp
        ret