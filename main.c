/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:30:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/04/29 15:40:08 by lfourmau         ###   ########lyon.fr   */
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

static int		parsing(char *arg, big_struct *bs)
{
	if (check_cub(arg))
			return (printf("Error\nbad map format\n"));
	parsing_struct_init(bs);
	if (full_parsing(arg, bs) == 1)
			return (1);
	if (check_spawn_close(bs))
			return (printf("Error\nInvalid map\n"));
	return (0);
}

int     main(int argc, char **argv)
{
	int i;
	int j;
	big_struct bs;
	bs.ps = malloc(sizeof(parse_struct));
	bs.ms = malloc(sizeof(map_struct));
	bs.ws = malloc(sizeof(window_struct));
	bs.rs = malloc(sizeof(ray_struct));
	bs.ts = malloc(sizeof(textures_struct));
	bs.ks = malloc(sizeof(keys_struct));
	bs.ss = malloc(sizeof(sprites_struct));
	//bs.ts->textures_params = malloc(sizeof(textures_params));

	if (!bs.ps || !bs.ms)
	{
		free(bs.ps);
		free(bs.ms);
	}
	i = 0;
	j = 0;
	if (argc == 2)
	{
		if (parsing(argv[1], &bs))
			return (1);
		window_prog(&bs);
		// printf("\n\n\033[33m----------INFOS---------------\033[0m\n");
		// printf("\033[92mRes Horizontale\033[0m --> [%d]\n", bs.ps->horiz_res);
		// printf("\033[92mRes Verticale\033[0m --> [%d]\n", bs.ps->vertic_res);
		// printf("\033[92mNO\033[0m --> [%s]\n", bs.ps->NO);
		// printf("\033[92mSO\033[0m --> [%s]\n", bs.ps->SO);
		// printf("\033[92mWE\033[0m --> [%s]\n", bs.ps->WE);
		// printf("\033[92mEA\033[0m --> [%s]\n", bs.ps->EA);
		// printf("\033[92mS\033[0m --> [%s]\n", bs.ps->S);
		// printf("\033[92mColor floor\033[0m --> [%d]\n", bs.ps->color_f);
		// printf("\033[92mColor ciel\033[0m --> [%d]\n", bs.ps->color_c);
		// printf("\033[33m-----------MAP---------------\033[0m\n");
		// while (bs.ms->map[i])
		// {
		// 	printf("[%s] \033[92m <--- ligne [%d]\033[0m", bs.ms->map[i], i);
		// 	i++;
		// 	printf("\n");
		// }
		// printf("\033[92mSpawn Player\033[0m --> [%c]\n", bs.ms->spawn);


		// ft_dracaufeu();
	}
	else
		printf("Error\nWrong arguments\n");
	// while (1)
	// 	;
}
