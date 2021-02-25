/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:30:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/02/25 13:43:07 by lfourmau         ###   ########lyon.fr   */
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
		parsing_struct_init(ps, ms);
		if (full_parsing(argv[1], ps, ms))
			return (1);
		if (check_spawn_close(ms))
			return (printf("map invalide\n"));
		printf("\n\n\033[33m----------INFOS---------------\033[0m\n");
		printf("\033[92mRes Horizontale\033[0m --> [%d]\n", ps->horiz_res);
		printf("\033[92mRes Verticale\033[0m --> [%d]\n", ps->vertic_res);
		printf("\033[92mNO\033[0m --> [%s]\n", ps->NO);
		printf("\033[92mSO\033[0m --> [%s]\n", ps->SO);
		printf("\033[92mWE\033[0m --> [%s]\n", ps->WE);
		printf("\033[92mEA\033[0m --> [%s]\n", ps->EA);
		printf("\033[92mS\033[0m --> [%s]\n", ps->S);
		printf("\033[92mColor floor\033[0m --> [%d]\n", ps->color_f);
		printf("\033[92mColor ciel\033[0m --> [%d]\n", ps->color_c);
		printf("\033[33m-----------MAP---------------\033[0m\n");
		while (ms->map[i])
		{
			printf("\033[92mligne [%d] :\033[0m [%s]", i, ms->map[i]);
			i++;
			printf("\n");
		}

printf("\033[0;33m		.\"-,.__\n");
printf("\033[1;31m              .--'  .._,'\"-' `.\n");
printf("\033[1;31m                 `.     `.  ,\n");
printf("\033[0;33m             .    .'         `'\n");
printf("\033[0;33m             `.   /          ,'\n");
printf("\033[1;31m               `  '--.   ,-\"'\n");
printf("\033[1;31m                `\"`   |  \n");
printf("\033[0;33m                   -. \\, |\n");
printf("\033[1;31m                    `--Y.'      ___.\n");
printf("\033[1;31m                         \\     L._, \n");
printf("\033[1;31m               _.,        `.   <  <\\                _\n");
printf("\033[1;31m             ,' '           `, `.   | \\            ( `\n");
printf("\033[1;31m          ../, `.            `  |    .\\`.           \\ \\_\n");
printf("\033[1;31m         ,' ,..  .           _.,'    ||\\l            )  '\".\n");
printf("\033[1;31m        , ,'   \\           ,'.-.`-._,'  |           .  _._`.\n");
printf("\033[1;31m      ,' /      \\ \\        `' ' `--/   | \\          / /   ..\\\n");
printf("\033[1;31m    .'  /        \\ .         |\\__ - _ ,'` `        / /     `.`.\n");
 printf("\033[1;31m   |  '          ..         `-...-\"  |  `-'      / /        . `.\n");
printf("\033[1;31m    | /           |L__           |    |          / /          `. `.\n");
printf("\033[1;31m   , /            .   .          |    |         / /             ` `\n");
printf("\033[1;31m  / /          ,. ,`._ `-_       |    |  _   ,-' /               ` \n");
printf("\033[1;31m / .           \\\"`_/. `-_ \\_,.  ,'    +-' `-'  _,        ..,-.    \\`.\n");
printf("\033[1;31m.  '         .-f    ,'   `    '.       \\__.---'     _   .'   '      \n");
printf("\033[1;31m' /          `.'    l     .' /          \\..      ,_|/   `.  ,'`     L`\n");
printf("\033[1;31m|'      _.-\"` `.    \\ _,'  `            \\ `.___`.'\"`-.  , |   |    | \n");
printf("\033[1;31m||    ,'      `. `.   '       _,...._        `  |    `/ '  |   '     .|\n");
printf("\033[1;31m||  ,'          `. ;.,.---' ,'       `.   `.. `-'  .-' /_ .'    ;_   ||\n");
printf("\033[1;31m|| '              V      / /           `   | `   ,'   ,' '.    !  `. ||\n");
printf("\033[1;31m||/            _,-------7 '              . |  `-'    l         /    `||\n");
printf("\033[1;31m. |          ,' .-   ,' ||               | .-.        `.      .'     ||\n");
printf("\033[1;31m`'        ,'    `\".'    |               |    `.        '. -.'       `'\n");
printf("\033[1;31m          /      ,'      |               |,'    \\-.._,.'/'\n");
printf("\033[1;31m          .     /        .               .       \\    .''\n");
printf("\033[1;31m        .`.    |         `.             /         :_,'.'\n");
printf("\033[1;31m          \\ `...\\   _     ,'-.        .'         /_.-'\n");
printf("\033[1;31m           `-.__ `,  `'   .  _.>----''.  _  __  /\n");
printf("\033[1;31m                 / ,\"'\"\\,'               `/  `-.|\" \n");
	}
	else
		printf("Error\nNombre d'arguments incorrect\n");
	// while (1)
	// 	;
}
