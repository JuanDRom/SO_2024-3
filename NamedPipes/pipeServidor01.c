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
  char BusMesaje[80];
  char final[10];
  int fin;
  int cantidadBytes;
       printf("\n \t\t >>>>>>>>>>>>>INICIO SERVIDO<<<<<<<<<<<<<<<< \n");
    /* Create the FIFO if it does not exist */
    mknod(FIFO_FILE, S_IFIFO|0640, 0);
    strcpy(final, "fin");
    while(1) {
    ArchivoDesc = open(FIFO_FILE, O_RDONLY);      
    cantidadBytes = read(ArchivoDesc, BusMesaje, sizeof(BusMesaje));     
   BusMesaje[cantidadBytes] = '\0';       
   printf("Received string: \"%s\" and length is %d\n", BusMesaje, (int)strlen (BusMesaje));
    fin = strcmp(BusMesaje, final);
       if (fin == 0) {
          close(ArchivoDesc);
          break;
       }
    }
    return 0;
  }
