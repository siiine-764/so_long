/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 21:12:39 by mayache-          #+#    #+#             */
/*   Updated: 2022/10/24 21:30:41 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer(unsigned long nbr, int *cnt)
{
	char	*bass;

	bass = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_print_pointer(nbr / 16, cnt);
		ft_print_pointer(nbr % 16, cnt);
	}
	else
	{
		ft_putchr(bass[nbr % 16], cnt);
	}
}
