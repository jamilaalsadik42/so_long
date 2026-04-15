/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 02:19:32 by jamila            #+#    #+#             */
/*   Updated: 2026/04/08 11:15:43 by jamila           ###   ########.fr       */
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
    ///////testing///////////////////////////
    printf("Lines: %d\n", count_lines(argv[1]));
    char **map;
    int i;
    map = read_map(argv[1]);
    if(!map)
        return(1);
    i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
    if (is_rectangular(map))
    	printf("Map is rectangular\n");
    else
	    printf("Map is NOT rectangular\n");
    if (has_valid_chars(map))
	    printf("Map has valid characters\n");
    else
	    printf("Map has invalid characters\n");
    if (has_valid_elements(map))
	    printf("Map has valid P, E, and C counts\n");
    else
	    printf("Map has invalid P, E, or C counts\n");
    t_count	count;
    if(check_valid_wall(map))
        printf("valid wall provided\n");
    else
        printf("invalid wall provided\n");

    count = count_elements(map);
    printf("P: %d, E: %d, C: %d\n", count.p, count.e, count.c);
    int row;
    int col;
    find_player(map, &row, &col);
    printf("player is at (%d , %d)\n",row, col);
    /////////////////////////////////////////////
    game.mlx = mlx_init();
    if(!game.mlx)
        error_exit("mlx_init failed \n");
    game.win = mlx_new_window(game.mlx, 800, 600, "so_long");
    if(!game.win)
        error_exit("mlx_new_window  failed \n");
    mlx_loop(game.mlx);
    return(0);
}