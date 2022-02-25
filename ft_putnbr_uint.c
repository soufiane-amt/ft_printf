/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 21:14:07 by samajat           #+#    #+#             */
/*   Updated: 2021/12/08 17:45:24 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_uint(unsigned int n, int *re)
{
	unsigned int	div;
	unsigned int	rem;
	unsigned int	di;

	if (n < 10)
	{
		*re += 1;
		di = n + '0';
		write (1, &di, 1);
	}
	else if (n > 9)
	{
		rem = n % 10;
		div = n / 10;
		ft_putnbr_uint(div, re);
		ft_putnbr_uint(rem, re);
	}
}
