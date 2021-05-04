/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 13:03:22 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 08:06:21 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inbase(char *base, char carac)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (carac == base[i])
			return (i);
		i++;
	}
	return (-1);
}

static int	ft_error(char *str)
{
	int	i;
	int	j;

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
		if (str[i] == '+' || str[i] == '-' || (str[i] >= 9 && str[i] <= 13)
			|| str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	res;
	int	pos;

	i = 0;
	res = 0;
	pos = 1;
	if (ft_error(base) == 1)
		return (0);
	while (ft_isspace(str[i]) == 1)
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			pos *= -1;
		i++;
	}
	while (ft_inbase(base, str[i]) != -1)
	{
		res = res * ft_strlen(base) + ft_inbase(base, str[i]);
		i++;
	}
	if (res)
		return (res * pos);
	return (0);
}
