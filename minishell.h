/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gebuqaj <gebuqaj@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 08:17:27 by gebuqaj           #+#    #+#             */
/*   Updated: 2024/06/05 10:20:29 by gebuqaj          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <limits.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>

//builtins
bool	is_builtin(char *input);
void	exec_builtin(char *input);
void	ft_echo(char **input);

//exec_ext
void	execute_external_command(const char *input);

//utils
void	free_tab(char **tab);
int size_of_tab(char **tab);


#endif