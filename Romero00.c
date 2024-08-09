/******************************
Autor: juan diego romero
Clase: sistemas operativos
Tema:primer taller guiado programado
Pontificia universidad Javeriana
Julio 2024
Requerimientos
  -Funcion que sume 2 enteros
  -Funcion que calcule el area de una circunferencia
  -Funcion que de la bienvenida
**************************/
#include <stdio.h>


/*Funcion de bienvenida*/

void bienvenida(){
    
  printf("Hola mundo\n");
  printf("\t\tGracias por la bienvenida a la clase de sistemas operativos :)\n");
}
//Funcion de suma de dos enteros
void suma(){
  printf("Primer entero es: 5\n");
  printf("Segundo entero es: 15\n");
  int a = 5 + 15;
  printf("El resultado es: %d\n", a);
}

//Función que calcula el area de una circunferencia
void areaCircunferencia(){
  int r = 5;
  float pi = 3.14;
  float area = r * r * pi;
  printf("El area del criculo con es %f\n",area);
  
  
}
int main(int argc, char *argv[]){
  
  bienvenida();
  suma();
  areaCircunferencia();

  
 
  return 0;
}