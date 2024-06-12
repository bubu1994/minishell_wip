
#include "minishell.h"

int main(void)
{
	pid_t	pid;
	int		status;

	pid = fork();//renvoie '0' dans le processus fils et renvoie le pid du processus fils dans le processus parent
	if (pid == 0)//donc dans le processus fils
	{
		printf("fils: %d\n", pid);
		printf("fils: %d\n", getpid());
	}
	else if (pid != 0)
	{
		printf("parent est la\n");
	}
	printf("smack\n");
	
	return (0);
}