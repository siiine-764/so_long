/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:37:12 by mayache-          #+#    #+#             */
/*   Updated: 2022/10/24 21:36:05 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_form_int(va_list ar, const char str)
{
	int	len;
	int	cnt;

	len = 0;
	cnt = 0;
	if (str == 'i' || str == 'd')
	{
		ft_putnbr(va_arg(ar, int), &cnt);
		len += cnt;
	}
	else if (str == 'u')
	{
		ft_unsigned_int(va_arg(ar, unsigned int), &cnt);
		len += cnt;
	}
	else if (str == 'x' || str == 'X')
	{
		ft_printhex(va_arg(ar, unsigned int), str, &cnt);
		len += cnt;
	}
	return (len);
}

int	ft_form(va_list ar, const char str)
{
	int	len;
	int	cnt;

	len = 0;
	cnt = 0;
	if (str == 'c')
		len += ft_putchr(va_arg(ar, int), 0);
	else if (str == 'p')
	{
		cnt += ft_putstr("0x");
		ft_print_pointer(va_arg(ar, unsigned long), &cnt);
		len += cnt;
	}
	if (str == 's')
		len += ft_putstr(va_arg(ar, char *));
	else if (str == '%')
		len += ft_putchr('%', 0);
	else
		len += ft_form_int(ar, str);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	ar;

	len = 0;
	i = 0;
	va_start(ar, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			len += ft_form(ar, str[i]);
		}
		else
			len += ft_putchr(str[i], 0);
		i++;
	}
	va_end(ar);
	return (len);
}
