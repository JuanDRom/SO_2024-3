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
void suma(int a, int b){
  printf("Primer entero es: %d\n", a);
  printf("Segundo entero es: %d\n", b);
  int c = a + b;
  printf("El resultado es: %d\n", a);
}

//Función que calcula el area de una circunferencia
void areaCircunferencia(float r){
  float pi = 3.14;
  float area = r * r * pi;
  printf("El area del criculo con es %f\n",area);
  
  
}
int main(int argc, char *argv[]){
  
  bienvenida();
  int n1, n2;
  float r;
  printf("ingrese el primer numero a sumar: ");
  scanf("%d", &n1);
  printf("\ningrese el segundo numero a sumar:");
  scanf("%d", &n2);
  suma(n1,n2);
  printf("\ningrese el area del circulo: ");
  scanf("%f", &r);
  areaCircunferencia(r);

  
 
  return 0;
}