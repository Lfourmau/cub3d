/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:21:29 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 08:10:27 by lfourmau         ###   ########lyon.fr   */
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
			return ((char *)&str[i]);
		i++;
	}
	if (carac == 0)
		return ((char *)&str[i]);
	return (0);
}
