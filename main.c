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
*/

void	exe_command(char *input)
{
	pid_t	pid;
	int		status;

	if (is_builtin(input))
		exec_builtin(input);
	else
	{
		pid = fork();
		if (pid == 0)
			execute_external_command(input);
		wait(&status);
	}
	add_history(input);
}

void	parsing(char *input)//input du prompt, de l'user
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(input, '|');
	
	exe_command(tab[0]);
	free_tab(tab);
}
/*PIPE
Le pipe (|) redirige cette sortie standard de la première commande (ls -l) vers
l'entrée standard (stdin) de la commande suivante (grep "txt").
Au lieu de voir la sortie de ls -l directement dans le terminal, cette sortie
est "pipelée" vers grep.
Bash utilise des descripteurs de fichiers pour gérer la redirection. Chaque
processus a des descripteurs pour l'entrée standard (stdin, descripteur 0), la
sortie standard (stdout, descripteur 1), et l'erreur standard (stderr, descripteur 2).
Le processus de la première commande (ls -l) écrit sa sortie dans le pipe, et le
processus de la deuxième commande (grep "txt") lit cette entrée depuis le pipe.
LE PIPE EST UN CANAL DE COMMUNICATION ENTRE DEUX PROCESSUS. Un canal a une entrée
et une sortie! lol
*/

int	main(void)
{
	char		*prompt = "\033[1;31m$> \033[0m";
	char		*input;

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
			parsing(input);
		}
		rl_on_new_line();
		free(input);
	}
	return (0);
}
