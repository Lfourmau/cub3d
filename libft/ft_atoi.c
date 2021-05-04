/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 11:16:57 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 08:06:30 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				j;
	unsigned long	res;
	int				sign;

	sign = 1;
	res = 0;
	i = 0;
	j = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + str[i++] - 48;
		j++;
	}
	if (res > 9223372036854775807 && sign == -1)
		return (0);
	else if (res > 9223372036854775807 && sign == 1)
		return (-1);
	return (res * sign);
}
