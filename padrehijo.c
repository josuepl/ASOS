#include<stdlib.h>
#include<stdio.h>
void main(){
 int pida,pidb,pidc;
pida = fork();

if(pida == 0){// proceso hijo ha sido creado
  printf("Hijo A: Hola mundo,mi id es: %d el id de mi padre es %d\n ",getpid(),getppid());
  //printf("El proceso hijo tiene id: %d\n",pida);
 }
else {// bloque del código del proceso padre
	
  printf("Padre: el proceso hijo A tiene id: %d\n",pida); 
  printf("Padre: mi  id: %d\n",getpid());
  printf("Padre: el id de mi padre: %d\n",getppid());

  if((pidb=fork())== 0){//hijo B del proceso padre
  
  printf("Hijo B: Hola mundo,mi id es: %d el id de mi padre es %d\n ",getpid(),getppid());
  //printf("El proceso hijo tiene id: %d\n",pida);
  }
 else{
  printf("Padre: el proceso hijo B tiene id: %d\n",pidb); 
  printf("Padre: mi  id: %d\n",getpid());
  printf("Padre: el id de mi padre: %d\n",getppid());

  if((pidc=fork())== 0) //Hijo C del proceso padre
  {
  printf("Hijo C: Hola mundo,mi id es: %d el id de mi padre es %d\n ",getpid(),getppid());
  
  }
  else{
 
  printf("Padre: el proceso hijo C tiene id: %d\n",pidc); 
  printf("Padre: mi  id: %d\n",getpid());
  printf("Padre: el id de mi padre: %d\n",getppid());
   
   sleep(2);  
  } 
 }
 }
}
