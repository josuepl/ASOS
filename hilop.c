#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float pot, div2;
void potencia(int *argv){
	float z=1;
	int i=0;
	printf("Thread %x \n",pthread_self());	//Se imprime el Id. del Hilo creado
	if(argv[2]==0)
		z = 1;
	else
	for(i=0; i < argv[2];i++)
	//z=powf((argv[1]),(argv[2]));
	z = z*argv[1];
	printf("Potencia %f\n",z);
	pot = z;
	pthread_exit(NULL);	//Finaliza la ejecucion del hilo

}

void division(int *argv){
	float w;
	printf("Thread %x\n",pthread_self());
	if(argv[2]==0)
		printf("No se puede realizar operacion\n");	//Se imprime el Id. del Hilo creado
	else{
		w=((float)(argv[1])) / ((float)(argv[2]));
		printf("Divison: %.4f\n",w);
		div2 = w;
	}

	pthread_exit(NULL);	//Finaliza la ejecucion del hilo
}

int main(int argc, char *argv[]){
	int i,h[3],j[3];
	pthread_t th1,th2;	//Direccion donde se almacenaran los identificadores de los hilos

	if(argc <= 1){
		printf("DEBES INTRODUCIR DOS NUMEROS");
		printf("\nEjemplo: \n./Salida 42 2\n");
	}
	else{
		for(i=1;i<argc;i++)
			h[i]=atoi(argv[i]);
			//Se crea el Hilo para ejecutar la funcion Potencia

		sleep(5);
		pthread_create(&th2,NULL,(void*)division,&h);
	//Se crea el Hilo para ejecutar la funcion Division

		sleep(3);
		pthread_create(&th1,NULL,(void*)potencia,&h);
		pthread_join(th1,NULL);	//Se espera a que finalice el hilo
		pthread_join(th2,NULL);	//Se espera a que finalice el hilo
	}
	printf("La potencia es %f: \n",pot);
	printf("La division es %f: \n",div2);
	return(0);
}

