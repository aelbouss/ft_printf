/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:06:21 by aelbouss          #+#    #+#             */
/*   Updated: 2024/12/25 22:45:48 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "printf.h"

size_t	ft_putnbr(int n)
{
	size_t	cnt;

	cnt = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		cnt += ft_putchar('-');
		n *= -1 ;
	}
	if (n > 9)
		cnt += ft_putnbr(n / 10);
	cnt += ft_putchar(n % 10 + '0');
	return (cnt);
}
