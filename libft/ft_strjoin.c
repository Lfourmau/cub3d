/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:21:51 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 08:10:37 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *prefixe, char const *suffixe)
{
	char		*concat;
	int			len;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!prefixe && !suffixe)
		return (NULL);
	len = ft_strlen(prefixe) + ft_strlen(suffixe);
	if (!(concat = malloc(sizeof(char) * (len + 1))))
		return (NULL);
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
	concat[len] = 0;
	free((char *)prefixe);
	return (concat);
}
