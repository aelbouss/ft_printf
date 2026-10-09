/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:05:50 by aelbouss          #+#    #+#             */
/*   Updated: 2024/12/25 23:12:26 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	_hex(unsigned long int n)
{
	static int	cnt;
	char		*hex;

	cnt = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		_hex(n / 16);
	}
	cnt += ft_putchar(hex[n % 16]);
	return (cnt);
}

size_t	ft_print_address(void *address)
{
	unsigned long int	add;
	size_t				cnt;

	if (!address)
		return (ft_putstr ("(nil)"));
	cnt = 0;
	add = (unsigned long int)address;
	cnt += ft_putstr("0x");
	cnt += _hex(add);
	return (cnt);
}
