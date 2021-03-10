/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:30:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/10 11:05:51 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	ft_dracaufeu()
{
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

int		parsing(char *arg, parse_struct *ps, map_struct *ms)
{
	if (check_cub(arg))
			return (printf("Error\nbad map format\n"));
	parsing_struct_init(ps, ms);
	if (full_parsing(arg, ps, ms))
			return (1);
	if (check_spawn_close(ms))
			return (printf("Error\nInvalid map\n"));
	return (0);
}

int     main(int argc, char **argv)
{
	int i;
	int j;
	parse_struct ps;
	map_struct ms;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		//check cub
		// ms.map = NULL;
		if (parsing(argv[1], &ps, &ms))
			return (1);
		printf("\n\n\033[33m----------INFOS---------------\033[0m\n");
		printf("\033[92mRes Horizontale\033[0m --> [%d]\n", ps.horiz_res);
		printf("\033[92mRes Verticale\033[0m --> [%d]\n", ps.vertic_res);
		printf("\033[92mNO\033[0m --> [%s]\n", ps.NO);
		printf("\033[92mSO\033[0m --> [%s]\n", ps.SO);
		printf("\033[92mWE\033[0m --> [%s]\n", ps.WE);
		printf("\033[92mEA\033[0m --> [%s]\n", ps.EA);
		printf("\033[92mS\033[0m --> [%s]\n", ps.S);
		printf("\033[92mColor floor\033[0m --> [%d]\n", ps.color_f);
		printf("\033[92mColor ciel\033[0m --> [%d]\n", ps.color_c);
		printf("\033[33m-----------MAP---------------\033[0m\n");
		while (ms.map[i])
		{
			printf("\033[92mligne [%d] :\033[0m [%s]", i, ms.map[i]);
			i++;
			printf("\n");
		}

		ft_dracaufeu();
	}
	else
		printf("Error\nWrong arguments\n");
	// while (1)
	// 	;
}
