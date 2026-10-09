/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lower_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:05:59 by aelbouss          #+#    #+#             */
/*   Updated: 2024/12/25 22:42:38 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_print_lower_hex(unsigned int n)
{
	char	*hex;
	int		cnt;

	cnt = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		cnt += ft_print_lower_hex(n / 16);
	cnt += ft_putchar(hex[n % 16]);
	return (cnt);
}
