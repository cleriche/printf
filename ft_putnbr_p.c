#include "ft_printf.h"

int	ft_putnbr_p(unsigned long n, int base)
{
	int	count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += ft_putstr("0x");
	if (n >= (long unsigned)base)
		count += ft_putnbr_p(n / base, base);
	write(1, &symbols[n % base], 1);
	return (count + 1);

}
