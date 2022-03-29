/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuytters <tuytters@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 12:59:49 by tamighi           #+#    #+#             */
/*   Updated: 2022/02/26 15:15:44 by tamighi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/key_hook.h"

void	key_release_game(int key, t_cub *cub)
{
	if (key == K_D)
		cub->key.d = 0;
	else if (key == K_A)
		cub->key.a = 0;
	else if (key == K_S)
		cub->key.s = 0;
	else if (key == K_W)
		cub->key.w = 0;
	else if (key == K_LEFT)
		cub->key.left = 0;
	else if (key == K_RIGHT)
		cub->key.right = 0;
	else if (key == K_SPACE)
		cub->key.door_r = 1;
	else if (key == K_UP)
		cub->key.shoot_r = 1;
}

int	key_release(int key, void *param)
{
	t_cub	*cub;

	cub = (t_cub *)param;
	if (cub->game_state == GAME)
		key_release_game(key, cub);
	return (0);
}
