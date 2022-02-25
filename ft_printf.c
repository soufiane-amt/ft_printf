/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:22:30 by samajat           #+#    #+#             */
/*   Updated: 2021/12/10 19:24:34 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_specifier(char current_char, char next_char)
{
	if (current_char == '%' && next_char
		&& (next_char == 'd' || next_char == 's' || next_char == 'c'
			|| next_char == 'p' || next_char == 'i' || next_char == 'u'
			|| next_char == 'x' || next_char == 'X' || next_char == '%'))
		return (1);
	return (0);
}

void	print(va_list list, char c, int *re)
{
	uintptr_t	n;

	if (c == 's')
		ft_putstr(va_arg(list, char *), re);
	if (c == 'd' || c == 'i')
		ft_putnbr_int(va_arg(list, int), re);
	if (c == 'c')
		ft_putchar(va_arg(list, int), re);
	if (c == 'p')
	{
		n = (uintptr_t)va_arg(list, void *);
		ft_putstr("0x", re);
		ft_putnbr_base(n, "0123456789abcdef", re);
	}
	if (c == 'u')
		ft_putnbr_uint(va_arg(list, unsigned int), re);
	if (c == 'x')
		ft_putnbr_base(va_arg(list, unsigned int), "0123456789abcdef", re);
	if (c == 'X')
		ft_putnbr_base(va_arg(list, unsigned int), "0123456789ABCDEF", re);
	if (c == '%')
		ft_putchar('%', re);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	va_list	list;
	int		returned;

	returned = 0;
	j = 0;
	va_start(list, format);
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			ft_putchar(format[i], &returned);
		else if (is_specifier(format[i], format[i + 1]))
		{
			print(list, format[i + 1], &returned);
			i++;
		}
		i++;
	}
	va_end(list);
	return (returned);
}
