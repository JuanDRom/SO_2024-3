/******************************************
Autor: Juan Diego Romero Plata
Fecha: 30-07-2024
Materia: Sistemas operativos
Pontificia universidad Javeriana
*******************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  
  /*printf("Ha ingresado [%d]: \n\n", argc);
  printf("Ha ingresado la edad: %s\n\n;", argv[0]);
  printf("Ha ingresado el mes: %s\n\n", argv[1]);*/
  
  /*printf("\n"); 
  printf(":::::Programa::::\n");
  int suma = 0;
  
  for(int i = 1; i <= 8; i++){
    int numero = atoi(argv[i]);
    printf("El numero %d es: %d \n", i, numero);
    suma += numero;
    
  }
  printf("La suma de los numeros es: %d\n", suma);*/
  
 /* int vector[] = {5,10,15,20,30,35};
  int *p1 = vector;
  int *p2 = vector + 2;
  int diferencia = p2 - p1;
  
  printf("\n El valor de p1 es de: %p ", p1);
  printf("\n El valor de p2 es de: %p ", p2);
  printf("\n El valor de la diferencia es de: %d\n", diferencia);
  */
  printf("Dato     Identificador\n");
  printf("iny     %%d %%i\n");
  printf("char     %%c\n");
  printf("float     %%f\n");
  printf("dpuble     %%lf\n");
  printf("short     %%hd\n");
  printf("long     %%ld\n");
  printf("long long     %%lld\n");
  printf("unsigned int     %%u\n");
  printf("unsigned short     %%hu\n");
  printf("unsigned long     %%lu\n");
  printf("unsigned long long     %%llu\n");
  printf("signed char     %%hhi\n");
  printf("unsigned char     %%hhu\n");
  printf("long double     %%lF\n");


  return 0;
}