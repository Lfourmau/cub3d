/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:30:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/18 15:00:22 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int     main(int argc, char **argv)
{
	parse_struct *ps;
	argc += 1;
	ps = malloc(sizeof(parse_struct));
	full_parsing(argv[1], ps);
	printf("%d\n", ps->horiz_res);
	printf("%d\n", ps->vertic_res);
//	printf("%s\n", ps->NO);
//	printf("%s\n", ps->SO);
//	printf("%s\n", ps->WE);
//	printf("%s\n", ps->EA);
	printf("%s\n", ps->S);
}
