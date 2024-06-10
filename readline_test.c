
#include "minishell.h"

int main(void)
{
	char *input;

	input = readline("--->");
	printf("%s\n", input);
	if (!ft_strcmp(input, " "))
		printf("1 seul ESPACE\n");
	return (0);
}