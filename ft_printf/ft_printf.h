/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 13:37:24 by mayache-          #+#    #+#             */
/*   Updated: 2022/10/24 21:37:55 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchr(char c, int *cnt);
int		ft_putstr(char *s);
void	ft_putnbr(long n, int *cnt);
void	ft_printhex(unsigned int nbr, char hex, int *cnt);
void	ft_print_pointer(unsigned long nbr, int *cnt);
void	ft_unsigned_int(unsigned int n, int *cnt);
#endif
