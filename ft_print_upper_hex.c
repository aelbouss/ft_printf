/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:06:06 by aelbouss          #+#    #+#             */
/*   Updated: 2024/12/25 22:44:06 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_print_upper_hex(unsigned int n)
{
	char	*hex;
	size_t	cnt;

	cnt = 0;
	hex = "0123456789ABCDEF";
	if (n >= 16)
		cnt += ft_print_upper_hex(n / 16);
	cnt += ft_putchar(hex[n % 16]);
	return (cnt);
}
