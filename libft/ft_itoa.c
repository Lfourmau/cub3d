/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:19:57 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 08:08:04 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbdigits_itoa(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	i++;
	return (i);
}

static char	*ft_recursive_itoa(long int nb, char *result, int index)
{
	if (nb >= 10)
		ft_recursive_itoa(nb / 10, result, index - 1);
	result[index - 1] = (nb % 10 + 48);
	return (result);
}

char	*ft_itoa(int nb)
{
	char		*result;
	int			index;
	long int	nbr;

	index = ft_nbdigits_itoa(nb);
	nbr = nb;
	result = malloc(sizeof(char) * ft_nbdigits_itoa(nbr) + 1);
	if (result == NULL)
		return (NULL);
	if (nbr < 0)
	{
		result[0] = '-';
		nbr *= -1;
	}
	result[index] = 0;
	ft_recursive_itoa(nbr, result, index);
	return (result);
}
