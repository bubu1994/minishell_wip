
#include "minishell.h"

char	*join_path_slash_input(char *path_rep, char *input)
{
	char	*rep_slash;
	char	*res;

	rep_slash = ft_strjoin(path_rep, "/");
	res = ft_strjoin(rep_slash, input);
	free(rep_slash);
	printf("res: %s, input: %s\n", res, input);
	return (res);
}

int	main()
{
	char *path = getenv("PATH");

	char **path_tab =  ft_split(path, ':');

	printf("dossier du path: %s\n", path_tab[5]);
	char *commande = join_path_slash_input(path_tab[5], "ls");
	printf("commande: %s\n", commande);

	return (0);
}