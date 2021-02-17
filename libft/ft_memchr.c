/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:20:52 by lfourmau          #+#    #+#             */
/*   Updated: 2020/11/30 02:38:50 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*string;
	size_t			i;
	unsigned char	carac;

	i = 0;
	string = (unsigned char*)str;
	carac = (unsigned char)c;
	while (i < n)
	{
		if (string[i] == carac)
			return ((void *)&string[i]);
		i++;
	}
	return (NULL);
}
