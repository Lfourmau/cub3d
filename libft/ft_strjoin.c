/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:21:51 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/07 07:09:23 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*fill_concat(const char *prefixe, const char *suffixe, char *concat)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i < ft_strlen(prefixe))
	{
		concat[i] = prefixe[i];
		i++;
	}
	while (j < ft_strlen(suffixe))
	{
		concat[i + j] = suffixe[j];
		j++;
	}
	return (concat);
}

char	*ft_strjoin(char const *prefixe, char const *suffixe)
{
	char		*concat;
	int			len;

	if (!prefixe && !suffixe)
		return (NULL);
	len = ft_strlen(prefixe) + ft_strlen(suffixe);
	concat = malloc(sizeof(char) * (len + 1));
	if (!concat)
		return (NULL);
	concat = fill_concat(prefixe, suffixe, concat);
	concat[len] = 0;
	free((char *)prefixe);
	return (concat);
}
