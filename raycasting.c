/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfourmau <lfourmau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:01:43 by loic              #+#    #+#             */
/*   Updated: 2021/05/03 08:38:07 by lfourmau         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_column(big_struct *bs, int x, float y)
{
	int j;

	j = -1;
	bs->rs->begin_wall = bs->ps->vertic_res / 2 - y / 2;
	bs->rs->end_wall = bs->ps->vertic_res / 2 + y / 2;
	bs->rs->wall_onscreen_size = bs->rs->end_wall - bs->rs->begin_wall;
	//print ciel
	while (++j < bs->rs->begin_wall && j < bs->ps->vertic_res)
		my_mlx_pixel_put(bs, x, j, bs->ps->color_c);
	//affichage de la texture selon l'orientation
	if (bs->rs->side == 1 && bs->rs->r_angle > 0 && bs->rs->r_angle < M_PI)
		put_wall_south(bs, x, j);
	else if (bs->rs->side == 1 && bs->rs->r_angle > M_PI && bs->rs->r_angle < 2 * M_PI)
		put_wall_north(bs, x, j);
	else if (bs->rs->side == 0 && bs->rs->r_angle > M_PI / 2 && bs->rs->r_angle < 3 * M_PI / 2)
		put_wall_east(bs, x, j);
	else
		put_wall_west(bs, x, j);
	j = bs->rs->end_wall - 1;
	//print sol
	while (++j < bs->ps->vertic_res)
		my_mlx_pixel_put(bs, x, j, bs->ps->color_f);
}

static void	check_step(big_struct *bs, float angle)
{
	if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
	{
		bs->rs->xstep = -1;
		bs->rs->xnear = (bs->ws->player_pos_x - bs->rs->mapx) * bs->rs->deltax;
	}
	else
	{
		bs->rs->xstep = 1;
		bs->rs->xnear = (bs->rs->mapx + 1.0 - bs->ws->player_pos_x) * bs->rs->deltax;
	}
	if (angle > 0 && angle < M_PI)
	{
		bs->rs->ystep = -1;
		bs->rs->ynear = (bs->ws->player_pos_y - bs->rs->mapy) * bs->rs->deltay;
	}
	else
	{
		bs->rs->ystep = 1;
		bs->rs->ynear = (bs->rs->mapy + 1.0 - bs->ws->player_pos_y) * bs->rs->deltay;
	}
}

static void	check_hit(big_struct *bs, int i)
{
	bs->ss->spritenum = 0;
	while (bs->rs->hit == 0)
	{
		//choix de la bonne direction pour le prochain carré
		if (bs->rs->xnear < bs->rs->ynear)
		{
			bs->rs->raydist = bs->rs->xnear;
			bs->rs->xnear += bs->rs->deltax;
			bs->rs->mapx += bs->rs->xstep;
			bs->rs->side = 0;
		}
		else
		{
			bs->rs->raydist = bs->rs->ynear;
			bs->rs->ynear += bs->rs->deltay;
			bs->rs->mapy += bs->rs->ystep;
			bs->rs->side = 1;
		}
		//touche un sprite
		if (bs->ms->map[bs->rs->mapy][bs->rs->mapx] == '2')
		{
			if (!sprite_infos(bs))
				//if (bs->ss->inter_sprite.x < bs->ss->mapx_sprite + 1 && bs->ss->inter_sprite.x > bs->ss->mapx_sprite && bs->ss->inter_sprite.y < bs->ss->mapy_sprite + 1 && bs->ss->inter_sprite.y > bs->ss->mapy_sprite)
					bs->ss->spritenum++;
			printf("INTER X : %f -- INTER Y %f -- SP %d\n", bs->ss->inter_sprite.x, bs->ss->inter_sprite.y, bs->ss->spritenum);
		}
		//touche un mur
		else if (bs->ms->map[bs->rs->mapy][bs->rs->mapx] && (bs->ms->map[bs->rs->mapy][bs->rs->mapx] == '1' || bs->ms->map[bs->rs->mapy][bs->rs->mapx] == '3'))
		{
			bs->rs->hit = 1;
			bs->rs->inter_wall.x = bs->ws->player_pos_y + bs->rs->base_x * bs->rs->raydist;
			bs->rs->inter_wall.y = bs->ws->player_pos_x + bs->rs->base_y * bs->rs->raydist;
			//fish eye correction
			bs->rs->raydist *= cos(bs->ws->p_angle - bs->rs->r_angle);
			//TODO : mettre le raydist a 0.01 si il vaut 0 pour ne pas segfault dans certains cas
			bs->rs->wall_height = bs->ps->vertic_res / bs->rs->raydist;
			print_column(bs, i, bs->rs->wall_height);
		}
	}
	if (bs->ss->spritenum > 0)
		put_sprite(bs, i, bs->ss->begin_sprite);
	bs->rs->hit = 0;
}

static void	raycasting(big_struct *bs, float angle, int i)
{
	bs->rs->mapx = (int)bs->ws->player_pos_x;//pos est en float, on int pour avoir l'index
	bs->rs->mapy = (int)bs->ws->player_pos_y;//pos est en float, on int pour avoir l'index
	bs->rs->deltax =  sqrt(1 + (sin(angle) * sin(angle)) / (cos(angle) * cos(angle)));
	bs->rs->deltay =  sqrt(1 + (cos(angle) * cos(angle)) / (sin(angle) * sin(angle)));
	check_step(bs, angle); //permet de se decaler en fonction de l'angle
	check_hit(bs, i); //on check le next carré et verifie si c'est un mur ou non
}

void	raycasting_loop(big_struct *bs)
{
	int 	i = -1;
	//Adapte la res hoirz a la FOV (60)
	float 	ratioangle = (60 * 0.0174532925) / bs->ps->horiz_res;
	//Le premier rayon est tiré a 30degres a gauche du joueur
	bs->rs->r_angle = bs->ws->p_angle + 30 * 0.0174532925;
	xpm_init(bs);
	while (++i < bs->ps->horiz_res)
	{
		//rotate angle
		if (bs->rs->r_angle > 2 * M_PI)
			bs->rs->r_angle -= 2 * M_PI;
		if (bs->rs->r_angle < 0)
			bs->rs->r_angle += 2 * M_PI;
		//Rotate vector pour trouver les bonnes intersections et afficher les textures
		rotate_vector(bs);
		raycasting(bs, bs->rs->r_angle, i);
		//enleve ratio angle pour balayer tout l'ecran
		bs->rs->r_angle -= ratioangle;
	}
}