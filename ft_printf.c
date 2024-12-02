/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cleriche <cleriche@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 10:36:51 by cleriche          #+#    #+#             */
/*   Updated: 2024/12/02 15:07:47 by cleriche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(int c)
{
	return write (1, &c, 1);
}

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

int	ft_putnbr_base(int n, int base, int is_uppercase)
{
	int	count;
	int	rec_count;
	char	*symbols_lower;
	char	*symbols_upper;
	char	*symbols;
	long	nb;
	
	count = 0;
	nb = n;
	symbols_lower = "0123456789abcdef";
	symbols_upper = "0123456789ABCDEF";
	if (is_uppercase)
		symbols = symbols_upper;
	else
		symbols = symbols_lower;	
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
		count++;
	}
	if (nb >= base)
	{
		int rec_count = ft_putnbr_base(nb / base, base, is_uppercase);	
		count += rec_count;
	}
	write (1, &symbols[nb % base], 1);
	return count + 1;
}

int	check_arg(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count+= ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr(va_arg(ap, int), 10);
	else if (specifier == 'x')
		count += ft_putnbr(va_arg(ap, unsigned int), 16);
	else if (specifier == 'X')
		count += ft_putnbr(va_arg(ap, unsigned int), 16);
	else if (specifier == 'u')
		count += ft_putnbr(va_arg(ap, unsigned int), 10);
	else if (specifier == 'p')
		count += ft_putnbr(va_arg(ap, unsigned int), 16);
	else if (specifier == '%')
		count += write (1, "%", 1);
	else	count += write (1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			count += check_arg(*format, ap);
		}
		else
			count += write(1, format, 1);
		++format;	
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int count;
	count = ft_printf("Hello %s\n", "world");
	ft_printf("count = %d\n", count);

	count = printf("Hello %s\n", "world");
	printf("count = %d\n", count);
}
