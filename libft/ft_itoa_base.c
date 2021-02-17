/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 09:49:37 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/17 09:54:39 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(long long int nb, char *base)
{
	int i;

	i = 0;
	if (nb < 0)
		nb = -nb;
	while (nb >= (long int)ft_strlen(base))
	{
		nb /= (long int)ft_strlen(base);
		i++;
	}
	i++;
	return (i);
}

static void		ft_recursive(long long int nb, char *str, char *base, int index)
{
	if (nb >= (long int)ft_strlen(base))
		ft_recursive(nb / (long int)ft_strlen(base), str, base, index - 1);
	str[index] = base[nb % (long int)ft_strlen(base)];
}

char			*ft_itoa_base(long long int nb, char *base)
{
	char	*str;
	int		index;

	index = ft_count(nb, base);
	if (!(str = malloc(sizeof(char) * (index + 1))))
		return (NULL);
	if (nb < 0)
		nb = -nb;
	str[index] = 0;
	ft_recursive(nb, str, base, index - 1);
	return (str);
}
