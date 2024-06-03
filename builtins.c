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

void	ft_echo(char *input)
{
	printf("%s\n", input);
}

void	ft_cd(char *input)
{
	printf("%s TO CODE\n", input);
}

void	ft_pwd(char *input)
{
	printf("%s TO CODE\n", input);
}

void	ft_export(char *input)
{
	printf("%s TO CODE\n", input);
}

void	ft_unset(char *input)
{
	printf("%s TO CODE\n", input);
}

void	ft_env(char *input)
{
	printf("%s TO CODE\n", input);
}

void	ft_exit(char *input)
{
	printf("%s TO CODE\n", input);
}

void	exec_builtin(char *input)
{
	if (!ft_strncmp(input, "echo", 4))
		ft_echo(input + 5);
	else if (!ft_strncmp(input, "cd", 2))
		ft_cd(input);
	else if (!ft_strncmp(input, "pwd", 2))
		ft_pwd(input);
	else if (!ft_strncmp(input, "export", 2))
		ft_export(input);
	else if (!ft_strncmp(input, "unset", 2))
		ft_unset(input);
	else if (!ft_strncmp(input, "env", 2))
		ft_env(input);
	else if (!ft_strncmp(input, "exit", 2))
		ft_exit(input);
}

bool	is_builtin(char *input)
{
	char	*blts[] = {"echo", "cd", "pwd", "export", "unset", "env", "exit"};
	int		i;

	i = 0;
	while (i <= 6)
	{
		if (!ft_strcmp(blts[i], input))
			return (true);
		i++;
	}
	return (false);
}
