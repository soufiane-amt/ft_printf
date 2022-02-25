/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samajat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:01:41 by samajat           #+#    #+#             */
/*   Updated: 2021/12/08 17:43:18 by samajat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	min_integer(int m, int *re)
{
	if (m == -2147483648)
	{
		write (1, "-2147483648", 11);
		*re += 11;
	}
}

void	ft_putnbr_int(int n, int *re)
{
	int	div;
	int	rem;
	int	di;

	min_integer(n, re);
	if (n < 0 && n != -2147483648)
	{
		write (1, "-", 1);
		*re += 1;
		n = n * (-1);
		ft_putnbr_int(n, re);
	}
	else if (n < 10 && n >= 0)
	{
		di = n + '0';
		*re += 1;
		write (1, &di, 1);
	}
	else if (n > 9)
	{
		rem = n % 10;
		div = n / 10;
		ft_putnbr_int(div, re);
		ft_putnbr_int(rem, re);
	}
}
/*int main()
{
	ft_putnbr(0);
    return 0;
}*/
