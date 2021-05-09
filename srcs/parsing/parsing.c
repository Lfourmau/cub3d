/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 09:54:24 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/09 17:14:03 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_r(t_big_struct *bs)
{
	char	**split;

	if (bs->ps.horiz_res != 0 || bs->ps.vertic_res != 0)
		return (printf("Error\nToo much informations\n"));
	split = ft_split(bs->ps.line, ' ');
	if (number_of_split(split) != 3 || (check_full_numbers(split, 1) == 1))
	{
		free_splits(split, number_of_split(split));
		return (printf("Error\nWrong resolution\n"));
	}
	bs->ps.horiz_res = ft_atoi(split[1]);
	bs->ps.vertic_res = ft_atoi(split[2]);
	free_splits(split, number_of_split(split));
	free(bs->ps.line);
	return (0);
}

int	parse_textures(t_big_struct *bs)
{
	char	**split;

	split = ft_split(bs->ps.line, ' ');
	if (number_of_split(split) != 2 || split[1][0] != '.')
	{
		free_splits(split, number_of_split(split));
		return (printf("Error\nWrong textures\n"));
	}
	if (!ft_strncmp(split[0], "NO", 2) && bs->ps.NO == 0)
		bs->ps.NO = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "SO", 2) && bs->ps.SO == 0)
		bs->ps.SO = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "WE", 2) && bs->ps.WE == 0)
		bs->ps.WE = ft_strdup(split[1]);
	else if (!ft_strncmp(split[0], "EA", 2) && bs->ps.EA == 0)
		bs->ps.EA = ft_strdup(split[1]);
	else if (split[0][0] == 'S' && split[0][1] != 'O' && bs->ps.S == 0)
		bs->ps.S = ft_strdup(split[1]);
	else
		return (printf("Error\nToo much informations\n"));
	free_splits(split, number_of_split(split));
	free(bs->ps.line);
	return (0);
}

int	parse_colors(t_big_struct *bs)
{
	char	**space_split;
	char	**comma_split;
	char	*c;

	space_split = ft_split(bs->ps.line, ' ');
	c = &space_split[0][0];
	comma_split = ft_split(space_split[1], ',');
	if (number_of_split(space_split) != 2 || number_of_split(comma_split) != 3
		|| check_full_numbers(comma_split, 0) == 1 || limit_colors(comma_split))
	{
		 free_comma_space_splits(comma_split, space_split);
		return (printf("Error\nWrong colors\n"));
	}
	if (*c == 'F' && bs->ps.color_f == -1)
		bs->ps.color_f = 65536 * ft_atoi(comma_split[0]) \
		+ 256 * ft_atoi(comma_split[1]) + ft_atoi(comma_split[2]);
	else if (*c == 'C' && bs->ps.color_c == -1)
		bs->ps.color_c = 65536 * ft_atoi(comma_split[0]) \
		+ 256 * ft_atoi(comma_split[1]) + ft_atoi(comma_split[2]);
	else
		return (printf("Error\nToo much informations\n"));
	free_comma_space_splits(comma_split, space_split);
	free(bs->ps.line);
	return (0);
}

int	full_parsing_body(t_big_struct *bs, int *j)
{
	if (bs->ps.line[0] == 'R' && bs->ps.line[1] == ' ')
		return (parse_r(bs));
	else if (check_identifiers_textures(bs) == 0)
		return (parse_textures(bs));
	else if ((bs->ps.line[0] == 'C' || bs->ps.line[0] == 'F')
		&& bs->ps.line[1] == ' ')
		return (parse_colors(bs));
	else if (bs->ps.line[0] == ' ' || bs->ps.line[0] == '1')
	{
		if (check_struct(bs) == 1)
			return (printf("Error\nInformation mising before the map\n"));
		bs->ms.map = map_nextline(bs->ms.map, bs, *j);
		*j += 1;
	}
	else if (bs->ps.line[0] == 0)
	{
		if (bs->ms.map != 0 && valid_extrem_lines(bs))
			return (printf("Empty line in the map\n"));
		free(bs->ps.line);
		return (0);
	}
	else
		return (printf("Error\nUnknown informations\n"));
	return (0);
}

int	full_parsing(char *map, t_big_struct *bs)
{
	int		fd;
	int		j;

	j = 0;
	fd = open(map, O_RDWR);
	if (fd == -1)
		return (printf("Map is missing\n"));
	bs->ps.line = NULL;
	while (get_next_line(fd, &bs->ps.line) != 0)
	{
		if (full_parsing_body(bs, &j))
			return (free_line(bs));
	}
	if (full_parsing_body(bs, &j))
		return (free_line(bs));
	if (texture_exist(bs))
		return (printf("Texture file missing\n"));
	if (check_struct(bs))
		return (1);
	display_spaces(bs->ms.map);
	return (0);
}
