/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:13:34 by jalsadik          #+#    #+#             */
/*   Updated: 2026/04/28 20:40:51 by jamila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	put_tile(t_game *game, int i, int j)
{
	int	x;
	int	y;

	x = j * TILE_SIZE;
	y = i * TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win, game->floor_img, x, y);
	if (game->map[i][j] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img, x, y);
	else if (game->map[i][j] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible_img, x, y);
	else if (game->map[i][j] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit_img, x, y);
	else if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player_img, x, y);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			put_tile(game, i, j);
			j++;
		}
		i++;
	}
}

int	expose_hook(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	return (0);
}
