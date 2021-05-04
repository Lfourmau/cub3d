/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:30:31 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/04 11:11:26 by lfourmau         ###   ########lyon.fr   */
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

static int		parsing(char *arg, t_big_struct *bs)
{
	if (check_cub(arg))
			return (printf("Error\nbad map format\n"));
	parsing_struct_init(bs);
	if (full_parsing(arg, bs) > 0)
			return (1);
	if (check_spawn_close(bs))
			return (printf("Error\nInvalid map\n"));
	return (0);
}

int     main(int argc, char **argv)
{
	t_big_struct	bs;

	if (argc == 2)
	{
		if (parsing(argv[1], &bs))
			return (1);
		window_prog(&bs);
	}
	else if (argc == 3)
	{
		if (check_save(argv[2]))
			return (printf("Wrong save arg\n"));
	}
	else
		printf("Error\nWrong arguments\n");
	// while (1)
	// 	;
}
