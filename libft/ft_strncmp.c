/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:22:43 by lfourmau          #+#    #+#             */
/*   Updated: 2020/11/26 01:48:48 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*strcast1;
	unsigned char	*strcast2;
	size_t			i;

	strcast1 = (unsigned char *)str1;
	strcast2 = (unsigned char *)str2;
	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if (strcast1[i] != strcast2[i])
			return (strcast1[i] - strcast2[i]);
		i++;
	}
	return (0);
}
