/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:21:04 by lfourmau          #+#    #+#             */
/*   Updated: 2020/11/26 01:54:57 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*string1;
	unsigned char	*string2;

	i = 0;
	string1 = (unsigned char*)str1;
	string2 = (unsigned char*)str2;
	while (i < n)
	{
		if (*string1 != *string2)
			return (*string1 - *string2);
		string1++;
		string2++;
		i++;
	}
	return (0);
}
