/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 10:57:29 by lfourmau          #+#    #+#             */
/*   Updated: 2021/01/04 11:02:55 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_putnbr(char *str)
{
	int a;

	a = 0;
	while (str[a])
	{
		a++;
	}
	return (a);
}

static int	ft_error(char *str)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(str) == 0 || ft_strlen(str) == 1)
		return (1);
	while (str[i])
	{
		j = i + 1;
		while (str[i] != str[j] && str[j])
			j++;
		if (str[i] == str[j])
			return (1);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

void		ft_putnbr_base(int nbr, char *base)
{
	long int nb;

	if (!ft_error(base))
	{
		nb = nbr;
		if (nb < 0)
		{
			ft_putchar_fd(1, '-');
			nb = nb * -1;
		}
		if (nb < ft_strlen_putnbr(base))
			ft_putchar_fd(1, base[nb]);
		else
		{
			ft_putnbr_base(nb / ft_strlen(base), base);
			ft_putnbr_base(nb % ft_strlen(base), base);
		}
	}
}
