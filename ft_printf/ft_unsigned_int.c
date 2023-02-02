/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:18:09 by mayache-          #+#    #+#             */
/*   Updated: 2022/10/24 19:42:41 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_unsigned_int(unsigned int n, int *cnt)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10, cnt);
		ft_putnbr(n % 10, cnt);
	}
	else
		ft_putchr(n + 48, cnt);
}
