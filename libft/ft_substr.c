/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:23:38 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 08:11:19 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if (len < 0)
		len *= -1;
	result = malloc(sizeof(char) * len + 1);
	if (result == NULL || s == 0)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
	{
		result[i] = 0;
		return (result);
	}
	s += start;
	while (*s && i < len)
	{
		result[i] = *s;
		i++;
		s++;
	}
	result[i] = 0;
	return (result);
}
