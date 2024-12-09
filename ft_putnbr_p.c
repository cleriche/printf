#include "ft_printf.h"

static int	ft_putnbr_recurs(unsigned long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	count = 0;
	if (n >= (unsigned long)base)
		count += ft_putnbr_recurs(n / base, base);
	write(1, &symbols[n % base], 1);
	return (count + 1);
}

int	ft_putnbr_p(unsigned long n, int base)
{
	int	count;

	count = 2;
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_putstr("0x");
	count += ft_putnbr_recurs(n, base);
	return (count);
}
