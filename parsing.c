/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:54:24 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/25 13:05:01 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_r(char *line, parse_struct *ps)
{
	char **split;
	split = ft_split(line, ' ');
	if (number_of_split(split) != 3 || (check_full_numbers(split, 1) == 1))
	{
		free(split);
		return(printf("Error\nVeuillez entrer une resolution valide\n"));
	}
	ps->horiz_res = ft_atoi(split[1]);
	ps->vertic_res = ft_atoi(split[2]);
	free_splits(split, number_of_split(split));
	free(line);
	return (0);
}

int		parse_textures(char *line, parse_struct *ps)
{
	char **split;
	split = ft_split(line, ' ');
	if (number_of_split(split) != 2 || split[1][0] != '.')
	{
		return(printf("Error\nTextures mal renseignees\n"));
		free(split);
	}
	if (!ft_strncmp(split[0], "NO", 2))
		ps->NO = ft_strdup(split[1]);
	if (!ft_strncmp(split[0], "SO", 2))
		ps->SO = ft_strdup(split[1]);
	if (!ft_strncmp(split[0], "WE", 2))
		ps->WE = ft_strdup(split[1]);
	if (!ft_strncmp(split[0], "EA", 2))
		ps->EA = ft_strdup(split[1]);
	if (split[0][0] == 'S' && split[0][1] != 'O')
		ps->S = ft_strdup(split[1]);
	free_splits(split, number_of_split(split));
	free(line);
	return (0);
}

int		parse_colors(char *line, parse_struct *ps)
{
	char **space_split;
	char **comma_split;
	char *c;

	space_split = ft_split(line, ' ');
	c = &space_split[0][0];
	comma_split = ft_split(space_split[1], ',');
	if (number_of_split(space_split) != 2 || number_of_split(comma_split) != 3 || check_full_numbers(comma_split, 0) == 1 || limit_colors(comma_split))
	{
		free(space_split);
		free(comma_split);
        return(printf("Error\nCouleurs du sol et du plafond mal renseignees\n")); 
	}
	if (*c == 'F')
		ps->color_f = 65536 * ft_atoi(comma_split[0]) + 256 * ft_atoi(comma_split[1]) + ft_atoi(comma_split[2]);
	if (*c == 'C')
		ps->color_c = 65536 * ft_atoi(comma_split[0]) + 256 * ft_atoi(comma_split[1]) + ft_atoi(comma_split[2]);
	free_splits(comma_split, number_of_split(comma_split));
	free_splits(space_split, number_of_split(space_split));
	free(line);
	return (0);
}

int		full_parsing(char *map, parse_struct *ps, map_struct *ms) //la map sera argv[1]
{
	char	*line;
	int fd;
	int j;
	
	fd = open(map, O_RDONLY);
	j = 0;
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'R')
			if (parse_r(line, ps) > 0)
				return (1);
		if (check_identifiers_textures(line) == 0)
			if (parse_textures(line, ps) > 0)
				return (1);
		if (line[0] == 'C' || line[0] == 'F')
			if (parse_colors(line, ps) > 0)
				return (1);
		if (line[0] == ' ' || line[0] == '1')
		{
			ms->map = map_nextline(ms->map, line, j);
			j++;
		}
		if (line[0] == 0)
			free(line);
	}
	//il faudra aussi fct pour verifier qu'on a toutes les infos
	free(line);
	display_spaces(ms->map);
	return (0);
}
