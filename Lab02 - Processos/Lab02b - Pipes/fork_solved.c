#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int value = 5;

int main()
{
  pid_t pid;
  int fd[2];
  
  if(pipe(fd) < 0){
    printf("n foi");
  }
  pid = fork();

  if (pid == 0) { /* child process */
  	printf("Entrei no filho!\n");
	value += 15;
    	write(fd[1], &value, sizeof(value));
	printf ("CHILD: value = %d\n",value); /* LINE A */
	return 0;
  }
  else if (pid > 0) { /* parent process */
    	wait(NULL);
    	read(fd[0], &value, sizeof(value));
	printf ("PARENT: value = %d\n",value); /* LINE A */
	return 0;
  }
}
