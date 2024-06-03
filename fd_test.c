#include "minishell.h"

int main(void)
{
	int fd = open("mifile.txt", O_WRONLY | O_APPEND);
	int fd2 = open("./dossier/file.txt", O_RDONLY);
	printf ("%d, %d, %d, %d, %d\n", fd, fd2, STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
	write(0, "ca", 3);
	write(1, "la\n", 4);
	write(2, "ew", 3);//
	write(fd, "ciaoo", 6);
	close(fd);
	close(fd2);
	return (0);
}