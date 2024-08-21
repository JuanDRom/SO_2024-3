/**********************************************************
autor: Juan Diego Romero
Clase: Sistemas operativos
Tema: Uso de la funcion realloc()
Conceptos: La función realloc se utiliza para redimensionar un bloque de memoria
que ya ha sido reservado dinámicamente.
Universidad: Pontificicia Universidad Javeriana
Fecha: 13/08/2024
***********************************************************/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int main() {

  // Definimos dos enteros para luego usarlos como el tamaño del arreglo
  int tam1 = 4;
  int tam2 = 8;
  // Se declara un puntero y se asigna memoria para 4 enteros haciendo uso de la
  // funcion malloc
  int *ar1 = (int *)malloc(
      tam1 * sizeof(int)); // 4 bloques de memoria de tamaño entero.

  // Comprobación de que la memoria fue asignada correctamente
  if (ar1 == NULL) {
    printf("Error al asignar memoria\n");
    return 1;
  }

  // LLenamos el arreglo con numeros
  for (int i = 0; i < tam1; i++) {
    ar1[i] = i + 1;
    printf("El valor del arreglo es: %d \n", ar1[i]);
  }

  // Cambiamos el tamaño del arreglo de tam1(4) a tam2(8)
  ar1 = realloc(ar1, tam2 * sizeof(int));

  // Comprobamos nuevamente que el arreglo este bien asignado
  if (ar1 == NULL) {
    printf("Error al redimensionar la memoria\n");
    return 1;
  }

  // volvemos a llenar el arreglo pero con un tamaño nuevo tam2(8)
  printf("\n\nNueva secuencia: \n");
  for (int i = 0; i < tam2; i++) {
    ar1[i] = i + 1;
    printf("El valor del arreglo es: %d \n", ar1[i]);
  }

  // Liberamos la memoria
  free(ar1);

  return 0;
}
