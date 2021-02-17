/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:22:53 by lfourmau          #+#    #+#             */
/*   Updated: 2020/11/29 15:23:44 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[j] == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] && haystack[i + j] == needle[j] && i + j < size)
			j++;
		if (needle[j] == 0)
			return ((char *)&haystack[i]);
		i++;
		j = 0;
	}
	return (0);
}
