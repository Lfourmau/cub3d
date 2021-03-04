/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_close_spawn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:13:52 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/03 17:43:19 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int valid_extrem_lines(map_struct *ms)
{
	int i;
	int nb_splits;

	i = 0;
	nb_splits = number_of_split(ms->map);
	while (ms->map[0][i] && (ms->map[0][i] == ' ' || ms->map[0][i] == '1'))
		i++;
	if (ms->map[0][i] != 0)
		return (1);
	i = 0;
	while (ms->map[nb_splits - 1][i] && (ms->map[nb_splits - 1][i] == ' ' || ms->map[nb_splits - 1][i] == '1'))
		i++;
	if (ms->map[nb_splits - 1][i] != 0)
		return (1);
	return (0);
}

int valid_middle_lines(map_struct *ms)
{
	int i;
	int j;
	int nb_splits;

	i = 1;
	nb_splits = number_of_split(ms->map);
	while (i < nb_splits - 1) //i - 1 car extremites deja check
	{
		j = 0;
		while (ft_isspace(ms->map[i][j]))
			j++;
		if (ms->map[i][j] != '1')
			return (1);
		while (ms->map[i][j])
			j++;
		j--;
		while (ft_isspace(ms->map[i][j]))
			j--;
		if (ms->map[i][j] != '1')
			return (1);
		i++;
	}
	return (0);
}

int check_spawns(char c, map_struct *ms)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (ms->nb_spawns == 0)
		{
			ms->spawn = c;
			ms->nb_spawns += 1;
		}
		else
			return (1);
	}
	return (0);
}

int check_leaks(map_struct *ms)
{
	int i;
	int j;

	i = 0;
	while (ms->map[i])
	{
		j = 0;
		while (ms->map[i][j])
		{
			if (ms->map[i][j] == '0' || ms->map[i][j] == '2' || isspawn(ms->map[i][j]))
			{
				if (check_around(ms->map[i - 1][j]))
					return (1);
				if (check_around(ms->map[i][j - 1]))
					return (1);
				if (check_around(ms->map[i + 1][j]))
					return (1);
				if (check_around(ms->map[i][j + 1]))
					return (1);
			}
			if (check_spawns(ms->map[i][j], ms))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_spawn_close(map_struct *ms)
{
	if (valid_extrem_lines(ms))
		return (1);
	if (valid_middle_lines(ms))
		return (1);
	if(check_leaks(ms))
		return (1);
	if (ms->nb_spawns == 0)
		return (1);
	return (0);
}