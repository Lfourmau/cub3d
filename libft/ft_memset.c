/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:17:45 by lfourmau          #+#    #+#             */
/*   Updated: 2020/11/26 01:55:39 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memzone, int octet, size_t len)
{
	size_t	i;
	char	*tab;

	i = 0;
	tab = memzone;
	while (i < len)
	{
		tab[i] = octet;
		i++;
	}
	memzone = tab;
	return (memzone);
}
