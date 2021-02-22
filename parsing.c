/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:54:24 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/22 16:34:09 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_r(char *line, parse_struct *ps)
{
	char **split;
	split = ft_split(line, ' ');
	if (number_of_split(split) != 3)
	{
		//free(split);
		return(printf("Error\nVeuillez entrer R suivi de 2 nombres pour la resolution\n"));
	}
	if (check_full_numbers(split, 1) == 1)
		return(printf("Error\nVeuilez n'entrer que des chiffres pour la resolution\n"));
	ps->horiz_res = ft_atoi(split[1]);
	ps->vertic_res = ft_atoi(split[2]);
	//free(split);
	return (0);
}

int	parse_textures(char *line, parse_struct *ps)
{
	char **split;
	split = ft_split(line, ' ');
	if (number_of_split(split) != 2 || split[1][0] != '.')
	{
		return(printf("Error\nTextures mal renseignees\n"));
		//free(split);
	}
	if (!ft_strncmp(split[0], "NO", 2))
		ps->NO = split[1];
	if (!ft_strncmp(split[0], "SO", 2))
		ps->SO = split[1];
	if (!ft_strncmp(split[0], "WE", 2))
		ps->WE = split[1];
	if (!ft_strncmp(split[0], "EA", 2))
		ps->EA = split[1];
	if (split[0][0] == 'S' && split[0][1] != 'O')
		ps->S = split[1];;
	//free(split);
	return (0);
}

int	parse_colors(char *line, parse_struct *ps)
{
	char **space_split;
	char **comma_split;
	char *c;

	space_split = ft_split(line, ' ');
	c = &space_split[0][0];
	comma_split = ft_split(space_split[1], ',');
	if (number_of_split(space_split) != 2 || number_of_split(comma_split) != 3 || check_full_numbers(comma_split, 0) == 1)
	{
		free(space_split);
		//free(space_split);
       return(printf("Error\nCouleurs du sol et du plafond mal renseignees\n")); 
	}
		free(space_split);
	if (*c == 'F')
		ps->color_f = 65536 * ft_atoi(comma_split[0]) + 256 * ft_atoi(comma_split[1]) + ft_atoi(comma_split[2]);
	if (*c == 'C')
		ps->color_c = 65536 * ft_atoi(comma_split[0]) + 256 * ft_atoi(comma_split[1]) + ft_atoi(comma_split[2]);
	//free(comma_split);
	return (0);
}

int	full_parsing(char *map, parse_struct *ps, map_struct *ms) //la map sera argv[1]
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
			ms->map = ft_realloc(ms->map, line, j);
			j++;
		}
//il faudra aussi fct pour verifier qu'on a toutes les infos

	}
	return (0);
//	free(line);
}
