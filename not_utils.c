
#include "minishell.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int	get_size(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		;
	return (i);
}

char	**change_first_string(char **tab, char *str)
{
	char	**res;
	int		i;

	res = malloc(sizeof(char *) * (get_size(tab) + 1));
	if (!res)
		return (NULL);
	res[0] = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!res[0])
		return (NULL);
	res[0] = ft_strcpy(res[0], str);	
	i = 1;
	while (i < get_size(tab))
	{
		res[i] = malloc(sizeof(char) * (ft_strlen(tab[i]) + 1));
		if (!res[i])
			return (NULL);
		res[i] = ft_strcpy(res[i], tab[i]);
		i++;
	}
	res[i] = NULL;
	free_tab(tab);
	return (res);
}
