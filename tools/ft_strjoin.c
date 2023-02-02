/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayache- <mayache-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:42:07 by mayache-          #+#    #+#             */
/*   Updated: 2023/02/02 16:16:43 by mayache-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*reue;
	size_t	lens1;
	size_t	lens2;

	if (!s1 || !s2)
		return (0);
	lens1 = strlen(s1);
	lens2 = strlen(s2);
	if (s1 && s2)
	{
		reue = (char *)malloc(lens2 + lens1 + 1);
		if (reue == NULL)
			return (NULL);
		strlcpy(reue, s1, lens1 + 1);
		strlcat(reue, s2, lens2 + lens1 + 1);
		return (reue);
	}
	return (0);
}
