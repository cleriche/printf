#include "ft_printf.h"

int	ft_putnbr_base(long n, int base, int is_uppercase)
{
	int		count;
	char	*symbols;

	count = 0;
	if (is_uppercase)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (n < 0 && base == 10)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n < 0)
		n = (unsigned int)n;
	if ((unsigned long)n >= (unsigned int)base)
		count += ft_putnbr_base(n / base, base, is_uppercase);
	write (1, &symbols[n % base], 1);
	return (count + 1);
}
