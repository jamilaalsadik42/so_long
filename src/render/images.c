/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalsadik <jalsadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 12:15:44 by jalsadik          #+#    #+#             */
/*   Updated: 2026/04/26 14:53:42 by jalsadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	load_image(void *mlx, void **img, char *path)
{
	int	w;
	int	h;

	*img = mlx_xpm_file_to_image(mlx, path, &w, &h);
}

void	load_images(t_game *game)
{
	load_image(game->mlx, &game->wall_img, "textures/wall.xpm");
	load_image(game->mlx, &game->floor_img, "textures/floor.xpm");
	load_image(game->mlx, &game->player_img, "textures/player.xpm");
	load_image(game->mlx, &game->collectible_img,
		"textures/collectible.xpm");
	load_image(game->mlx, &game->exit_img, "textures/exit.xpm");
	if (!game->wall_img || !game->floor_img || !game->player_img
		|| !game->collectible_img || !game->exit_img)
		error_exit("Error loading images\n");
}
