#include <stdio.h>
#include <stdlib.h>

extern int sumarNumeros(int*);
extern int exponente(int, int);
extern int paridad(int);

void interfaz1(int arreglo[10]) {
    int eax = 0, ebx = 0, ecx = 0, sf = 0, zf = 0, cf = 0, of = 0;
    int pc = 0, ir = 0, final = 1, ebp = 0, esp = 0, loop = 9;
    char instrucciones[12][25] = {"empujar    EBP", "mover    EBP, ESP",
    "empujar    EBX", "mover    EBX, [EBP + 8]", "mover    ECX, 10",
    "restar    EAX, EAX", "sumar    EAX, [EBX]", "sumar    EBX, 4", "iterar    ciclo",
    "extraer    EBX","extraer    EBP", "retornar"};
    int memoria[12] = {0, 0, arreglo[0], arreglo[1], arreglo[2], arreglo[3],
    arreglo[4], arreglo[5], arreglo[6], arreglo[7], arreglo[8], arreglo[9]};
    while (final) {
        system("clear");
        printf("Registro PC: %d\n", pc + 1);
        printf("Registro de Instrucciones: %d\n\n", ir);
        printf("Registro EAX: %d         \t\tBandera SF: %d\
        \nRegistro EBX: %d         \t\tBandera ZF: %d\n", eax, sf, ebx, zf);
        printf("Registro ECX: %d         \t\tBandera CF: %d\
        \nRegistro EDX: %d         \t\tBandera OF: %d\n", ecx, cf, of, 0);
        printf("Registro EBP: %d\nRegistro ESP: %d", ebp, esp);
        printf("\n\nInstruccion: %s\n\n", instrucciones[pc]);
        printf("\nMemoria: [");
        for (int i = 0; i < 12; i++) {
            printf(" %d,", memoria[i]);
        }
        printf("]\n\nPresione <enter> para continuar...");
        getchar();
        if (pc == 0) { memoria[1] = ebp; }
        else if (pc == 1) { ebp = esp; }
        else if (pc == 2) { memoria[0] = ebx; }
        else if (pc == 3) { ebx = arreglo[0]; }
        else if (pc == 4) { ecx = 10; }
        else if (pc == 5) { eax = eax - eax; }
        else if (pc == 6) { eax = eax + ebx; }
        else if (pc == 7) { ebx = arreglo[10 - loop]; }
        else if (pc == 8) {
            if (loop) {
                pc = 5;
                loop--;
            }
        }
        else if (pc == 9) { ebx = memoria[0]; }
        else if (pc == 10) { ebp = memoria[1]; }
        else if (pc >= 11) { final = 0; }
        if (eax == 0) { zf = 1; }
        else { zf = 0; }
        if (eax < 0) { sf = 1; }
        else { sf = 0; }
        if (-2147483648 <= eax <= 2147483647) { of = 0; }
        else { of = 1; }
        pc++;
    }
}




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
    getchar();
    interfaz1(numeros);
    printf("\nTotal = %d", total);
    getchar();
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
    printf("Total = %d\n", respuesta);
    getchar();
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
    getchar();
    return;
}


void main() {
    int op;
    while (1) {
        system("clear");
        printf("MENU:\n1. Sumar 10 numeros\n2. Elevar un numero a una potencia\n3. Paridad de un numero\n");
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