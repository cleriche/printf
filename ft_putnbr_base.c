#include "ft_printf.h"

int	ft_putnbr_base(long n, int base, int is_uppercase)
{
	int	count;
	int	rec_count;
	char	*symbols_lower;
	char	*symbols_upper;
	char	*symbols;
		
	count = 0;
	symbols_lower = "0123456789abcdef";
	symbols_upper = "0123456789ABCDEF";
	if (is_uppercase)
		symbols = symbols_upper;
	else
		symbols = symbols_lower;	
	if (n < 0 && base == 10)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n < 0)
		n = (unsigned int)n;

	if ((unsigned long)n >= (unsigned int)base)
	{
		rec_count = ft_putnbr_base(n / base, base, is_uppercase);	
		count += rec_count;
	}
	write (1, &symbols[n % base], 1);
	return count + 1;
}

