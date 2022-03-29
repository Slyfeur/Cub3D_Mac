/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 10:11:00 by tamighi           #+#    #+#             */
/*   Updated: 2022/03/01 15:58:24 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/global.h"

void	free_my_imgs(t_cub *cub, t_img *imgs)
{
	int	i;

	i = 0;
	while (imgs[i].img)
		mlx_destroy_image(cub->mlx.mlx, imgs[i++].img);
}

void	free_my_arr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	free_all_imgs(t_cub *cub)
{
	int	j;

	j = 0;
	while (j < NB_SPR)
		free_my_imgs(cub, cub->sprites[j++]);
	free_my_imgs(cub, cub->textures);
	if (cub->display.img)
		mlx_destroy_image(cub->mlx.mlx, cub->display.img);
}

void	free_rest_of_struct(t_cub *cub)
{
	int	i;

	i = -1;
	if (cub->doors)
		free(cub->doors);
	if (cub->en)
		free(cub->en);
	if (cub->sprs)
		free(cub->sprs);
	if (cub->mkits)
		free(cub->mkits);
	while (cub->map_dist && cub->map_dist[++i])
		free(cub->map_dist[i]);
	if (cub->map_dist)
		free(cub->map_dist);
}

void	free_and_exit(t_cub *cub, int error)
{
	free_my_arr(cub->map);
	free_all_imgs(cub);
	free_rest_of_struct(cub);
	if (cub->mlx.mlx && cub->mlx.win)
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
	exit(error);
}
