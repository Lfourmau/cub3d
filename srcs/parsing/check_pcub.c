/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pcub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 17:10:56 by loic              #+#    #+#             */
/*   Updated: 2021/05/09 17:13:46 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_cub(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i--;
	if (str[i] == 'b')
		i--;
	else
		return (1);
	if (str[i] == 'u')
		i--;
	else
		return (1);
	if (str[i] == 'c')
		i--;
	else
		return (1);
	if (str[i] == '.')
		i--;
	else
		return (1);
	return (0);
}
