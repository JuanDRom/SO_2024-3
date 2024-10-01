/******************************************************************
  autor: Juan Diego Romero
Fecha: 01/10/2024
Sistemas operativos
Comunicacion bi direccional entre named pipes (fifos) en este servidor
se recibe una cadena de texto del cliente y por medio de la funcion string inverso
se envia al cliente la misma cadena que el manda pero invertida. Se hace por medio
de named pipes.
Servidor
******************************************************************/
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

//Definicion de variables y del archivo fifo que se va a usar
#define FIFO_FILE "myfifo"
void reverse_string(char *);
int main() {
  int fd;
  char buffLectura[80];
  char Final[10];
  int final1;
  int read_bytes;

  //crear el fifo en caso de que no exista
  mkfifo(FIFO_FILE, S_IFIFO | 0666);
  strcpy(Final, "Final");
  fd = open(FIFO_FILE, O_RDWR);
  while (1) {
    read_bytes = read(fd, buffLectura, sizeof(buffLectura));
    buffLectura[read_bytes] = '\0';
    printf("FIFOSERVER: mensaje recibido: \"%s\" con un tamano de %d\n", buffLectura,
           (int)strlen(buffLectura));
    final1 = strcmp(buffLectura, Final);

    if (final1 == 0) {
      close(fd);
      break;
    }
    reverse_string(buffLectura);
    printf("FIFOSERVER: Mensaje recibido invertido: \"%s\" con tamano de %d\n",
           buffLectura, (int)strlen(buffLectura));
    write(fd, buffLectura, strlen(buffLectura));
    
    sleep(2);
    close(fd);
  }
  return 0;
}

void reverse_string(char *str) {
  int last, limit, first;
  char temp;
  last = strlen(str) - 1;
  limit = last / 2;
  first = 0;

  while (first < last) {
    temp = str[first];
    str[first] = str[last];
    str[last] = temp;
    first++;
    last--;
  }
  return;
}
