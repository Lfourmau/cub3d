/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_close_spawn.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 12:13:52 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 08:35:37 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	valid_extrem_lines(t_big_struct *bs)
{
	int	i;
	int	nb_splits;

	i = 0;
	nb_splits = number_of_split(bs->ms->map);
	while (bs->ms->map[0][i] && (bs->ms->map[0][i] == ' ' || bs->ms->map[0][i] == '1'))
		i++;
	if (bs->ms->map[0][i] != 0)
		return (1);
	i = 0;
	while (bs->ms->map[nb_splits - 1][i] && (bs->ms->map[nb_splits - 1][i] == ' ' || bs->ms->map[nb_splits - 1][i] == '1'))
		i++;
	if (bs->ms->map[nb_splits - 1][i] != 0)
		return (1);
	return (0);
}

int	valid_middle_lines(t_big_struct *bs)
{
	int	i;
	int	j;
	int	nb_splits;

	i = 1;
	nb_splits = number_of_split(bs->ms->map);
	while (i < nb_splits - 1) //i - 1 car extremites deja check
	{
		j = 0;
		while (ft_isspace(bs->ms->map[i][j]))
			j++;
		if (bs->ms->map[i][j] != '1')
			return (1);
		while (bs->ms->map[i][j])
			j++;
		j--;
		while (ft_isspace(bs->ms->map[i][j]))
			j--;
		if (bs->ms->map[i][j] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_spawns(char c, t_big_struct *bs, int i, int j)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (bs->ms->nb_spawns == 0)
		{
			bs->ms->start_spawn.x = j;
			bs->ms->start_spawn.y = i;
			bs->ms->spawn = c;
			bs->ms->nb_spawns += 1;
		}
		else
			return (1);
	}
	return (0);
}

int	check_leaks(t_big_struct *bs)
{
	int	i;
	int	j;

	i = -1;
	while (bs->ms->map[++i])
	{
		j = -1;
		while (bs->ms->map[i][++j])
		{
			if (bs->ms->map[i][j] == '0' || bs->ms->map[i][j] == '2' || bs->ms->map[i][j] == '3' || isspawn(bs->ms->map[i][j]))
			{
				if (check_around(bs->ms->map[i - 1][j]))
					return (1);
				if (check_around(bs->ms->map[i][j - 1]))
					return (1);
				if (check_around(bs->ms->map[i + 1][j]))
					return (1);
				if (check_around(bs->ms->map[i][j + 1]))
					return (1);
			}
			if (check_spawns(bs->ms->map[i][j], bs, i, j))
				return (1);
		}
	}
	return (0);
}

int	check_spawn_close(t_big_struct *bs)
{
	if (valid_extrem_lines(bs))
		return (1);
	if (valid_middle_lines(bs))
		return (1);
	if (check_leaks(bs))
		return (1);
	if (bs->ms->nb_spawns == 0)
		return (1);
	return (0);
}
