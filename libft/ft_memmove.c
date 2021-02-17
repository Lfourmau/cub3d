/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 07:06:12 by lfourmau          #+#    #+#             */
/*   Updated: 2020/11/26 01:40:35 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;
	unsigned char	*cpy;
	unsigned char	*source;

	cpy = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst == 0 && src == 0)
		return (0);
	if (dst > src)
	{
		i = len;
		while (i-- > 0)
			cpy[i] = source[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			cpy[i] = source[i];
			i++;
		}
	}
	return (dst);
}
