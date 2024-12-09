#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		ft_putchar((int)str[i]);
		i++;
	}
	return (i);
}
