/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:19:30 by lfourmau          #+#    #+#             */
/*   Updated: 2020/11/26 01:37:14 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int nbr)
{
	unsigned char nb;

	nb = (unsigned char)nbr;
	if (nbr <= 31 || nbr >= 127)
		return (0);
	return (1);
}
