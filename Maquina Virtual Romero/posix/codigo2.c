/* 
Nombre: Juan Diego Romero
Materia: Sistemas Operativos
Tema: POSIX
Descripción: Este programa implementa un modelo productor-consumidor usando hilos y sincronización con POSIX en C. 
El productor incrementa un contador hasta un límite de 10 y espera si se alcanza, mientras que el consumidor lo decrementa 
cuando es mayor que 0. Ambos hilos usan variables de condición y mutex para coordinarse y evitar condiciones de carrera.
*/

void *productor() {
    while(1) {
        pthread_mutex_lock(&condp_mutex);
        while(counter >= 10) 
            pthread_cond_wait(&condVarProd, &condp_mutex);
        pthread_mutex_unlock(&condp_mutex);

        pthread_mutex_lock(&counter_mutex);
        counter++;
        pthread_cond_signal(&condVarCons);
        printf("Soy el PRODUCTOR %d || Contador = %d\n", pthread_self(), counter);
        pthread_mutex_unlock(&condp_mutex);
        pthread_mutex_unlock(&counter_mutex);

        if(counter > 7)
            sleep(4);
    }
}

void *consumidor() {
    while(1) {
        sleep(1);
        pthread_mutex_lock(&condc_mutex);
        while(counter <= 0) {
            pthread_cond_signal(&condVarProd);
            pthread_cond_wait(&condVarCons, &condc_mutex);
        }
        pthread_mutex_unlock(&condc_mutex);

        pthread_mutex_lock(&counter_mutex);
        if(counter > 0) {
            printf("Soy el CONSUMIDOR %d || Contador = %d\n", pthread_self(), counter);
            counter--;
            pthread_cond_signal(&condVarProd);
        }
        pthread_mutex_unlock(&counter_mutex);
        pthread_mutex_unlock(&condc_mutex);
    }
}
