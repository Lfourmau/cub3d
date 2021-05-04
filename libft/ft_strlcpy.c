/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:22:19 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 08:10:47 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (src == 0)
		return (0);
	while (src[i] && i < size - 1)
	{
		if (size > 0)
		{
			dest[i] = src[i];
		}
		i++;
	}
	if (size > 0)
		dest[i] = 0;
	while (src[i])
		i++;
	return (i);
}
