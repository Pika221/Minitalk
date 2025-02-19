/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hialpagu <hialpagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:23:24 by hialpagu          #+#    #+#             */
/*   Updated: 2024/11/26 15:23:24 by hialpagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		nbr = -nbr;
		count += write (1, "-", 1);
		count += print_int(nbr);
	}
	else if (nbr > 9)
	{
		count += print_int(nbr / 10);
		count += print_int(nbr % 10);
	}
	else
		count += print_chr(nbr + 48);
	return (count);
}

int	print_uns(unsigned int nbr)
{
	int	count;

	count = 0;
	if (nbr > 9)
	{
		count += print_uns(nbr / 10);
		count += print_uns(nbr % 10);
	}
	else
		count += print_chr(nbr + 48);
	return (count);
}

int	print_hex(unsigned int nbr, char hex)
{
	int	count;

	count = 0;
	if (nbr >= 16)
	{
		count += print_hex(nbr / 16, hex);
	}
	if (nbr % 16 < 10)
		count += print_chr(nbr % 16 + 48);
	else
	{
		if (hex == 'x')
			count += print_chr(nbr % 16 + 87);
		else if (hex == 'X')
			count += print_chr(nbr % 16 + 55);
	}
	return (count);
}
