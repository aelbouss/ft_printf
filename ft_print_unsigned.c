/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:06:02 by aelbouss          #+#    #+#             */
/*   Updated: 2024/12/25 22:26:58 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_print_unsigned(unsigned int n)
{
	static size_t	cnt;

	cnt = 0;
	if (n < 10)
	{
		cnt += ft_putchar(n + '0');
		return (cnt);
	}
	else
	{
		ft_print_unsigned(n / 10);
		cnt += ft_putchar(n % 10 + '0');
	}
	return (cnt);
}
