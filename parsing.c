/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:54:24 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/09 07:20:26 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		parse_r(char *line, parse_struct *ps)
{
	if (ps->horiz_res != 0 || ps->vertic_res != 0)
		return (printf("Error\nDupplicata d'informations\n"));
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
	if (!ft_strncmp(split[0], "NO", 2) && ps->NO == 0)
		ps->NO = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "SO", 2) && ps->SO == 0)
		ps->SO = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "WE", 2) && ps->WE == 0)
		ps->WE = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "EA", 2) && ps->EA == 0)
		ps->EA = ft_strdup(split[1]);
	else if (split[0][0] == 'S' && split[0][1] != 'O' && ps->S == 0)
		ps->S = ft_strdup(split[1]);
	else
		return(printf("Error\nDupplicata d'infos\n")); 
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
	if (*c == 'F' && ps->color_f == -1)
		ps->color_f = 65536 * ft_atoi(comma_split[0]) + 256 * ft_atoi(comma_split[1]) + ft_atoi(comma_split[2]);
	else if (*c == 'C' && ps->color_c == -1)
		ps->color_c = 65536 * ft_atoi(comma_split[0]) + 256 * ft_atoi(comma_split[1]) + ft_atoi(comma_split[2]);
	else
		return(printf("Error\nDupplicata d'infos\n")); 
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
		if (line[0] == 'R' && line[1] == ' ')
			if (parse_r(line, ps) > 0)
				return (1);
		if (check_identifiers_textures(line) == 0)
			if (parse_textures(line, ps) > 0)
				return (1);
		if ((line[0] == 'C' || line[0] == 'F') && line[1] == ' ')
			if (parse_colors(line, ps) > 0)
				return (1);
		if (line[0] == ' ' || line[0] == '1')
		{
			if (check_struct(ps, ms) == 1)
				return (printf("Error\nManque une info avant la map\n"));
			ms->map = map_nextline(ms->map, line, j);
			j++;
		}
		if (line[0] == 0)
		{
			free(line);
			if (ms->map != 0)
				return (printf("Ligne vide dans la map\n"));
		}
	}
	if (check_struct(ps, ms))
		return (free_struct(ps, ms, line));
	free(line);
	display_spaces(ms->map);
	return (0);
}

