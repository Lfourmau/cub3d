/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:22:37 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 10:32:43 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_full_numbers(char **splitresult, int i)
{
	int	j;

	while (splitresult[i])
	{
		j = 0;
		while (splitresult[i][j])
		{
			if (ft_isdigit(splitresult[i][j]))
				j++;
			else
				return (1);
		}
		i++;
	}
	return (0);
}

int	number_of_split(char **splitresult)
{
	int	i;

	i = 0;
	if (!splitresult)
		return (0);
	while (splitresult[i])
		i++;
	return (i);
}

int	check_identifiers_textures(char *line)
{
	if (!ft_strncmp(line, "NO", 2) && line[2] == ' ')
		return (0);
	if (!ft_strncmp(line, "SO", 2) && line[2] == ' ')
		return (0);
	if (!ft_strncmp(line, "WE", 2) && line[2] == ' ')
		return (0);
	if (!ft_strncmp(line, "EA", 2) && line[2] == ' ')
		return (0);
	if (line[0] == 'S' && line[1] == ' ')
		return (0);
	return (1);
}

int	limit_colors(char **colors)
{
	int	i;

	i = 0;
	while (colors[i])
	{
		if (ft_atoi(colors[i]) > 255)
			return (1);
		i++;
	}
	return (0);
}

int	texture_exist(t_big_struct *bs)
{
	if (open(bs->ps->NO, O_RDONLY) == -1)
		return (1);
	if (open(bs->ps->SO, O_RDONLY) == -1)
		return (1);
	if (open(bs->ps->EA, O_RDONLY) == -1)
		return (1);
	if (open(bs->ps->WE, O_RDONLY) == -1)
		return (1);
	if (open(bs->ps->S, O_RDONLY) == -1)
		return (1);
	return (0);
}
