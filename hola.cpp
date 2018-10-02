#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
using namespace std;

int main(void){
pid_t pid;
int status;

 if((pid=fork())==0){
  //waitpid(pid2,&status2,0);
  cout<<"HIJO A: Hola soy el proceso Hijo con PID: "<<getpid()<<endl;
  cout<<"HIJO A: el pid de mi padre es: "<<getppid()<<endl;	
 }
 else{
  waitpid(pid, &status,0);
  cout<<"PADRE: Hola soy el proceso padre con PID: "<<getpid()<<endl;
  cout<<"PADRE: El pid de mi hijo es: "<<pid<<endl;
  pid_t pid2;
  int status2;
  if((pid2=fork())==0){
   cout<<"HIJOB: Hola soy el proceso hijo con PID: "<<getpid()<<endl;
   cout<<"HIJOB: EL PID de mi padre es: "<<getppid()<<endl;

  }
  else{
     //waitpid(pid, &status,0);
     waitpid(pid2, &status,0);
	pid_t pid3;
	int status3;
	if((pid3=fork())==0){
	cout<<"HIJOC: Hola soy el proceso hijo con PID: "<<getpid()<<endl;
        cout<<"HIJOC: EL PID de mi padre es: "<<getppid()<<endl;
		
	}
	else{
	waitpid(pid3,&status3,0);
   	cout<<"PADRE: Hola soy el proceso padre con PID: "<<getpid()<<endl;
   	cout<<"PADRE: El pid de mi hijo B es: "<<pid2<<endl;
  	}
 }


}
 cout<<"\n Hola mundo"<<endl;
}


