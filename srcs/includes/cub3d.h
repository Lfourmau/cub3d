/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loic <loic@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:21:18 by lfourmau          #+#    #+#             */
/*   Updated: 2021/05/09 17:17:14 by loic             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../libft/libft.h"
# include "../../mlx/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

# define LEFTLOOK 123
# define RIGHTLOOK 124
# define WKEY 13
# define AKEY 0
# define SKEY 1
# define DKEY 2
# define ESC 53
# define DANGLE 0.01
# define DINTER 0.01

typedef struct s_point
{
	float		x;
	float		y;
}				t_point;

typedef struct s_intpoint
{
	int			x;
	int			y;
}				t_intpoint;

//PARSING
typedef struct s_parsing_struct
{
	t_intpoint	screensize;
	int			horiz_res;
	int			vertic_res;	
	int			color_f;
	int			color_c;
	char		*line;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*S;
}			t_parse_struct;

typedef struct s_map_struct
{
	char		**map;
	char		spawn;
	int			nb_spawns;
	t_intpoint	start_spawn;
}			t_map_struct;

//WINDOW MLX
typedef struct s_window_struct
{
	void		*mlx_ptr;
	void		*mlx_img;
	void		*win_ptr;
	char		*img_ptr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			mltp;
	t_intpoint	minimap_pos;
	float		p_angle;
	t_point		player_pos;
	int			key_press;
}				t_window_struct;

typedef struct s_keys_struct
{
	int		w;
	int		a;
	int		s;
	int		d;
	int		left;
	int		right;
	int		esc;
}				t_keys_struct;

//RAYCASTING
typedef struct s_ray_struct
{
	t_intpoint	map_case;
	float		ynear;
	float		xnear;
	float		deltax;
	float		deltay;
	float		xstep;
	float		ystep;
	int			hit;
	int			side;
	float		r_angle;
	float		raydist;
	t_point		inter_wall;
	float		wall_height;
	float		begin_wall;
	float		end_wall;
	int			wall_onscreen_size;
	float		base_x;
	float		base_y;
}				t_ray_struct;

typedef struct s_textures_params
{
	void	*img;
	int		*buff;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	r;
	char	g;
	char	b;
	char	t;
}				t_textures_params;

typedef struct s_textures_struct
{
	t_textures_params	w;
	t_textures_params	s;
	t_textures_params	n;
	t_textures_params	e;
	t_textures_params	sp;
}				t_textures_struct;

typedef struct s_sprites_struct
{
	t_point	inter_sprite;
	t_point	center_sprite;
	t_point	secondpoint;
	float	raydist_sprite;
	int		spritenum;
	int		begin_sprite;
	int		sprite_onscreen_size;
	int		mapx_sprite;
	int		mapy_sprite;
	int		texture_x;
}			t_sprites_struct;	

typedef struct s_big_struct
{
	t_parse_struct		ps;
	t_map_struct		ms;
	t_window_struct		ws;
	t_ray_struct		rs;
	t_textures_struct	ts;
	t_keys_struct		ks;
	t_sprites_struct	ss;
	int					bmp;
}				t_big_struct;

//PARSING FUNCS
int				full_parsing(char *map, t_big_struct *bs);
int				check_full_numbers(char **splitresult, int i);
void			parsing_struct_init(t_big_struct *bs);
int				number_of_split(char **splitresult);
int				check_identifiers_textures(t_big_struct *bs);
char			**map_nextline(char **map, t_big_struct *bs, int n);
int				max_len_map(char **map);
void			parse_map(t_big_struct *bs, int j);
void			free_splits(char **chain, int i);
void			free_textures(t_big_struct *bs);
void			display_spaces(char **map);
int				check_spawn_close(t_big_struct *bs);
int				limit_colors(char **colors);
int				isspawn(char c);
int				check_around(char c);
int				check_cub(char *str);
int				check_struct(t_big_struct *bs);
int				free_struct(t_big_struct *bs, char *line);
int				texture_exist(t_big_struct *bs);
int				free_line(t_big_struct *bs);
void			free_comma_space_splits(char **comma, char **space);
int				valid_extrem_lines(t_big_struct *bs);

//PRINT FUNCS
void			my_mlx_pixel_put(t_big_struct *bs, int x, int y, int color);
void			print_square(t_big_struct *bs, int posx, int posy, int color);
void			print_minimap(t_big_struct *bs);
void			print_minisquare(t_big_struct *bs, \
int posx, int posy, int color);
void			print_full_minimap(t_big_struct *bs);
void			print_column(t_big_struct *bs, int x, float y);
void			put_all_sprites(t_big_struct *bs, int i, \
t_sprites_struct *spritestab);
void			put_sprite(t_big_struct *bs, int x, int j, \
t_sprites_struct sprite);
void			print_good_square(t_big_struct *bs, int i, int j);

//MLX FUNCS
int				window_prog(t_big_struct *bs);
int				render_next_frame(t_big_struct *bs);
void			raycasting_loop(t_big_struct *bs);

//MATHS
void			multiplicator(t_big_struct *bs);
void			detect_spawn_dir(t_big_struct *bs);
void			rotate_vector(t_big_struct *bs);

//MOOVE FUNCS
void			updatecoord(t_big_struct *bs);
void			wmoove(t_big_struct *bs);
void			smoove(t_big_struct *bs);
void			sidemooves(t_big_struct *bs);
void			lookmoove(t_big_struct *bs);
void			moove_ray(t_big_struct *bs);
void			a_moove(t_big_struct *bs);
void			d_moove(t_big_struct *bs);
void			moove_ray_check_wall(t_big_struct *bs, int i);

//TEXTURES AND SPRITES
void			render_textures(t_big_struct *bs);
void			xpm_init(t_big_struct *bs);
void			put_wall_north(t_big_struct *bs, int x, int j);
void			put_wall_south(t_big_struct *bs, int x, int j);
void			put_wall_west(t_big_struct *bs, int x, int j);
void			put_wall_east(t_big_struct *bs, int x, int j);
void			sprite_infos(t_big_struct *bs, t_sprites_struct *spritestab);
float			dist(float xa, float xb, float ya, float yb);

//BITMAP
int				check_save(char *str);
int				bmp_image(t_big_struct *bs);

#endif
