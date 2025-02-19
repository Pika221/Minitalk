/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hialpagu <hialpagu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:22:55 by hialpagu          #+#    #+#             */
/*   Updated: 2024/11/26 15:22:55 by hialpagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	print_chr(char c);
int	print_str(char *str);
int	print_ptr(unsigned long p);
int	print_int(long nbr);
int	print_uns(unsigned int nbr);
int	print_hex(unsigned int nbr, char hex);

#endif