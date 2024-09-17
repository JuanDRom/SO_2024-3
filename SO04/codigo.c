/*******************************************************************************************************
Autor: Jocelyne Gonzalez Hernanadez
Fecha:03/09/2024
Materia: Sistemas Operativos
Tema:Introducción a procesos con Fork
Descripción:
*Fork: al ser invocado crea un proceso "hijo" y uno "padre".
**Cada uno de estos al ser invocados tienen diferentes espacios de memoria (2 procesos diferentes).
**Son idénticos hasta que el programador determine lo contrario.
*******************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Da un menú de funciones de unix

int main(){
  //Se crea el proceso hijo con la misma información
  fork(); 
  printf("\n\nHola profesionales en formación\n");
}