/*******************************************************************************************************
Autor: Juan Diego Romero
Fecha:15/09/2024
Materia: Sistemas Operativos
Taller procesos: 
Se hizo un programa en lenguaje C que recibe cuatro argumentos desde la línea de comandos: dos archivos de texto y dos números enteros que indican
 la cantidad de elementos en cada archivo. Cada archivo contiene un arreglo de números 
enteros, separados por espacios. El programa lee los valores de estos archivos, los almacena en memoria 
dinámica y luego crea tres procesos hijos utilizando fork(). El primer proceso hijo calcula la suma de los
 elementos del primer archivo, el segundo la suma del segundo archivo, y un tercer proceso 
 calcula la suma total de ambos arreglos. El proceso padre recoge estos resultados utilizando pipes y 
 finalmente imprime las sumas individuales y la suma total. Se libera la memoria dinámica antes de finalizar la ejecución del programa.
*******************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


//funcion para leer el archivo y almacenar los numeros en un arreglo
void leer_arreglo(const char *archivo, int *arreglo, int N) {
    FILE *f = fopen(archivo, "r");
    if (f == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < N; i++) {
        if (fscanf(f, "%d", &arreglo[i]) != 1) {
            perror("Error al leer el archivo");
            fclose(f);
            exit(EXIT_FAILURE);
        }
    }
    fclose(f);
}
//Funcion que suma los elementos ya almacenados en un arreglo
int suma_arreglo(int *arreglo, int N) {
    int suma = 0;
    for (int i = 0; i < N; i++) {
        suma += arreglo[i];
    }
    return suma;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Uso: %s N1 archivo00 N2 archivo01\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Lectura de argumentos
    int N1 = atoi(argv[1]);
    const char *archivo00 = argv[2];
    int N2 = atoi(argv[3]);
    const char *archivo01 = argv[4];

    // Reserva de memoria para los arreglos
    int *arreglo1 = (int *)malloc(N1 * sizeof(int));
    int *arreglo2 = (int *)malloc(N2 * sizeof(int));
    //verificación para evitar errores posteriores en la ejecucion
    if (arreglo1 == NULL || arreglo2 == NULL) {
        perror("Error en la reserva de memoria");
        exit(EXIT_FAILURE);
    }

    // Lectura de los archivos
    leer_arreglo(archivo00, arreglo1, N1);
    leer_arreglo(archivo01, arreglo2, N2);

    // Pipes para comunicación entre procesos
    int pipe1[2], pipe2[2], pipe3[2];
    pipe(pipe1);
    pipe(pipe2);
    pipe(pipe3);

    pid_t pid1 = fork();
    if (pid1 == 0) {  // Primer hijo: suma del arreglo del primer archivo
        int sumaA = suma_arreglo(arreglo1, N1);
        close(pipe1[0]);
        write(pipe1[1], &sumaA, sizeof(sumaA));
        close(pipe1[1]);
        exit(0);
    }

    pid_t pid2 = fork();
    if (pid2 == 0) {  // Segundo hijo: suma del arreglo del segundo archivo
        int sumaB = suma_arreglo(arreglo2, N2);
        close(pipe2[0]);
        write(pipe2[1], &sumaB, sizeof(sumaB));
        close(pipe2[1]);
        exit(0);
    }

    pid_t pid3 = fork();
    if (pid3 == 0) {  // Suma de los dos arreglos combinados
        int suma_total = suma_arreglo(arreglo1, N1) + suma_arreglo(arreglo2, N2);
        close(pipe3[0]);
        write(pipe3[1], &suma_total, sizeof(suma_total));
        close(pipe3[1]);
        exit(0);
    }

    // Proceso padre: recibe las sumas e imprime resultados
    int sumaA, sumaB, suma_total;
    close(pipe1[1]);
    close(pipe2[1]);
    close(pipe3[1]);

    // Lectura de las sumas
    read(pipe1[0], &sumaA, sizeof(sumaA));
    read(pipe2[0], &sumaB, sizeof(sumaB));
    read(pipe3[0], &suma_total, sizeof(suma_total));
    //Cerramos los pipes 
    close(pipe1[0]);
    close(pipe2[0]);
    close(pipe3[0]);

    // Impresión de resultados
    printf("Suma del arreglo del archivo00: %d\n", sumaA);
    printf("Suma del arreglo del archivo01: %d\n", sumaB);
    printf("Suma total de ambos arreglos: %d\n", suma_total);

    // Liberación de memoria
    free(arreglo1);
    free(arreglo2);

    return 0;
}
