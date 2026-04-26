/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 02:19:32 by jamila            #+#    #+#             */
/*   Updated: 2026/04/25 18:25:18 by jamila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/so_long.h"

int main(int argc, char **argv)
{
    t_game game;
    
    if(argc != 2)
        error_exit("Usage: ./so_long map.ber\n");
    game.map = read_map(argv[1]);
    if(!game.map)
        error_exit("Map Read Failed\n");
    if(!validate_map(game.map))
        error_exit("Invalid Map\n");
    game.moves = 0;
    game.collectibles = Count_collectibles(game.map);
    find_player(game.map, &game.player_row, &game.player_col);
    game.map_height = count_map_row(game.map);
    game.map_width = ft_strln(game.map[0]);
    game.mlx = mlx_init();
    if(!game.mlx)
        error_exit("mlx_init failed \n");
    game.win = mlx_new_window(game.mlx,
        game.map_width * TILE_SIZE,
        game.map_height * TILE_SIZE,
        "so_long");
    if(!game.win)
        error_exit("mlx_new_window  failed \n");
    render_map(&game);
    mlx_key_hook(game.win, key_hook, &game);
    mlx_loop(game.mlx);
    return(0);
}
