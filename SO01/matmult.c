/************************************************
Nombre: Juan Diego Romero Plata
Fecha: 06-08-2024
Sistemas operativos
Pontificia Universidad Javeriana
Tema: evaluación del rendimiento de sistemas de cómputo
*************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Reserva de memoria
#define DATA_RESERVA (1024*1024*64*3)
static double MEM_CHUNK[DATA_RESERVA];
//Funcion para multiplicar la matriz
void mult_matriz(int SZ, double *a, double *b, double *c){
  int i, j, k;
  for(i = 0; i < SZ; i++){
    for(j = 0; j < SZ; j++){
      double *pA, *pB, sumaTemp;
      sumaTemp = 0.0;
      pA = a+(i*SZ); pB = b+j;
      for(k = SZ; k > 0; k--, pA++, pB+=SZ)
        sumaTemp += (*pA * *pB);
      c[i*SZ + j] = sumaTemp;
    }
  }
 
}
//Funcion para inicializar la matriz
void Init_matriz(int SZ, double *a, double *b, double *c){
  int i, j, k;
  for(k = 0; k < SZ; k++){
    for(j = 0; j < SZ; j++){
      a[j+k *SZ] = 2.3*(j+k);
      b[j+k *SZ] = 3.2*(j-k);
      c[j+k *SZ] = 1.3;
    }
  }
 
}
//Funcion para imprimir la matriz
void print_matriz(int SZ, double *a){
  
  int i, j, k;
  for(k = 0; k < SZ; k++){
    for(j = 0; j < SZ; j++){
      printf("%f", a[j+k *SZ]);
    }
    printf("\n");
  }
  printf("----------------------------------------");
}

int main(int argc, char *argv[]){
  //If para asegurar que se ingresen argumentos a la matriz.
  if(argc < 2){
    printf("./matmult matrixSize numHilos... \n");
    return -1;
  }
  //definicion de variables (reserva de memoria para las matrices)
  double *A, *B, *C;
  int N = (int) atof(argv[1]);
  int h = (int) atof(argv[2]);
  //reserva inicial de la matriz
  A =MEM_CHUNK;
  B = A + N*N;
  C = B + N*N;
  
  
  printf("Valores ingresados: \n");
  printf("matrix size (NxN): %dx%d\n",N,N );
  printf("Número de hilos (h): %d\n", h);
  Init_matriz(N, A, B, C);
  print_matriz(N, A);
  print_matriz(N, B);
  mult_matriz(N,A,B,C);
 
  print_matriz(N, C);

  

  return 0;
}