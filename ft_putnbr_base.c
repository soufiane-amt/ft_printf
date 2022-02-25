/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:52:20 by samajat           #+#    #+#             */
/*   Updated: 2021/12/08 17:36:28 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_duplicate_chars(char *base)
{
	uintptr_t	i;
	uintptr_t	j;

	i = 0;
	j = 0;
	while (*(base + i) && i < ft_strlen(base))
	{
		j = i + 1;
		while (*(base + j))
		{
			if (*(base + i) == *(base + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	base_is_valid(char *base)
{
	uintptr_t	i;

	i = 0;
	if (!(*base) || ft_strlen(base) == 1)
		return (0);
	if (ft_strlen(base) >= 2)
	{
		if (!check_duplicate_chars(base))
			return (0);
		i = 0;
		while (*(base + i))
		{
			if (*(base + i) == '+' || *(base + i) == '-')
				return (0);
			i++;
		}
	}
	return (1);
}

void	ft_putnbr_base(uintptr_t nbr, char *base, int *re)
{
	uintptr_t	len;

	len = ft_strlen(base);
	if (base_is_valid(base))
	{
		if (nbr > len - 1)
		{
			ft_putnbr_base(nbr / len, base, re);
			ft_putnbr_base(nbr % len, base, re);
		}
		else
		{
			write (1, base + nbr, 1);
			*re += 1;
		}
	}
}
