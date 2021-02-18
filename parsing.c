/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:54:24 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/18 15:18:47 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_r(char *line, parse_struct *ps)
{
	char **split;
	split = ft_split(line, ' ');
	//que faire si on n'a pas que des chiffres ?
	if (ft_strlen(*split) != 3)
	{
		//free(split);
		 //print erreur
	}
	ps->horiz_res = ft_atoi(split[1]);
	ps->vertic_res = ft_atoi(split[2]);
	//free(split);
}

void	parse_textures(char *line, parse_struct *ps)
{
	char **split;
	split = ft_split(line, ' ');
	if (ft_strlen(*split) != 2)
	{
		//free(split);
	    //print erreur
	}
	if (!ft_strncmp(split[0], "NO", 2))
		ps->NO = split[1];
	if (!ft_strncmp(split[0], "SO", 2))
		ps->SO = split[1];
	if (!ft_strncmp(split[0], "WE", 2))
		ps->WE = split[1];
	if (ft_strncmp(split[0], "EA", 2))
		ps->EA = split[1];
	if (split[0][0] == 'S' && split[0][1] != 'O')
		ps->S = split[1];;
	//free(split);
}
/*
void	parse_colors(char *line, parse_struct *ps)
{
	char **space_split;
	char **comma_split;
	char *c;

	space_split = ft_split(line, ' ');
	if (ft_strlen(*space_split) != 2)
	{
		free(space_split);
        //print erreur
	}
	c = &space_split[0][0];
	comma_split = ft_split(space_split[1], ',');
	free(space_split);
	if (ft_strlen(*comma_split) != 3)
	{
		free(comma_split);
		 //print erreur
	}
	if (*c == 'F')
		ps->color_f = //calcul sur les rgb pour le int
	if (*c == 'C')
		ps->color_c = //calcul sur les rgb pour le  int
	free(comma_split);

}
*/

void	full_parsing(char *map, parse_struct *ps) //la map sera argv[1]
{
	char	*line;
	int fd;
	
	fd = open(map, O_RDONLY);
	line = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'R')
			parse_r(line, ps);
		if (line[0] == 'N' || line[0] == 'W' || line[0] == 'E' || line[0] == 'S')
			parse_textures(line, ps);
/*
		if (line[0] == 'C' || line[0] == 'F')
			parse_colors(line);

		if (line[0] == ' ' || line[0] == '1')
			parse_map();
*/
	}
//	free(line);
}
