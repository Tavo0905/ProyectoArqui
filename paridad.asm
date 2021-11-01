%include "io.mac"

global paridad

.CODE
    paridad:
        push        ebp
        mov         ebp, esp
        push        ebx
        mov         eax, [ebp + 8]  ; EAX obtiene el valor a comparar
        mov         ebx, 2          ; Mueve a EBX el divisor
        sub         edx, edx
        div         ebx             ; Divide el EAX con EBX
        cmp         edx, 0          ; Si EDX es 0, es par
        je          par             ; Salta si es igual
        mov         eax, 0          ; Retorna un 0 si es impar
        jmp         final           ; Salta al final
    par:
        mov         eax, 1          ; Retorna un 1 si es par
    final:
        pop         ebx
        pop         ebp
        ret                         ; Retorna al programa en C