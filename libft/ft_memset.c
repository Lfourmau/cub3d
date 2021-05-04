/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:17:45 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 08:09:08 by lfourmau         ###   ########lyon.fr   */
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
