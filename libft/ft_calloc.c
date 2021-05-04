/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:17:22 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 08:06:38 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nbelements, size_t size)
{
	void	*ptr;

	ptr = malloc(size * nbelements);
	if (ptr == 0)
		return (NULL);
	ft_bzero(ptr, nbelements * size);
	return (ptr);
}
