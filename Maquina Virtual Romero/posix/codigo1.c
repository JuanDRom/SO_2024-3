/* 
Nombre: Juan Diego Romero
Materia: Sistemas Operativos
Tema: POSIX
Descripción: Este programa crea un conjunto de hilos usando POSIX en C. 
Cada hilo ejecuta una función que imprime el número de trabajo que le corresponde. 
Primero se crean los hilos con `pthread_create` y, al terminar, el programa espera 
que cada hilo complete su ejecución con `pthread_join`.
*/
 

/*Función cualquiera para ejecutar el thread*/
 static void *funcion(void *argumentos){
      size_t job = *(size_t *)argumentos;
      printf("\n\t Job %zu \n", job);
      return NULL;
  }

 int main(int argc, char *argv[]){
      int N = (int)atoi(argv[1]);
      size_t jobs[N];                 //Vector de trabajos|
      pthread_t hilos[N];             //Vector de hilos
      for(int i=0; i<N; i++){
          jobs[i] = i;
         //Creación de hilos y envío de función
          pthread_create(&hilos[i], NULL, funcion, jobs+i);
      }
      for(int i=0; i<N; i++)
          pthread_join(hilos[i], NULL);
 
      return 0;
  }
