/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelbouss <aelbouss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 22:06:24 by aelbouss          #+#    #+#             */
/*   Updated: 2024/12/25 22:28:56 by aelbouss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_putstr(char *str)
{
	size_t	i;
	size_t	cnt;

	i = 0;
	cnt = 0;
	if (!str)
		return (ft_putstr ("(null)"));
	while (str[i])
	{
		write(1, &str[i], 1);
		cnt++;
		i++;
	}
	return (cnt);
}
