#include <stdio.h>
#include <stdlib.h>

extern int sumarNumeros(int*);
extern int exponente(int, int);
extern int paridad(int);

void interfaz1(int arreglo[10]) {
    int eax = 0;
    int ebx = 0, ecx = 0, edx = 0, ebp = 0, esp = 0;
    int sf = 0, zf = 0, cf = 0, of = 0;
    int pc = 0, ir = 0, final = 1;
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
        \nRegistro EDX: %d         \t\tBandera OF: %d\n", ecx, cf, edx, of);
        printf("Registro EBP: %d\nRegistro ESP: %d", ebp, esp);
        printf("\n\nInstruccion: %s\n\n", instrucciones[pc]);
        printf("\nMemoria: [");
        for (int i = 0; i < 12; i++) {
            if (i != 11){ 
                printf(" %d,", memoria[i]);
            }
            else{
                printf(" %d", memoria[i]);
            }
        }
        printf("]\n\nPresione <enter> para continuar...");
        getchar();

        switch (pc){
            case 0:
                memoria[1] = ebp;
                break;
            case 1:
                ebp = esp;
                break;
            case 2:
                memoria[0] = ebx;
                break;
            case 3:
                ebx = arreglo[0];
                break;
            case 4:
                ecx = 10;
                break;
            case 5:
                eax = eax - eax;
                zf = 1;
                break;
            case 6:
                if ((eax > 0 && ebx > 0 && 2147483647 - eax - ebx < 0) || (eax < 0 && ebx < 0 && -2147483648 + eax + ebx > 0)){
                    of = 1;
                    cf = 1;
                }
                else{
                    of = 0;
                    cf = 0;
                }
                eax = eax + ebx;
                if (eax == 0){
                    zf = 1;
                    sf = 0;
                } else if (eax < 0){
                    zf = 0;
                    sf = 1;
                } else{
                    zf = 0;
                    sf = 0;
                }
                break;
            case 7:
                ebx = arreglo[10 - ecx + 1];
                if (ebx == 0){
                    zf = 1;
                    sf = 0;
                } else if (ebx < 0){
                    zf = 0;
                    sf = 1;
                } else{
                    zf = 0;
                    sf = 0;
                }
                of = 0;
                cf = 0;
                break;
            case 8:
                if (ecx - 1) {
                    pc = 5;
                }
                ecx--;
                break;
            case 9:
                ebx = memoria[0];
                break;
            case 10:
                ebp = memoria[1];
                break;
            case 11:
                final = 0;
                break;
        }
        /*if (pc == 0) { memoria[1] = ebp; }
        else if (pc == 1) { ebp = esp; }
        else if (pc == 2) { memoria[0] = ebx; }
        else if (pc == 3) { ebx = arreglo[0]; }
        else if (pc == 4) { ecx = 10; }
        else if (pc == 5) { eax = eax - eax; }
        else if (pc == 6) { eax = eax + ebx; }
        else if (pc == 7) { ebx = arreglo[10 - ecx + 1]; }
        else if (pc == 8) {
            if (ecx - 1) {
                pc = 5;
            }
            ecx--;
        }
        else if (pc == 9) { ebx = memoria[0]; }
        else if (pc == 10) { ebp = memoria[1]; }
        else if (pc >= 11) { final = 0; }

        if (eax == 0 && pc >= 5) { zf = 1; }
        else { zf = 0; }
        if (eax < 0) { sf = 1; }
        else { sf = 0; }
        if (-2147483648 <= eax <= 2147483647) { of = 0; }
        else { of = 1; }*/
        pc++;
    }
}

void interfaz2(int base, int exponente){
    int eax = 0, ebx = 0, ecx = 0, edx = 0, ebp = 0, esp = 0;
    int sf = 0, zf = 0, cf = 0, of = 0;
    int pc = 0, ir = 0, final = 1;
    char instrucciones[16][25] = {"empujar    EBP", "mover    EBP, ESP",
    "empujar    EBX", "mover    EBX, [EBP + 8]", "mover    ECX, [EBP + 12]",
    "mover    EAX, 1", "comparar    ECX, 0", "saltar igual    fin", "saltar menor    error",
    "multiplicar    EBX", "iterar    ciclo1", "saltar    fin", "mover    EAX, -1",
    "extraer    EBX","extraer    EBP", "retornar"};
    int memoria[4] = {0, 0, base, exponente};

    while (final){
        system("clear");
        printf("Registro PC: %d\n", pc + 1);
        printf("Registro de Instrucciones: %d\n\n", ir);
        printf("Registro EAX: %d         \t\tBandera SF: %d\
        \nRegistro EBX: %d         \t\tBandera ZF: %d\n", eax, sf, ebx, zf);
        printf("Registro ECX: %d         \t\tBandera CF: %d\
        \nRegistro EDX: %d         \t\tBandera OF: %d\n", ecx, cf, edx, of);
        printf("Registro EBP: %d\nRegistro ESP: %d", ebp, esp);
        printf("\n\nInstruccion: %s\n\n", instrucciones[pc]);
        printf("\nMemoria: [");
        for (int i = 0; i < 4; i++) {
            if (i != 3){ 
                printf(" %d,", memoria[i]);
            }
            else{
                printf(" %d", memoria[i]);
            }
        }
        printf("]\n\nPresione <enter> para continuar...");
        getchar();

        switch (pc){
            case 0:
                memoria[1] = ebp;
                break;
            case 1:
                ebp = esp;
                break;
            case 2:
                memoria[0] = ebx;
                break;
            case 3:
                ebx = base;
                if (ebx == 0){
                    zf = 1;
                } else{
                    zf = 0;
                }
                if (ebx < 0){
                    sf = 1;
                } else{
                    sf = 0;
                }
                break;
            case 4:
                ecx = exponente;
                if (ecx == 0){
                    zf = 1;
                } else{
                    zf = 0;
                }
                if (ecx < 0){
                    sf = 1;
                } else{
                    sf = 0;
                }
                break;
            case 5:
                eax = 1;
                break;
            case 6:
                if (ecx == 0){
                    zf = 1;
                }
                if (ecx < 0){
                    sf = 1;
                }
                break;
            case 7:
                if (zf == 1){
                    pc = 12;
                }
                break;
            case 8:
                if (sf == 1){
                    pc = 11;
                } 
                break;
            case 9:
                if (((eax > 0 && ebx > 0 || eax < 0 && ebx < 0) && eax*ebx < 0) ||
                ((eax > 0 && ebx < 0 || eax < 0 && ebx > 0) && eax*ebx > 0)){
                    of = 1;
                    cf = 1;
                }
                else{
                    of = 0;
                    cf = 0;
                }
                eax = eax*ebx;
                break;
            case 10:
                if (ecx - 1){
                    pc = 8;
                }
                ecx--;
                break;
            case 11:
                pc = 12;
                break;
            case 12:
                eax = -1;
                sf = 1;
                zf = 0;
                cf = 0;
                break;
            case 13:
                ebx = memoria[0];
                break;
            case 14:
                ebp = memoria[1];
                break;
            case 15:
                final = 0;
                break;
        }

        /*if (eax == 0 && pc >= 5) { zf = 1; }
        else { zf = 0; }
        if (eax < 0) { sf = 1; }
        else { sf = 0; }
        if (-2147483648 <= eax <= 2147483647) { of = 0; }
        else { of = 1; }*/
        pc++;
    }
}

void interfaz3(int num){
    int eax = 0, ebx = 0, ecx = 0, edx = 0, ebp = 0, esp = 0;
    int sf = 0, zf = 0, cf = 0, of = 0;
    int pc = 0, ir = 0, final = 1;
    char instrucciones[15][25] = {"empujar    EBP", "mover    EBP, ESP",
    "empujar    EBX", "mover    EAX, [EBP + 8]", "mover    EBX, 2",
    "restar    EDX, EDX", "dividir    EBX", "comparar    EDX, 0",
    "saltar igual    par","mov    EAX, 0", "saltar    final", "mover    EAX, 1",
    "extraer    EBX", "extraer    EBP", "retornar"};
    int memoria[3] = {0, 0, num};

    while (final){
        system("clear");
        printf("Registro PC: %d\n", pc + 1);
        printf("Registro de Instrucciones: %d\n\n", ir);
        printf("Registro EAX: %d         \t\tBandera SF: %d\
        \nRegistro EBX: %d         \t\tBandera ZF: %d\n", eax, sf, ebx, zf);
        printf("Registro ECX: %d         \t\tBandera CF: %d\
        \nRegistro EDX: %d         \t\tBandera OF: %d\n", ecx, cf, edx, of);
        printf("Registro EBP: %d\nRegistro ESP: %d", ebp, esp);
        printf("\n\nInstruccion: %s\n\n", instrucciones[pc]);
        printf("\nMemoria: [");
        for (int i = 0; i < 3; i++) {
            if (i != 2){ 
                printf(" %d,", memoria[i]);
            }
            else{
                printf(" %d", memoria[i]);
            }
        }
        printf("]\n\nPresione <enter> para continuar...");
        getchar();

        switch (pc){
            case 0:
                memoria[1] = ebp;
                break;
            case 1:
                ebp = esp;
                break;
            case 2:
                memoria[0] = ebx;
                break;
            case 3:
                eax = num;
                break;
            case 4:
                ebx = 2;
                break;
            case 5:
                edx = edx - edx;
                zf = 1;
                break;
            case 6:
                edx = eax%ebx;
                eax = eax/ebx;
                cf = 0;
                of = 0;
                zf = 0;
                sf = 0;
                break;
            case 7:
                if (edx == 0){
                    zf = 1;
                }
                if (edx < 0){
                    sf = 1;
                }
                break;
            case 8:
                if (zf == 1){
                    pc = 10;
                }
                break;
            case 9:
                eax = 0;
                break;
            case 10:
                pc = 11;
                break;
            case 11:
                eax = 1;
                break;
            case 12:
                ebx = memoria[0];
                break;
            case 13:
                ebp = memoria[1];
                break;
            case 14:
                final = 0;
                break;
        }
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
    getchar();
    interfaz2(base, exp);
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
    getchar();
    interfaz3(num);
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
        else if (op == *"0"){
            break;
        }
        else {
            printf("\nLa entrada ingresada no es valida, por favor intente de nuevo\n");
            getchar();
        }
    }
    return;
}