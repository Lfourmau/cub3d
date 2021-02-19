/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 08:22:37 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/19 10:18:57 by lfourmau         ###   ########lyon.fr   */
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
