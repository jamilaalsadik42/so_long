/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalsadik <jalsadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:27:16 by jamila            #+#    #+#             */
/*   Updated: 2026/04/26 15:32:52 by jalsadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int	is_arrow_key(int keycode, int *next_row, int *next_col)
{
	if (keycode == 65362)
		(*next_row)--;
	else if (keycode == 65361)
		(*next_col)--;
	else if (keycode == 65364)
		(*next_row)++;
	else if (keycode == 65363)
		(*next_col)++;
	else
		return (0);
	return (1);
}

static int	keycode_condition(int keycode, t_game *game,
		int *next_row, int *next_col)
{
	if (keycode == 65307)
		clean_exit(game);
	if (!is_arrow_key(keycode, next_row, next_col))
		return (0);
	if (game->map[*next_row][*next_col] == '1')
		return (0);
	if (game->map[*next_row][*next_col] == 'E')
	{
		if (game->collectibles == 0)
		{
			write(1, "You Win!!\n", 11);
			clean_exit(game);
		}
		return (0);
	}
	return (1);
}

int	key_hook(int keycode, t_game *game)
{
	int	next_row;
	int	next_col;

	next_row = game->player_row;
	next_col = game->player_col;
	if (!keycode_condition(keycode, game, &next_row, &next_col))
		return (0);
	if (game->map[next_row][next_col] == 'C')
		game->collectibles--;
	game->map[game->player_row][game->player_col] = '0';
	game->map[next_row][next_col] = 'P';
	game->player_row = next_row;
	game->player_col = next_col;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	mlx_clear_window(game->mlx, game->win);
	render_map(game);
	return (0);
}
