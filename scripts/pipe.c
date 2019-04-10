#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
int main()
{
	int fd[2];
	char buffer[30];
	pipe(fd);
	if(!fork())
	{
		printf("HIJO: escribiendo en el PIPE\n");
		buffer[0]='h';
		buffer[1]='o';
		buffer[2]='l';
		buffer[3]='a';
		buffer[4]='.';
		buffer[5]='m';
		buffer[6]='u';
		write(fd[1], buffer, 7);
		printf("HIJO.... adios %s\n",buffer);
		sleep(3);
		read(fd[0],buffer,10);
		printf("HIJO he leido %s",buffer);
		exit(0);
	}
	else{
		sleep(2);
		printf("PADRE: leyendo desde pipe \n");
		read(fd[0], buffer, 7);
		printf("PADRE: he leido \%s \n", buffer);
		buffer[7]='n';
		buffer[8]='d';
		buffer[9]='o';
		write(fd[1], buffer, 10);
		printf("PADRE: he leido \%s \n", buffer);
		sleep(2);
	}
}
