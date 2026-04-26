/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalsadik <jalsadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 02:19:32 by jamila            #+#    #+#             */
/*   Updated: 2026/04/26 14:39:00 by jalsadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	init_game_data(t_game *game)
{
	game->moves = 0;
	game->collectibles = count_collectibles(game->map);
	find_player(game->map, &game->player_row, &game->player_col);
	game->map_height = count_map_row(game->map);
	game->map_width = ft_strln(game->map[0]);
}

static void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("mlx_init failed\n");
	load_images(game);
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "so_long");
	if (!game->win)
		error_exit("mlx_new_window failed\n");
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		error_exit("Usage: ./so_long map.ber\n");
	game.map = read_map(argv[1]);
	if (!game.map)
		error_exit("Map Read Failed\n");
	if (!validate_map(game.map))
		error_exit("Invalid Map\n");
	init_game_data(&game);
	init_window(&game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	render_map(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
