/*******************************************************************************************************
Autor: Juan Diego Romero
Fecha:03/09/2024
Materia: Sistemas Operativos
Tema:Introducción a procesos con Fork

*******************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Da un menú de funciones de unix

int main(){
  //Se crea el proceso hijo con la misma información
  fork(); 
  printf("\n\nHola profesionales en formación\n");
}
