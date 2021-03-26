/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:21:18 by lfourmau          #+#    #+#             */
/*   Updated: 2021/03/26 11:19:48 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft/libft.h"
#include "mlx/mlx.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <fcntl.h>

# define LEFTLOOK 123
# define RIGHTLOOK 124
# define WKEY 13
# define AKEY 0
# define SKEY 1
# define DKEY 2
# define ESC 53


typedef struct	parsing_struct
	{
		int 	horiz_res;
		int 	vertic_res;	
		int		color_f;
		int		color_c;
		char	*NO;
		char	*SO;
		char	*WE;
		char	*EA;
		char	*S;
	}			parse_struct;

typedef struct	map_struct
	{
		char	**map;
		char 	spawn;
		int		nb_spawns;
		int		spawn_x;
		int		spawn_y;
	}			map_struct;

typedef struct	window_struct
	{
		void	*mlx_ptr;
		void	*mlx_img;
		void	*win_ptr;
		void	*img_ptr;
		int		bits_per_pixel;
   		int		line_length;
   		int		endian;
		int		multiplicator;
		int		minimap_pos_x;
		int		minimap_pos_y;
		float	p_angle;
		float 	player_pos_x;
		float	player_pos_y;
		int 	key_press;
	}			window_struct;

typedef struct ray_struct
{
		int		mapx;
		int		mapy;
		float	ynear;
		float	xnear;
		float 	deltax;
		float 	deltay;
		float 	xstep;
		float 	ystep;
		int		hit;
		int 	side;
		float 	r_angle;
		float	rayshort;
}				ray_struct;

typedef struct  big_struct
{
	parse_struct	*ps;
	map_struct		*ms;
	window_struct	*ws;
	ray_struct 		*rs;
}				big_struct;

int				full_parsing(char *map, big_struct *bs);
int				check_full_numbers(char **splitresult, int i);
void			parsing_struct_init(big_struct *bs);
int				number_of_split(char **splitresult);
int				check_identifiers_textures(char *line);
char			**map_nextline(char **map, char *line, int n);
int				max_len_map(char **map);
void			parse_map(char *line, big_struct *bs, int j);
void			free_splits(char **chain, int i);
void			display_spaces(char **map);
int				check_spawn_close(big_struct *bs);
int				limit_colors(char **colors);
int				isspawn(char c);
int				check_around(char c);
int     		check_cub(char *str);
int				check_struct(big_struct *bs);
int				free_struct(big_struct *bs, char *line);

int 			window_prog(big_struct *bs);
void            my_mlx_pixel_put(big_struct *bs, int x, int y, int color);
void 			print_square(big_struct *bs, int posx, int posy, int color);
void			print_minimap(big_struct *bs);
void			multiplicator(big_struct *bs);
void			detect_spawn_dir(big_struct *bs);
void 			print_direction(big_struct *bs, int posx, int posy, int color);
void			wmoove(big_struct *bs);
void			smoove(big_struct *bs);
void 			amoove(big_struct *bs);
void			dmoove(big_struct *bs);
void			lookmoove(big_struct *bs, int key);
int				render_next_frame(big_struct *bs);

void			raycasting_loop(big_struct *bs);
void			print_column(big_struct *bs, int x, int y);
#endif
