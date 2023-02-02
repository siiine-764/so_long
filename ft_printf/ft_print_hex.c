/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 19:12:00 by mayache-          #+#    #+#             */
/*   Updated: 2022/10/24 19:40:43 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printhex(unsigned int nbr, char hex, int *cnt)
{
	unsigned int	bass_len;
	char			*base;

	bass_len = 16;
	if (hex == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < bass_len)
		ft_putchr(base[nbr % bass_len], cnt);
	else
	{
		ft_printhex(nbr / bass_len, hex, cnt);
		ft_printhex(nbr % bass_len, hex, cnt);
	}
}
