/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 09:19:37 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 15:52:27 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "global.h"

void			view_casting(t_cub *cub);
void			hit_wall_check(t_ray *r, t_cub *cub);
void			f_c_casting(t_ray *r, t_cub *cub);
void			draw_sprites(t_ray *r, t_cub *cub);
void			sprites_init(t_ray *r, t_cub *cub);
void			s_draw_start_end_fct(t_spr *spr);
void			mkits_in_sprites(t_cub *cub, int *j, t_ray *r);
void			hit_wall_check(t_ray *r, t_cub *cub);
void			draw_line(t_ray *r, t_cub *cub);
void			draw_img(t_cub *cub, t_img img, int start_y, int start_x);

void			display_map(t_cub *cub);
void			display_char(t_cub *cub);
void			display_gun(t_cub *cub);
void			display_menubar(t_cub *cub);

void			put_my_pixel(t_img img, int y, int x, unsigned int color);
unsigned int	get_texture_color(t_img text, int y, int x);
int				is_door(t_door *d, int y, int x);
int				is_ennemy(t_en *en, int y, int x);
int				is_element_before_wall(t_cub *cub, int y, int x);
int				is_raycast_end(t_cub *cub, int y, int x);
void			optimisation_pixel_put(t_img img,
					int y, int x, unsigned int color);
void			optimisation_pixel_put2(t_img img,
					int y, int x, unsigned int color);

void			draw_text(t_cub *cub, int start_y, int *start_x, char *str);
void			draw_nb(t_cub *cub, int start_y, int *start_x, int nb);

#endif
