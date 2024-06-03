
#include "philo.h"

int main(void)
{
	int i = 0;

	while (i < 10)
	{
		if (i == 5)
		{
			break ;
		}
		i++;
	}
	printf("%d\n", i);
	return (0);
}