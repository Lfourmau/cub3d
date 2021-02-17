/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:21:29 by lfourmau          #+#    #+#             */
/*   Updated: 2020/11/26 01:43:33 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	carac;

	i = 0;
	carac = (char)c;
	while (str[i])
	{
		if (str[i] == carac)
			return ((char*)&str[i]);
		i++;
	}
	if (carac == 0)
		return ((char *)&str[i]);
	return (0);
}
