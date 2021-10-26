#include <stdio.h>
#include <stdlib.h>
#include "sumarNumeros.asm"

void funcion1() {
    getchar();
    int entrada = 0;
    int numeros[10];
    for (int i = 0; i < 10; i++) {
        printf("Ingrese el numero %d: ", i + 1);
        scanf("%d", &entrada);
        numeros[i] = entrada;
    }
    int total = sumarNumeros(numeros);
    printf("Total = %d", total);
    return;
}

void funcion2() {
    return;
}

void funcion3() {
    return;
}


void main() {
    int op;
    extern int sumarNumeros(int*);
    while (1) {
        system("clear");
        printf("MENU:\n1. Ejecutar el primer programa\n2. Ejecutar el segundo programa\n3. Ejecutar el tercer programa\n");
        printf("Ingrese una opcion: ");
        op = getchar();
        if (op == *"1") {
            funcion1();
        }
        else if (op == *"2") {
            funcion2();
        }
        else if (op == *"3") {
            funcion3();
        }
        else {
            printf("\nLa entrada ingresada no es valida, por favor intente de nuevo\n");
            getchar();
        }
        getchar();
    }
    return;
}