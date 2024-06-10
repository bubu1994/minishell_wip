/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:14:08 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/06/05 10:56:13 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*join_path_slash_input(char *path_rep, char *input)
{
	char	*res;
	char	*rep_slash;

	rep_slash = ft_strjoin(path_rep, "/");
	res = ft_strjoin(rep_slash, input);
	free(rep_slash);
	return (res);
}

/*
-input peut comprendre les options (ex. input = ls -l -a)
-n'interpréte pas les guillemets
*/
void	execute_external_command(const char *input)
{
	char	**input_tab;
	char	**path_tab;
	char	*path_to_exec;
	int		i;

	if (input[0] == '\0')
		return ;
	input_tab = ft_split(input, ' ');
	path_tab = ft_split(getenv("PATH"), ':');
	i = -1;
	while (path_tab[++i])
	{
		path_to_exec = join_path_slash_input(path_tab[i], input_tab[0]);
		if (access(path_to_exec, X_OK) == 0)
			execve(path_to_exec, input_tab, NULL);
		free(path_to_exec);
	}
	printf("minishell: %s: command not found\n", input_tab[0]);
	free_tab(input_tab);
	free_tab(path_tab);
}

/*
int main(int argc, char **argv)
{
	(void)argc;
	execute_external_command(argv[1]);
	return (0);
}
*/