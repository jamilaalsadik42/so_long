/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalsadik <jalsadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:13:34 by jalsadik          #+#    #+#             */
/*   Updated: 2026/04/21 18:19:22 by jalsadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_square(t_game *game, int row, int col, int color)
{
	int x;
	int y;
	int i;
	int j;
	
	x = col * TILE_SIZE;
	y = row * TILE_SIZE;
	i = 0;
	while(i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
		mlx_pixel_put(game->mlx, game->win,x+j, y+i, color);
			j++;
		}
		i++;
	}
}
void	render_map(t_game *game)
{
	int i;
	int j;
	
	i = 0;
	while(i < game->map_height)
	{
		j = 0;
		while (j < game->map_width)
		{
			if(game->map[i][j] == '1')
				draw_square(game, i, j, 0x9C3E07);
			else if(game->map[i][j] == 'E')
				draw_square(game, i, j, 0x27F5A9);
			else if(game->map[i][j] == 'C')
				draw_square(game, i, j, 0xF5E427);
			else if(game->map[i][j] == 'P')
				draw_square(game, i, j, 0x2AF527);
			else if(game->map[i][j] == '0')
				draw_square(game, i, j, 0x63ADF8);
			j++;	
		}
		i++;
	}
}