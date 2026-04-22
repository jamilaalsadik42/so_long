/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 11:27:16 by jamila            #+#    #+#             */
/*   Updated: 2026/04/22 19:04:38 by jamila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"
#include<stdio.h>
int key_hook(int keycode, t_game *game)
{
    int next_row;
    int next_col;

    next_row = game->player_row;
    next_col = game->player_col;
    if (keycode == 65307)
		exit(0);
    if(keycode == 119)
        next_row--;
    if(keycode == 97)
        next_col--;
    if (keycode == 115)
        next_row++;
    if (keycode == 100)
        next_col++;
    if (next_row == game->player_row && next_col == game->player_col)
        return (0);
     if(game->map[next_row][next_col] == '1')
        return(0);
    if(game->map[next_row][next_col] == 'E')
    {
        if(game->collectibles == 0)
        {
            write(1,"You Win!!",10);
            exit(0);
        }
        return(0);
    }
    if(game->map[next_row][next_col] == 'C')
        game->collectibles--;
    game->map[game->player_row][game->player_col] = '0';
    game->map[next_row][next_col] = 'P';
    game->player_row = next_row;
    game->player_col = next_col;
    game->moves++;
    printf("Moves: %d\n", game->moves);
    mlx_clear_window(game->mlx, game->win);
    render_map(game);
    return (0);
}
