#include <stdio.h>
#include <assert.h>
#include <pthread.h>

//compilacion condicional
#define __DEBUG 

void *IncrDecr(void *);

//la variable global y compartida
int x=0;

int main(int argc, char *argv[]) {
        pthread_t t0id,t1id;

        pthread_create(&t0id, NULL, IncrDecr, NULL);
        pthread_create(&t1id, NULL, IncrDecr, NULL);
#ifdef __DEBUG
        printf("Hilos Creados\n");
        printf("Inicio de sonda de testeo\n");
#endif
        //sonda que comprueba el Invariante
        while(1) {
                assert(0<=x && x<=2); // Inv: 0<=x<=2
                printf("%2d", x);
        }
        //aqui nunca llega
}


//componente del multiprograma
void *IncrDecr(void *arg)
{
int x =5;
#ifdef __DEBUG
        printf("Hilo IncrDecr iniciado\n");
#endif

        for (x;x > 0;x--) {
                x = x+1;
                x = x-1;
        }
}
