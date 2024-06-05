/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:09:45 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/06/05 10:51:30 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


/*
-n'execute pas nos propres executables (./a.out :command not found: a.out)

-attention aux esapces dans l'input, qui est splitté par un espace..(->segfault)
*/

int	main(void)
{
	char		*prompt = "\033[1;31m$> \033[0m";
	char		*input;
	pid_t		pid;
	int			status;

	while (1)
	{
		input = readline(prompt);//retourne NULL si EOF (ctrl-d)
		if (input == NULL)
		{
			printf("exit\n");
			break ;
		}
		if (input[0] != '\0')
		{
			if (is_builtin(input))
				exec_builtin(input);
			else
			{
				pid = fork();
				if (pid == 0)
				{
					execute_external_command(input);
					break ;
				}
				wait(&status);
			}
			add_history(input);
		}
		rl_on_new_line();
		free(input);
	}
	return (0);
}
