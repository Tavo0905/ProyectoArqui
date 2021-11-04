#include <stdio.h>
#include <stdlib.h>

// Declaración de las funciones NASM y auxiliares
extern int sumarNumeros(int*);
extern int exponente(int, int);
extern int paridad(int);
int toBinary(int);

void interfaz1(int arreglo[10]) {
    //Interfaz de la funcion de sumar 10 numeros, recibe
    //el arreglo, y simula su ejecucion
    // Inicio de variables para la simulacion
    int eax = 0, ebx = 0, ecx = 0, edx = 0, ebp = 0, esp = 0;
    char ceax = *" ", cebx = *" ", cecx = *" ", cedx = *" ", cebp = *" ", cesp = *" ";
    int sf = 0, zf = 0, cf = 0, of = 0;
    int pc = 0, ir = 0, final = 1, fetch = 0;
    char instrucciones[12][25] = {"empujar    EBP", "mover    EBP, ESP",
    "empujar    EBX", "mover    EBX, [EBP + 8]", "mover    ECX, 10",
    "restar    EAX, EAX", "sumar    EAX, [EBX]", "sumar    EBX, 4", "iterar    ciclo",
    "extraer    EBX","extraer    EBP", "retornar"};
    int memoria[12] = {0, 0, arreglo[0], arreglo[1], arreglo[2], arreglo[3],
    arreglo[4], arreglo[5], arreglo[6], arreglo[7], arreglo[8], arreglo[9]};
    while (final) {             // Interfaz de la simulación
        system("clear");
        printf("Registro PC: ");
        toBinary(pc + 1);
        printf("\nRegistro de Instrucciones: ");
        toBinary(ir);
        printf("\n\nRegistro EAX: ");
        toBinary(eax);
        printf("\t\tBandera SF: %d", sf);
        printf("\nRegistro EBX: ");
        toBinary(ebx);
        printf("\t\tBandera ZF: %d\n", zf);
        printf("Registro ECX: ");
        toBinary(ecx);
        printf("\t\tBandera CF: %d", cf);
        printf("\nRegistro EDX: ");
        toBinary(edx);
        printf("\t\tBandera OF: %d\n", of);
        printf("Registro EBP: ");
        toBinary(ebp);
        printf("\nRegistro ESP: ");
        toBinary(esp);
        printf("\n\nInstruccion: %s\n\n", instrucciones[pc]);
        printf("\nMemoria: [");
        for (int i = 0; i < 12; i++) {      // Imprime la memoria del computador
            if (i != 11){ 
                printf("%04X, ", memoria[i]);
            }
            else{
                printf("%04X", memoria[i]);
            }
        }
        printf("]\n\nPresione <enter> para continuar...");
        getchar();
        switch (pc){            // Simula cada una de las instrucciones
            case 0:
                switch (fetch) {        // Simula cada etapa del ciclo de fetch
                    case 0:             // por instrucción
                        ir = 6;
                        break;
                    case 1:
                        memoria[1] = ebp;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 1:
                switch (fetch) {
                    case 0:
                        ir = 1;
                        break;
                    case 1:
                        ebp = esp;
                        if (ebp == 0){
                            zf = 1;
                            sf = 0;
                        } else if (ebp < 0){
                            zf = 0;
                            sf = 1;
                        } else{
                            zf = 0;
                            sf = 0;
                        }
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 2:
                switch (fetch) {
                    case 0:
                        ir = 6;
                        break;
                    case 1:
                        memoria[0] = ebx;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 3:
                switch (fetch) {
                    case 0:
                        ir = 1;
                        break;
                    case 1:
                        ebx = arreglo[0];
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 4:
                switch (fetch) {
                    case 0:
                        ir = 1;
                        break;
                    case 1:
                        ecx = 10;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 5:
                switch (fetch) {
                    case 0:
                        ir = 3;
                        break;
                    case 1:
                        eax = eax - eax;
                        zf = 1;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 6:
                switch (fetch) {
                    case 0:
                        ir = 2;
                        break;
                    case 1:
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
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 7:
                switch (fetch) {
                    case 0:
                        ir = 2;
                        break;
                    case 1:
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
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 8:
                switch (fetch) {
                    case 0:
                        ir = 8;
                        break;
                    case 1:
                        ecx--;
                        break;
                    case 2:
                        if (ecx) {
                            pc = 6;
                        }
                        else {
                            pc++;
                        }
                        fetch = -1;
                        break;
                }
                break;
            case 9:
                switch (fetch) {
                    case 0:
                        ir = 7;
                        break;
                    case 1:
                        ebx = memoria[0];
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 10:
                switch (fetch) {
                    case 0:
                        ir = 7;
                        break;
                    case 1:
                        ebp = memoria[1];
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 11:
                switch (fetch) {
                    case 0:
                        ir = 9;
                        break;
                    case 1:
                        ebp = memoria[1];
                        final = 0;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
        }
        fetch++;
        if (eax >= 0){      // Imprime el complemento a dos de cada registro
            ceax = *" ";
        } else{
            ceax = *"c";
        }
        if (ebx >= 0){
            cebx = *" ";
        } else{
            cebx = *"c";
        }
        if (ecx >= 0){
            cecx = *" ";
        } else{
            cecx = *"c";
        }
        if (edx >= 0){
            cedx = *" ";
        } else{
            cedx = *"c";
        }
        if (ebp >= 0){
            cebp = *" ";
        } else{
            cebp = *"c";
        }
        if (esp >= 0){
            cesp = *" ";
        } else{
            cesp = *"c";
        }
    }
}

void interfaz2(int base, int exponente){
    //Interfaz de la funcion de exponente, recibe
    //los parametros y simula la ejecucion
    // Inicio de variables para la simulacion
    int eax = 0, ebx = 0, ecx = 0, edx = 0, ebp = 0, esp = 0;
    char ceax = *" ", cebx = *" ", cecx = *" ", cedx = *" ", cebp = *" ", cesp = *" ";
    int sf = 0, zf = 0, cf = 0, of = 0;
    int pc = 0, ir = 0, final = 1, fetch = 0;
    char instrucciones[16][25] = {"empujar    EBP", "mover    EBP, ESP",
    "empujar    EBX", "mover    EBX, [EBP + 8]", "mover    ECX, [EBP + 12]",
    "mover    EAX, 1", "comparar    ECX, 0", "saltar igual    fin", "saltar menor    error",
    "multiplicar    EBX", "iterar    ciclo1", "saltar    fin", "mover    EAX, -1",
    "extraer    EBX","extraer    EBP", "retornar"};
    int memoria[4] = {0, 0, base, exponente};
    while (final){
        system("clear");
        printf("Registro PC: ");
        toBinary(pc + 1);
        printf("\nRegistro de Instrucciones: ");
        toBinary(ir);
        printf("\n\nRegistro EAX: ");
        toBinary(eax);
        printf("\t\tBandera SF: %d", sf);
        printf("\nRegistro EBX: ");
        toBinary(ebx);
        printf("\t\tBandera ZF: %d\n", zf);
        printf("Registro ECX: ");
        toBinary(ecx);
        printf("\t\tBandera CF: %d", cf);
        printf("\nRegistro EDX: ");
        toBinary(edx);
        printf("\t\tBandera OF: %d\n", of);
        printf("Registro EBP: ");
        toBinary(ebp);
        printf("\nRegistro ESP: ");
        toBinary(esp);
        printf("\n\nInstruccion: %s\n\n", instrucciones[pc]);
        printf("\nMemoria: [");
        for (int i = 0; i < 4; i++) {       // Imprime la memoria del computador
            if (i != 3){ 
                printf("%04X, ", memoria[i]);
            }
            else{
                printf("%04X", memoria[i]);
            }
        }
        printf("]\n\nPresione <enter> para continuar...");
        getchar();
        switch (pc){            // Simula cada una de las instrucciones del programa
            case 0:
                switch (fetch) {        // Simula cada una de las etapas del
                    case 0:             // Ciclo de fetch por instrucción
                        ir = 6;
                        break;
                    case 1:
                        memoria[1] = ebp;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 1:
                switch (fetch) {
                    case 0:
                        ir = 1;
                        break;
                    case 1:
                        ebp = esp;
                        if (ebp == 0){
                            zf = 1;
                            sf = 0;
                        } else if (ebp < 0){
                            zf = 0;
                            sf = 1;
                        } else{
                            zf = 0;
                            sf = 0;
                        }
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 2:
                switch (fetch) {
                    case 0:
                        ir = 6;
                        break;
                    case 1:
                        memoria[0] = ebx;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 3:
                switch (fetch) {
                    case 0:
                        ir = 1;
                        break;
                    case 1:
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
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 4:
                switch (fetch) {
                    case 0:
                        ir = 1;
                        break;
                    case 1:
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
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 5:
                switch (fetch) {
                    case 0:
                        ir = 1;
                        break;
                    case 1:
                        eax = 1;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 6:
                switch (fetch) {
                    case 0:
                        ir = 10;
                        break;
                    case 1:
                        if (ecx == 0){
                            zf = 1;
                        }
                        if (ecx < 0){
                            sf = 1;
                        }
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 7:
                switch (fetch) {
                    case 0:
                        ir = 12;
                        break;
                    case 1:
                        break;
                    case 2:
                        if (zf == 1){
                            pc = 12;
                        }
                        else {
                            pc++;
                        }
                        fetch = -1;
                        break;
                }
                break;
            case 8:
                switch (fetch) {
                    case 0:
                        ir = 14;
                        break;
                    case 1:
                        break;
                    case 2:
                        if (sf == 1){
                            pc = 11;
                        } 
                        else {
                            pc++;
                        }
                        fetch = -1;
                        break;
                }
                break;
            case 9:
                switch (fetch) {
                    case 0:
                        ir = 4;
                        break;
                    case 1:
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
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 10:
                switch (fetch) {
                    case 0:
                        ir = 8;
                        break;
                    case 1:
                        ecx--;
                        break;
                    case 2:
                        if (ecx){
                            pc = 9;
                        }
                        else {
                            pc++;
                        }
                        fetch = -1;
                        break;
                }
                break;
            case 11:
                switch (fetch) {
                    case 0:
                        ir = 11;
                        break;
                    case 1:
                        break;
                    case 2:
                        pc = 13;
                        fetch = -1;
                        break;
                }
                break;
            case 12:
                switch (fetch) {
                    case 0:
                        ir = 7;
                        break;
                    case 1:
                        eax = -1;
                        sf = 1;
                        zf = 0;
                        cf = 0;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 13:
                switch (fetch) {
                    case 0:
                        ir = 7;
                        break;
                    case 1:
                        ebx = memoria[0];
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 14:
                switch (fetch) {
                    case 0:
                        ir = 7;
                        break;
                    case 1:
                        ebp = memoria[1];
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 15:
                switch (fetch) {
                    case 0:
                        ir = 9;
                        break;
                    case 1:
                        final = 0;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
        }
        fetch++;
        if (eax >= 0){      // Imprime el complemento a dos de cada registro
            ceax = *" ";
        } else{
            ceax = *"c";
        }
        if (ebx >= 0){
            cebx = *" ";
        } else{
            cebx = *"c";
        }
        if (ecx >= 0){
            cecx = *" ";
        } else{
            cecx = *"c";
        }
        if (edx >= 0){
            cedx = *" ";
        } else{
            cedx = *"c";
        }
        if (ebp >= 0){
            cebp = *" ";
        } else{
            cebp = *"c";
        }
        if (esp >= 0){
            cesp = *" ";
        } else{
            cesp = *"c";
        }
    }
}

void interfaz3(int num){
    //Interfaz de la funcion de paridad, recibe el
    //numero por comprobar, y simula su ejecucion
    // Inicio de variables para la simulacion
    int eax = 0, ebx = 0, ecx = 0, edx = 0, ebp = 0, esp = 0;
    char ceax = *" ", cebx = *" ", cecx = *" ", cedx = *" ", cebp = *" ", cesp = *" ";
    int sf = 0, zf = 0, cf = 0, of = 0;
    int pc = 0, ir = 0, final = 1, fetch = 0;
    char instrucciones[15][25] = {"empujar    EBP", "mover    EBP, ESP",
    "empujar    EBX", "mover    EAX, [EBP + 8]", "mover    EBX, 2",
    "restar    EDX, EDX", "dividir    EBX", "comparar    EDX, 0",
    "saltar igual    par","mov    EAX, 0", "saltar    final", "mover    EAX, 1",
    "extraer    EBX", "extraer    EBP", "retornar"};
    int memoria[3] = {0, 0, num};
    while (final){
        system("clear");
        printf("Registro PC: ");
        toBinary(pc + 1);
        printf("\nRegistro de Instrucciones: ");
        toBinary(ir);
        printf("\n\nRegistro EAX: ");
        toBinary(eax);
        printf("\t\tBandera SF: %d", sf);
        printf("\nRegistro EBX: ");
        toBinary(ebx);
        printf("\t\tBandera ZF: %d\n", zf);
        printf("Registro ECX: ");
        toBinary(ecx);
        printf("\t\tBandera CF: %d", cf);
        printf("\nRegistro EDX: ");
        toBinary(edx);
        printf("\t\tBandera OF: %d\n", of);
        printf("Registro EBP: ");
        toBinary(ebp);
        printf("\nRegistro ESP: ");
        toBinary(esp);
        printf("\n\nInstruccion: %s\n\n", instrucciones[pc]);
        printf("\nMemoria: [");
        for (int i = 0; i < 3; i++) { // Imprime la memoria del computador
            if (i != 2){ 
                printf("%04X, ", memoria[i]);
            }
            else{
                printf("%04X", memoria[i]);
            }
        }
        printf("]\n\nPresione <enter> para continuar...");
        getchar();
        switch (pc){        // Simula cada una de las instrucciones
            case 0:
                switch (fetch) {        // Simula cada uno de los ciclos de fetch
                    case 0:             // De cada instruccion
                        ir = 6;
                        break;
                    case 1:
                        memoria[1] = ebp;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 1:
                switch (fetch) {
                    case 0:
                        ir = 1;
                        break;
                    case 1:
                        ebp = esp;
                        if (ebp == 0){
                            zf = 1;
                            sf = 0;
                        } else if (ebp < 0){
                            zf = 0;
                            sf = 1;
                        } else{
                            zf = 0;
                            sf = 0;
                        }
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 2:
                switch (fetch) {
                    case 0:
                        ir = 6;
                        break;
                    case 1:
                        memoria[0] = ebx;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 3:
                switch (fetch) {
                    case 0:
                        ir = 1;
                        break;
                    case 1:
                        eax = num;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 4:
                switch (fetch) {
                    case 0:
                        ir = 1;
                        break;
                    case 1:
                        ebx = 2;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 5:
                switch (fetch) {
                    case 0:
                        ir = 3;
                        break;
                    case 1:
                        edx = edx - edx;
                        zf = 1;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 6:
                switch (fetch) {
                    case 0:
                        ir = 5;
                        break;
                    case 1:
                        edx = eax%ebx;
                        eax = eax/ebx;
                        cf = 0;
                        of = 0;
                        zf = 0;
                        sf = 0;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 7:
                switch (fetch) {
                    case 0:
                        ir = 10;
                        break;
                    case 1:
                        if (edx == 0){
                            zf = 1;
                        }
                        if (edx < 0){
                            sf = 1;
                        }
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 8:
                switch (fetch) {
                    case 0:
                        ir = 12;
                        break;
                    case 1:
                        break;
                    case 2:
                        if (zf == 1){
                            pc = 11;
                        }
                        else {
                            pc++;
                        }
                        fetch = -1;
                        break;
                }
                break;
            case 9:
                switch (fetch) {
                    case 0:
                        ir = 1;
                        break;
                    case 1:
                        eax = 0;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 10:
                switch (fetch) {
                    case 0:
                        ir = 11;
                        break;
                    case 1:
                        break;
                    case 2:
                        pc = 12;
                        fetch = -1;
                        break;
                }
                break;
            case 11:
                switch (fetch) {
                    case 0:
                        ir = 1;
                        break;
                    case 1:
                        eax = 1;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 12:
                switch (fetch) {
                    case 0:
                        ir = 7;
                        break;
                    case 1:
                        ebx = memoria[0];
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 13:
                switch (fetch) {
                    case 0:
                        ir = 7;
                        break;
                    case 1:
                        ebp = memoria[1];
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
            case 14:
                switch (fetch) {
                    case 0:
                        ir = 9;
                        break;
                    case 1:
                        final = 0;
                        break;
                    case 2:
                        pc++;
                        fetch = -1;
                        break;
                }
                break;
        }
        fetch++;
        if (eax >= 0){      //  Valida el complemento a dos de cada registro
            ceax = *" ";
        } else{
            ceax = *"c";
        }
        if (ebx >= 0){
            cebx = *" ";
        } else{
            cebx = *"c";
        }
        if (ecx >= 0){
            cecx = *" ";
        } else{
            cecx = *"c";
        }
        if (edx >= 0){
            cedx = *" ";
        } else{
            cedx = *"c";
        }
        if (ebp >= 0){
            cebp = *" ";
        } else{
            cebp = *"c";
        }
        if (esp >= 0){
            cesp = *" ";
        } else{
            cesp = *"c";
        }
    }
}

void funcion1() {
    // FUNCION DE SUMA DE 10 NUMEROS
    // Recibe los numeros ingresados por el usuario
    // Y los ejecuta en NASM y empieza la simulación
    getchar();
    int entrada = 0;
    int numeros[10];
    for (int i = 0; i < 10; i++) {
        printf("Ingrese el numero %d: ", i + 1);    // Recibe 10 números
        scanf("%d", &entrada);
        numeros[i] = entrada;
    }
    int total = sumarNumeros(numeros);              // Llama a la función de NASM
    getchar();
    interfaz1(numeros);                             // Inicia la simulación
    printf("\nTotal = %d", total);
    getchar();
    return;
}

void funcion2() {
    // FUNCION DE EXPONENTE
    // Recibe los numeros ingresados por el usuario y
    // Llama a la funcion en NASM y empieza el simulador
    getchar();
    int base, exp;
    printf("Ingrese la base de la operacion: ");
    scanf("%d", &base);
    printf("Ingrese el exponente de la operacion: ");
    scanf("%d", &exp);
    int respuesta = exponente(base, exp);   // Llama a la funcion en NASM
    getchar();
    interfaz2(base, exp);                   // Simula el programa en NASM
    printf("\nTotal = %d\n", respuesta);
    getchar();
    return;
}

void funcion3() {
    // FUNCION DE PARIDAD
    // Recibe la entrada del usuario y
    // Llama a la funcion de NASM y ejecuta el simulador
    getchar();
    int num;
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    int par = paridad(num);     // Llama a la funcion en NASM
    getchar();
    interfaz3(num);             // Ejecucion del simulador
    if (par == 1)               // Imprime el resultado según la salida de NASM
        printf("\nEs par");
    else
        printf("\nEs impar");
    getchar();
    return;
}

int twosComplement(int binArray[100], int size){
    int i;
    int result = 1;
    for (i = 1; i <= size; i++){
        if (binArray[i] == 1){
            binArray[i] = 0;
        } else{
            binArray[i] = 1;
        }
    }

    for (i = 1; i <= size; i++){
        if (binArray[i] == 1){
            binArray[i] = 0;
        } else{
            binArray[i] = 1;
            break;
        }
    }

    for (int j = 32; j > size; j--){
        printf("%d", 1);
    }
    for (int j = size ;j> 0;j--){
        printf("%d", binArray[j]);
        //result = result*10 + binArray[j];
    }

    return result;
}

int toBinary(int decimalNumber){
    //int binaryNumber = 0;
    int negative = 0;
    if (decimalNumber < 0){
        negative = 1;
        decimalNumber = 0 - decimalNumber;
    }

    int binaryArray[100],i=1,j;
	int quotient = decimalNumber;
	while(quotient!=0) {
        binaryArray[i++] = quotient % 2;
		quotient = quotient / 2;
	}
    i--;

    if (negative == 1){
        return twosComplement(binaryArray, i);
    }

    for (int j = 32; j > i; j--){
        printf("%d", 0);
    }
	for (j = i;j> 0;j--){
        printf("%d", binaryArray[j]);
        //binaryNumber = binaryNumber*10 + binaryArray[j];
    }
	//return binaryNumber;
}

void main() {
    // Menú principal del simulador, pide una entrada al usuario
    int op;
    while (1) {
        system("clear");
        printf("MENU:\n1. Sumar 10 numeros\n2. Elevar un numero a una potencia\n3. Paridad de un numero\n");
        printf("0. Salir\nIngrese una opcion: ");
        op = getchar();
        if (op == *"1") {
            funcion1();     // Ejecuta el sumador de 10 números
        }
        else if (op == *"2") {
            funcion2();     // Ejecuta la función de exponente
        }
        else if (op == *"3") {
            funcion3();     // Ejecuta la función de paridad
        }
        else if (op == *"0"){
            break;          // Se sale del programa
        }
        else {
            printf("\nLa entrada ingresada no es valida, por favor intente de nuevo\n");
            getchar();
        }
    }
    return;
}