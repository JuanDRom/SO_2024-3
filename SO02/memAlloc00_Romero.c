/**********************************************************
autor: Juan Diego Romero
Clase: Sistemas operativos
Tema: Uso de la funcion malloc()
Conceptos: La funcion maloc reserva un espacio de memoria del tamaño requerido
indicando el inicio de la memoria reservada, haciendo uso de un puntero.
Universidad: Pontificicia Universidad Javeriana
Fecha: 13/08/2024
***********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int main(){

//se declaran las variables y punteros necesarios
  int *bloque00 = malloc(4*sizeof(int)); //asignación de memoria con tamaño de 4 bytes, tipo entero.
  int *puntero = malloc (15 *sizeof(*puntero)); //asignación de memoria de 15 bytes, tipo entero.
//Bucle para llenar los espacios de memoria del primer bloque (00)
  for(int i = 0; i < 4; i++)
    {
      bloque00[i] = i*2;
      printf("El valor de memoria reservada de bloque00[%d] = %d\n\n", i, bloque00[i]);
    }
    //bucle para llenar los espacios del puntero
    if(puntero != NULL){
        *(puntero + 8) = 9889;
            printf("El valor de la novena posicion de puntero es: %d \n\n", *(puntero+8));
      }
  //liberamos memoria reservada.
  free(bloque00);
  free(puntero);

  return 0;
}