/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hialpagu <hialpagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:23:13 by hialpagu          #+#    #+#             */
/*   Updated: 2024/11/26 15:23:13 by hialpagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	format(va_list args, char a)
{
	if (a == 'c')
		return (print_chr(va_arg(args, unsigned int)));
	if (a == 's')
		return (print_str(va_arg(args, char *)));
	if (a == 'p')
		return (print_ptr((unsigned long)va_arg(args, void *)));
	if (a == 'd' || a == 'i')
		return (print_int((long)va_arg(args, int)));
	if (a == 'u')
		return (print_uns(va_arg(args, unsigned int)));
	if (a == 'x' || a == 'X')
		return (print_hex(va_arg(args, unsigned int), a));
	return (0);
}

static int	check(const char *str, int i)
{
	if (str[i] == '%')
	{
		if (str[i + 1] == 'c' || str[i + 1] == 's' || str[i + 1] == 'p'
			|| str[i + 1] == 'd' || str[i + 1] == 'i' || str[i + 1] == 'u'
			|| str[i + 1] == 'x' || str[i + 1] == 'X' || str[i + 1] == '%')
			return (1);
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		res;

	i = 0;
	res = 0;
	va_start(args, s);
	while (s[i])
	{
		if (check(s, i))
		{
			if (s[i + 1] == '%')
				res += print_chr('%');
			else
				res += format(args, s[i + 1]);
			i++;
		}
		else
			res += print_chr(s[i]);
		i++;
	}
	va_end(args);
	return (res);
}
