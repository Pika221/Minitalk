/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <hialpagu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:35:22 by hialpagu          #+#    #+#             */
/*   Updated: 2025/03/01 15:53:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_chr(char c)
{
	write (1, &c, 1);
	return (1);
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		count += write (1, "(null)", 6);
		return (count);
	}
	while (*str)
		count += write (1, str++, 1);
	return (count);
}

int	print_ptr(unsigned long p)
{
	int		count;
	char	*hex;
	char	value[16];
	int		i;

	i = 0;
	hex = "0123456789abcdef";
	count = 0;
	if (p == 0)
		return (print_str("(nil)"));
	count += write (1, "0x", 2);
	while (p > 0)
	{
		value[i] = hex[p % 16];
		p /= 16;
		i++;
	}
	while (i-- > 0)
		count += print_chr(value[i]);
	return (count);
}
