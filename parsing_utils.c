/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:22:37 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/22 15:00:05 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_full_numbers(char **splitresult, int i)
{
	int j;

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
	int i;

	i = 0;
	if (!splitresult)
		return (0);
	while (splitresult[i])
		i++;
	return (i);
}

int check_identifiers_textures(char *line)
{
	if (!ft_strncmp(line, "NO", 2))
		return (0);
	if (!ft_strncmp(line, "SO", 2))
		return (0);
	if (!ft_strncmp(line, "WE", 2))
		return (0);
	if (!ft_strncmp(line, "EA", 2))
		return (0);
	if (line[0] == 'S' && line[1] == ' ')
		return (0);
	return (1);
}

char 	**ft_realloc(char **map, char *line)
{
	char **tmp;
	int i;

	i = 0;
	tmp = ft_calloc(number_of_split(map) + 1, sizeof(char*));
	tmp = map;
	while (map[i])
	{
		tmp[i] = map[i];
		i++;
	}
	tmp[i] = ft_calloc(ft_strlen(line), 1);
	tmp[i] = line;
	tmp[i + 1] = 0;
	//free(map);
	return (tmp);
}
