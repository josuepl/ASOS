#include <pthread.h>
#include <stdio.h>
#include <math.h>

float pot, div; // variables globales 
int bandera;
float resultado;
void potencia(int *argv){
	while(1){
		if (bandera == 2){
			sleep(2);
		}
		else{
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
		resultado = pot;
		bandera = 2;
		pthread_exit(NULL);	//Finaliza la ejecucion del hilo
	}
	}
}

void division(int *argv){

	while(1){
	if (bandera == 1){
	sleep(2);
	}

	else{
	
	 float w;
	 printf("Thread %x\n",pthread_self());
	 if(argv[2]==0)
		printf("No se puede realizar operacion\n");	//Se imprime el Id. del Hilo creado
	 else{
		w=((float)(argv[1])) / ((float)(argv[2]));
		printf("Divison: %.4f\n",w); 
		div = w;
 		resultado = div;
	 }
	bandera = 1;
	 pthread_exit(NULL);	//Finaliza la ejecucion del hilo
	}
	}
}
int main(int argc, char *argv[]){
	int i,h[3],j[3];
	pthread_t th1,th2;	//Direccion donde se almacenaran los identificadores de los hilos

	if(argc <= 1){
		printf("DEBES INTRODUCIR DOS NUMEROS");
		printf("\nEjemplo: \n./Salida 42 2\n");
	}
	else{
		for(i=1;i<argc;i++){
			h[i]=atoi(argv[i]);
			j[i]=h[i];
			}
	if (h[1]< h[2]) bandera = 1;
	else bandera = 2;
	
	pthread_create(&th1,NULL,(void*)potencia,&h);
	//Se crea el Hilo para ejecutar la funcion Potencia

	pthread_create(&th2,NULL,(void*)division,&h);
	//Se crea el Hilo para ejecutar la funcion Division

		pthread_join(th1,NULL);	//Se espera a que finalice el hilo
		pthread_join(th2,NULL);	//Se espera a que finalice el hilo
		//pthread_join(th1,NULL);	//Se espera a que finalice el hilo
	}
	sleep(4);
	printf("La potencia es %f: \n",pot);
	printf("La division es %f: \n",div);
	printf("Resultado es %f: \n",resultado);
	return(0);
}

