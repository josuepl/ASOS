#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 5

void *imprime(void *threadid) {
   int tid;
   tid = (int)threadid;
   cout << "Hola Mundo. ID: " <<tid << endl;
   pthread_exit(NULL);
}

int main () {
   pthread_t threads[NUM_THREADS];
   int rc;
   int i;
   
   for( i = 0; i < NUM_THREADS; i++ ) {
      cout << "main() : ha creado un hilo: " << i << endl;
      rc = (int)pthread_create(&threads[i], NULL, imprime, (void *)i);
      
      if (rc) {
         cout << "Error:No se ha podido crear un hilo..." << rc << endl;
         exit(-1);
      }
   }
   pthread_exit(NULL);
}
