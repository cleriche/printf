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

#include "ft_printf.h"
//#include <unistd.h>
//#include <stdio.h>
//#include <stdarg.h>

static int	check_arg(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_putnbr_base(va_arg(ap, int), 10, 1);
	else if (specifier == 'x')
		count += ft_putnbr_base(va_arg(ap, unsigned int), 16, 0);
	else if (specifier == 'X')
		count += ft_putnbr_base(va_arg(ap, unsigned int), 16, 1);
	else if (specifier == 'u')
		count += ft_putnbr_base(va_arg(ap, unsigned int), 10, 1);
	else if (specifier == 'p')
		count += ft_putnbr_p(va_arg(ap, unsigned long), 16);
	else if (specifier == '%')
		count += write (1, "%", 1);
	else
		count += write (1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

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

/*int	main(void)
{
	int count;
	int	*p;
	int	n;

	n = 876;
	p = &n;

	count = ft_printf("Hello %s\n", "world");
	ft_printf("count = %d\n", count);

	count = printf("Hello %s\n", "world");
	printf("count = %d\n", count);

	printf("\n");

	count = ft_printf("int = %d\n", -2147483649);
	ft_printf("count = %d\n", count);

	count = printf("int = %d\n", -2147483649);
	printf("count = %d\n", count);

	printf("\n");

	count = ft_printf("i = %i\n", -87654);
	ft_printf("count = %d\n", count);

	count = printf("i = %i\n", -87654);
	printf("count = %d\n", count);

	printf("\n");

	count = ft_printf("x = %x\n", -76598);
	ft_printf("count = %d\n", count);

	count = printf("x = %x\n", -76598);
	ft_printf("count = %d\n", count);

	printf("\n");

	count = ft_printf("X = %X\n", -76598);
	ft_printf("count = %d\n", count);

	count = printf("X = %X\n", -76598);
	ft_printf("count = %d\n", count);

	printf("\n");

	count = ft_printf("p = %p\n", p);
	ft_printf("count = %d\n", count);

	count = printf("p = %p\n", p);
	printf("count = %d\n", count);

	printf("\n");

	count = ft_printf("u = %u\n", -8765);
	ft_printf("count = %d\n", count);

	count = printf("u = %u\n", -8765);
	printf("count = %d\n", count);

	printf("\n");

	count = ft_printf("100%%\n");
	ft_printf("%d\n", count);

	count = printf("100%%\n");
	printf("%d\n", count);

}*/
