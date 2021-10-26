global sumarNumeros

sumarNumeros:
    enter       0,0
    mov         ebx, [ebp + 8]
    mov         ecx, 10
    sub         eax, eax
ciclo:
    add         eax, [ebx]
    inc         ebx
    loop        ciclo
    leave
    ret