/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:30:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/22 16:34:14 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     main(int argc, char **argv)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		parse_struct *ps;
		map_struct *ms;
		ps = malloc(sizeof(parse_struct));
		ms = malloc(sizeof(map_struct));
		ms->map = NULL;
		parsing_struct_init(ps);
		full_parsing(argv[1], ps, ms);
		printf("%d\n", ps->horiz_res);
		printf("%d\n", ps->vertic_res);
		printf("%s\n", ps->NO);
		printf("%s\n", ps->SO);
		printf("%s\n", ps->WE);
		printf("%s\n", ps->EA);
		printf("%s\n", ps->S);
		printf("%d\n", ps->color_f);
		printf("%d\n", ps->color_c);
		while (ms->map[i])
		{
			printf("ligne [%d] : %s", i, ms->map[i]);
			i++;
			printf("\n");
		}
	}
	else
		printf("Error\nNombre d'arguments incorrect\n");
}
