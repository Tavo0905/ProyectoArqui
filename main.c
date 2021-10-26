#include <stdio.h>
#include <stdlib.h>

extern int sumarNumeros(int*);
extern int exponente(int, int);
extern int paridad(int);

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
    getchar();
    int base, exp;
    printf("Ingrese la base de la operacion: ");
    scanf("%d", &base);
    printf("Ingrese el exponente de la operacion: ");
    scanf("%d", &exp);
    int respuesta = exponente(base, exp);
    printf("Total = %d", respuesta);
    return;
}

void funcion3() {
    getchar();
    int num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    int par = paridad(num);
    if (par == 1)
        printf("Es par");
    else
        printf("Es impar");
    return;
}


void main() {
    int op;
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