/*****************************************************************
 * Autor: Juan Diego Romero
 * Fecha: 24/09/2024
 * Clase: Sistemas operativos
 * Descripcion: Implementación de un cliente/servidor para el uso y prueba de named pipes en c
 *****************************************************************/
 #include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>


#define FIFO_FILE "MYFIFO"
int main() {
    int ArchivoDesc;
    int fin_proceso;
    int cadena;
    char BusMensaje[80];
    char senalFin[5];
  printf("\n \t\t >>>>>>>>>>>>>INICIO CLIENTE<<<<<<<<<<<<<<<< \n");
    printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");
    ArchivoDesc = open(FIFO_FILE, O_CREAT|O_WRONLY);
    strcpy(senalFin, "fin");
  
     while (1) {
        printf("Enter string: ");
        fgets(BusMensaje, sizeof(BusMensaje), stdin);
        cadena = strlen(BusMensaje);
        BusMensaje[cadena - 1] = '\0';
        fin_proceso = strcmp(BusMensaje, senalFin);
  
        printf("end_process is %d\n", fin_proceso);
        if (fin_proceso != 0) {
           write(ArchivoDesc, BusMensaje, strlen(BusMensaje));
           printf("Sent string: \"%s\" and string length is %d\n", BusMensaje, (int)    strlen(BusMensaje));
        } else {
           write(ArchivoDesc, BusMensaje, strlen(BusMensaje));
           printf("Sent string: \"%s\" and string length is %d\n", BusMensaje, (int)    strlen(BusMensaje));
           close(ArchivoDesc);
           break;
        }
     }
     return 0;
  
}
