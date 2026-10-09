/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 23:03:55 by aelbouss          #+#    #+#             */
/*   Updated: 2024/12/26 14:02:02 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	flags_handling(va_list ap, int i, const char *format)
{
	size_t	cnt;

	cnt = 0;
	if (format[i + 1] == 'd' || format[i + 1] == 'i')
		cnt += ft_putnbr(va_arg(ap, int));
	else if (format[i + 1] == 's')
		cnt += ft_putstr(va_arg(ap, char *));
	else if (format[i + 1] == 'x')
		cnt += ft_print_lower_hex(va_arg(ap, unsigned int));
	else if (format[i + 1] == 'X')
		cnt += ft_print_upper_hex(va_arg(ap, unsigned int));
	else if (format[i + 1] == 'c')
		cnt += ft_putchar(va_arg(ap, int));
	else if (format[i + 1] == '%')
		cnt += ft_putchar('%');
	else if (format[i + 1] == 'u')
		cnt += ft_print_unsigned(va_arg(ap, unsigned int));
	else if (format[i + 1] == 'p')
		cnt += ft_print_address(va_arg(ap, void *));
	else if (format[i + 1] == '\n')
		cnt += ft_putchar('%');
	return (cnt);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	count = 0;
	i = 0 ;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			count += flags_handling(ap, i, format);
			i++;
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (count);
}
