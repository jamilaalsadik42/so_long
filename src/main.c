/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 02:19:32 by jamila            #+#    #+#             */
/*   Updated: 2026/04/21 11:10:27 by jamila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"
#include <stdio.h>
int main(int argc, char **argv)
{
    t_game game;
    
    if(argc != 2)
        error_exit("Usage: ./so_long map.ber\n");
    (void)argv;
    game.mlx = mlx_init();
    if(!game.mlx)
        error_exit("mlx_init failed \n");
    game.win = mlx_new_window(game.mlx, 800, 600, "so_long");
    if(!game.win)
        error_exit("mlx_new_window  failed \n");
    mlx_loop(game.mlx);
    return(0);
}