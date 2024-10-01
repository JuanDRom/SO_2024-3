/******************************************************************
  autor: Juan Diego Romero
Fecha: 01/10/2024
Sistemas operativos
Comunicacion bi direccional entre named pipes (fifos), el cliente se comunica
con el servidor, recibe una señal para enviar un mensaje para posteriormente recibir
una respuesta del servidor, esta respuesta siendo su mensaje invertido.
Cliente
******************************************************************/
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_FILE "myfifo"
int main() {
  int fd;
  int final_linea;
  int TamMensaje;
  int Lectura;
  char buffLectura[80];
  char finCadena[5];
  printf("FIFO_CLIENT: Send messages, infinitely, to end enter \"end\"\n");
  fd = open(FIFO_FILE, O_CREAT | O_RDWR);
  strcpy(finCadena, "salir");

  while (1) {
    printf("Ingrese frase: ");
    fgets(buffLectura, sizeof(buffLectura), stdin);
    TamMensaje = strlen(buffLectura);
    buffLectura[TamMensaje - 1] = '\0';
    final_linea = strcmp(buffLectura, finCadena);

    // printf("final_linea is %d\n", final_linea);
    if (final_linea != 0) {
      write(fd, buffLectura, strlen(buffLectura));
      printf("FIFOCLIENT: Mensaje enviado: \"%s\" con un tamaño de %d\n",
             buffLectura, (int)strlen(buffLectura));
      Lectura = read(fd, buffLectura, sizeof(buffLectura));
      buffLectura[Lectura] = '\0';
      printf("FIFOCLIENT: Recibiendo cadena: \"%s\" con tamano de %d\n", buffLectura,
             (int)strlen(buffLectura));
    } else {
      write(fd, buffLectura, strlen(buffLectura));
      printf("FIFOCLIENT: Mensaje enviado: \"%s\" con un tamaño de %d\n",
             buffLectura, (int)strlen(buffLectura));
      close(fd);
      break;
    }
  }
  return 0;
}
