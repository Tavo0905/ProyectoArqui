%include "io.mac"

global sumarNumeros

.CODE
    sumarNumeros:
        push        ebp
        mov         ebp, esp
        push        ebx
        mov         ebx, [ebp + 8]  ; EBX apunta al inicio del arreglo
        mov         ecx, 10         ; Cantidad de numeros por sumar
        sub         eax, eax
    ciclo:
        add         eax, [ebx]
        add         ebx, 4          ; Pasa al siguiente numero del arreglo
        loop        ciclo           ; Suma ECX veces (10)
        pop         ebx
        pop         ebp
        ret