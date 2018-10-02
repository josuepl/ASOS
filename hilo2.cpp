#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

struct datos_hilo {
   int  thread_id;
   char *texto;
};

void *imprime_hola(void *threadarg) {
   struct datos_hilo *mi_dato;
   mi_dato = (struct datos_hilo *) threadarg;

   cout << "Thread ID : " << mi_dato->thread_id ;
   cout << " Texto : " << mi_dato->texto << endl;

   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   struct datos_hilo dt[NUM_THREADS];
   int rc;
   int i;

   for( i = 0; i < NUM_THREADS; i++ ) {
      cout <<"main() : creaando hilo:  " << i << endl;
      dt[i].thread_id = i;
      dt[i].texto = "Este es el texto";
      rc = pthread_create(&threads[i], NULL, imprime_hola, (void *)&dt[i]);
      
      if (rc) {
         cout << "Error:No se ha podido crear el thread," << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}

