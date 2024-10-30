/* 
Nombre: Juan Diego Romero
Materia: Sistemas Operativos
Tema: POSIX
Descripción: Este programa inicializa un modelo productor-consumidor en el que se crean múltiples hilos productores 
y consumidores. Utiliza mutex y variables de condición para sincronizar el acceso al recurso compartido `counter`, 
asegurando que los productores y consumidores puedan operar sin interferencias y evitar condiciones de carrera.
*/

int counter = 0;
int max = 4;

pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condp_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condc_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condVarProd = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condVarCons = PTHREAD_MUTEX_INITIALIZER;

void *consumidor();
void *productor();

int main(int argc, char *argv[]) {
    pthread_t prodHilo[max];            // Vector de hilos productor
    pthread_t consHilo[max];            // Vector de hilos consumidor
    for(int i = 0; i < max; i++) {
        // Creación de hilos y envío de función Productor o Consumidor
        pthread_create(&prodHilo[i], NULL, &productor, NULL);
        pthread_create(&consHilo[i], NULL, &consumidor, NULL);
    }
    for(int i = 0; i < max; i++) {
        pthread_join(prodHilo[i], NULL);
        pthread_join(consHilo[i], NULL);
    }
    return 0;
}
