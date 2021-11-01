%include "io.mac"

global exponente

.CODE
    exponente:
        push        ebp
        mov         ebp, esp
        push        ebx
        mov         ebx, [ebp + 8]  ; Le asigna la base al EBX
        mov         ecx, [ebp + 12] ; Le asigna la potencia al ECX
        mov         eax, 1          ; Asigna 1 al EAX para multiplicar
        cmp         ecx, 0          ; Caso especial, cuando la potencia es 0
        je          fin             ; Retorna 1 si ECX es 0
        jl          error           ; Si la potencia es negativa retorna -1
    ciclo1:
        mul         ebx             ; Multiplica EAX con EBX
        loop        ciclo1          ; Repite el proceso ECX veces
        jmp         fin             ; Terminado el proceso, salta al final
    error:
        mov         eax, -1         ; Asigna el valor -1 a EAX para retornar
    fin:
        pop         ebx
        pop         ebp
        ret                         ; Retorna al programa en C

