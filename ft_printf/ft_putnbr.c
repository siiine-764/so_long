/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:10:11 by mayache-          #+#    #+#             */
/*   Updated: 2022/10/24 19:41:25 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(long n, int *cnt)
{
	unsigned int	nbr;

	nbr = n;
	if (n < 0)
	{
		nbr = n * -1;
		ft_putchr('-', cnt);
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10, cnt);
		ft_putnbr(nbr % 10, cnt);
	}
	else
		ft_putchr(nbr + 48, cnt);
}
