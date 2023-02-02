/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 15:13:36 by mayache-          #+#    #+#             */
/*   Updated: 2022/10/24 21:38:45 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	cnt;

	cnt = 0;
	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
		cnt += ft_putchr(s[i++], 0);
	return (cnt);
}
