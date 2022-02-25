/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:23:17 by samajat           #+#    #+#             */
/*   Updated: 2021/12/10 19:27:59 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *re);
void	ft_putnbr_int(int n, int *re);
void	ft_putstr(char *str, int *re);
size_t	ft_strlen(const char *str);
void	ft_putnbr_base(uintptr_t nbr, char *base, int *re);
void	ft_putnbr_uint(unsigned int n, int *re);

#endif
