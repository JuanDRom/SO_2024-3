/**********************************************************
autor: Juan Diego Romero
Clase: Sistemas operativos
Tema: Uso de la funcion calloc()
Conceptos: La función calloc reserva un espacio de memooria de tamaño requerido, 
son de espacios de igual tamaño y de memoria contigua, se asigna de forma dinámica y
es especialmente útil para complejas estructuras de datos. 
Universidad: Pontificicia Universidad Javeriana
Fecha: 13/08/2024
***********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

int main(){

//se declaran las variables y punteros necesarios
  int *p1 = calloc(4,  sizeof(int)); //4 bloques de memoria de tamaño entero.
  int *p2 = calloc (10, sizeof(int[4])); //10 bloques de memoria de 1 int
  int *p3 = calloc (5, sizeof *p3); //5 bloques de memoria de tipo entero

//Bucle para llenar los espacios de memoria del primer bloque (00)
  printf("Contrusccicón y calculo de la secuencia de los primeros 10 términos \n");
  for(int i = 0; i < 10; i++){
    *(p2 +i) = i;
    printf("El valor de la secuencia es %d \n", i);
  }
    
  
  //liberamos memoria reservada.
  free(p1);
  free(p2);
  free(p3);

  return 0;
}