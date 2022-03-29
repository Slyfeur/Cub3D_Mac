/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamighi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 15:42:54 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/28 15:17:27 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/display.h"

void	draw_walls(t_cub *cub, t_ray *r)
{
	unsigned int	color;
	int				i;

	i = 0;
	while (i < r->draw_start)
	{
		color = get_texture_color(cub->textures[C], 0, 0);
		put_my_pixel(cub->display, i++, r->pix_x, color);
	}
	while (r->draw_start < r->draw_end)
	{
		r->tex_y = (int)r->tex_pos;
		r->tex_pos += r->tex_stepy;
		color = get_texture_color(cub->textures[r->tex], r->tex_x, r->tex_y);
		put_my_pixel(cub->display, r->draw_start++, r->pix_x, color);
	}
	while (r->draw_start < WIN_H)
	{
		color = get_texture_color(cub->textures[F], 0, 0);
		put_my_pixel(cub->display, r->draw_start++, r->pix_x, color);
	}
}

void	init_draywing_variables(t_ray *r, t_cub *cub)
{
	r->line_h = (int)(WIN_H / r->wall_dist);
	r->draw_start = r->line_h * -1 / 2 + WIN_H / 2;
	if (r->draw_start < 0)
		r->draw_start = 0;
	r->draw_end = r->line_h / 2 + WIN_H / 2;
	if (r->draw_end >= WIN_H)
		r->draw_end = WIN_H - 1;
	if (r->side == SO_NO)
		r->wall_x = cub->player.x + r->wall_dist * r->dir_x;
	else
		r->wall_x = cub->player.y + r->wall_dist * (r->dir_y * -1);
	r->wall_x -= floor(r->wall_x);
	if (r->side == SO_NO && r->step_y == -1)
		r->tex = SO;
	else if (r->side == SO_NO)
		r->tex = NO;
	else if (r->side == WE_EA && r->step_x == 1)
		r->tex = WE;
	else
		r->tex = EA;
	r->tex_x = (int)(r->wall_x * (float)cub->textures[r->tex].w);
	r->tex_stepy = (float)cub->textures[r->tex].h / r->line_h;
	r->tex_pos = (r->draw_start - WIN_H / 2 + r->line_h / 2) * r->tex_stepy;
}

void	draw_ray(t_ray *r, t_cub *cub)
{
	int	y;

	y = 0;
	init_draywing_variables(r, cub);
	draw_walls(cub, r);
}
