
#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	printf("%s\n", env[0]);

	return (0);
}
