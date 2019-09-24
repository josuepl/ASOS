#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUMERO_DE_HILOS 10

void *imprimir_hola_mundo(void *tid)
{
	/* Esta funcion imprime el identificador del hilo y después termina. */
	printf("Hola mundo. Saludos del hilo %d \n", tid);
	pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	/* El programa principal crea 10 hilos y después termina. */
	pthread_t hilos[NUMERO_DE_HILOS];
	int estado, i;
	for(i=0; i < NUMERO_DE_HILOS; i++) {
		printf("Aqui main. Creando hilo %d \n", i);
		//estado = pthread_create(&hilos[i], NULL, imprimir_hola_mundo, NULL);
		estado = pthread_create(&hilos[i], NULL, (void *)imprimir_hola_mundo, (void *)i);
		if (estado != 0) {
		printf("Ups. pthread_create devolvió el codigo de error %d \n", estado);
		exit(0);
		}
	}
exit(NULL);
}
