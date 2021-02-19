/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:30:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/19 08:44:43 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     main(int argc, char **argv)
{
	if (argc == 2)
	{
		parse_struct *ps;
		ps = malloc(sizeof(parse_struct));
		parsing_struct_init(ps);
		full_parsing(argv[1], ps);
		printf("%d\n", ps->horiz_res);
		printf("%d\n", ps->vertic_res);
		printf("%s\n", ps->NO);
		printf("%s\n", ps->SO);
		printf("%s\n", ps->WE);
		printf("%s\n", ps->EA);
		printf("%s\n", ps->S);
		printf("%d\n", ps->color_f);
		printf("%d\n", ps->color_c);
	}
	else
		printf("Error\nNombre d'arguments incorrect\n");
}
