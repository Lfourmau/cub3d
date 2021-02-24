/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:13:52 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/24 14:11:27 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int valid_extrem_lines(char **map)
{
	int i;
	int nb_splits;

	i = 0;
	nb_splits = number_of_split(map);
	while (map[0][i] && (map[0][i] == ' ' || map[0][i] == '1'))
		i++;
	if (map[0][i] != 0)
		return (1);
	i = 0;
	while (map[nb_splits - 1][i] && (map[nb_splits - 1][i] == ' ' || map[nb_splits - 1][i] == '1'))
		i++;
	if (map[nb_splits - 1][i] != 0)
		return (1);
	return (0);
}

int valid_middle_lines(char **map)
{
	int i;
	int j;
	int nb_splits;

	i = 1;
	nb_splits = number_of_split(map);
	while (i < nb_splits - 1) //i - 1 car extremites deja check
	{
		j = 0;
		while (ft_isspace(map[i][j]))
			j++;
		if (map[i][j] != '1')
			return (1);
		while (map[i][j])
			j++;
		j--;
		while (ft_isspace(map[i][j]))
			j--;
		if (map[i][j] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	map_isclose(char **map)
{
	if (valid_extrem_lines(map))
		return (1);
	if (valid_middle_lines(map))
		return (1);
	return (0);
}