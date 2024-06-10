/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 18:24:26 by marvin            #+#    #+#             */
/*   Updated: 2024/06/03 18:24:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Ex: "   echo -n   ceci et cela", splitté par les espaces
void	ft_echo(char **input)
{
	int	i;

	if (!input[1])
		return ;
	if (!ft_strcmp(input[1], "-n"))
	{
		i = 2;
		while (input[i])
		{
			printf("%s", input[i]);
			if (i != size_of_tab(input) - 1)
				printf(" ");
			i++;
		}
	}
	else
	{
		i = 1;
		while (input[i])
		{
			printf("%s", input[i]);
			if (i != size_of_tab(input) - 1)
				printf(" ");
			else
				printf("\n");
			i++;
		}
	}
}

void	ft_cd(char **input)
{
	printf("%s TO CODE\n", input[0]);
}

void	ft_pwd(char **input)
{
	char	cwd[PATH_MAX];

	if (input[1] && input[1][0] == '-' && input[1][1] != ' ')
	{
		printf("minishell: pwd: -%c invalid option\n", input[1][1]);
		return ;
	}
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("(builtin)%s\n", cwd);//'(builtin)' a supprimer
	else
        printf("getcwd() error");
}

void	ft_export(char **input)
{
	printf("%s TO CODE\n", input[0]);
}

void	ft_unset(char **input)
{
	printf("%s TO CODE\n", input[0]);
}

void	ft_env(char **input)
{
	printf("%s TO CODE\n", input[0]);
}

void	ft_exit(char **input)
{
	printf("%s TO CODE\n", input[0]);
}

void	exec_builtin(char *input)
{
	char	**tab;

	tab = ft_split(input, ' ');
	if (!ft_strcmp(tab[0], "echo"))
		ft_echo(tab);
	else if (!ft_strcmp(tab[0], "cd"))
		ft_cd(tab);
	else if (!ft_strcmp(tab[0], "pwd"))
		ft_pwd(tab);
	else if (!ft_strcmp(tab[0], "export"))
		ft_export(tab);
	else if (!ft_strcmp(tab[0], "unset"))
		ft_unset(tab);
	else if (!ft_strcmp(tab[0], "env"))
		ft_env(tab);
	else if (!ft_strcmp(tab[0], "exit"))
		ft_exit(tab);
	else
		printf("error, builtin not executed\n");
	free_tab(tab);
}

bool	is_builtin(char *input)
{
	char	*blts[] = {"echo", "cd", "pwd", "export", "unset", "env", "exit"};
	char	**tab_input;
	int		i;

	tab_input = ft_split(input, ' ');
	i = 0;
	while (i <= 6)
	{
		if (!ft_strcmp(blts[i], tab_input[0]))
			return (true);
		i++;
	}
	free_tab(tab_input);
	return (false);
}
