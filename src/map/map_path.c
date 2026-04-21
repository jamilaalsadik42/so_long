/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:02:11 by jamila            #+#    #+#             */
/*   Updated: 2026/04/21 12:15:54 by jamila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void    find_player(char **map, int *row, int *col)
{
    int x;
    int y;

    x = 0;
    while (map[x])
    {
        y = 0;
        while (map[x][y])
        {
            if(map[x][y] == 'P')
                {
                    *row = x;
                    *col = y;
                    return;
                }
            y++;
        }
        x++;
    }
}
static void copy_to_dup(char **map, char **dup, int size)
{
    int     x;
    int     y;

    x = 0;
    while (map[x])
    {
        y = 0; 
        while (map[x][y])
        {
            dup[x][y] = map[x][y];
            y++;
        }
        dup[x][y] = '\0';
        x++;
    }
    dup[size] = NULL;
}

char **duplicate_map(char **map)
{
    int     size;
    char    **dup;
    int     x;
    int     y;
    
    x = 0;
    size = count_map_row(map);
    if(size <= 0)
        return(NULL);
    dup = malloc(sizeof(char*)* (size + 1));
    if(!dup)
        return(NULL);
    while (map[x])
    {
        y = 0;
        while (map[x][y])
            y++;
        dup[x] = malloc(sizeof(char) * (y + 1));
        if(!dup[x])
            return(NULL);
        x++;
    }
    copy_to_dup(map, dup, size);
    return(dup);
}
void	flood_fill(char **map, int row, int col, int rows, int cols)
{
    if((row < 0) || (col < 0) ||  row >= rows || col >= cols 
    || map[row][col] == '1' || map[row][col] == 'X' )
        return;
    map[row][col] = 'X';
    flood_fill(map, row - 1, col, rows, cols); // up
	flood_fill(map, row + 1, col, rows, cols); // down
	flood_fill(map, row, col - 1, rows, cols); // left
	flood_fill(map, row, col + 1, rows, cols); // right
}
int check_path(char **map)
{
    char **dup;
    int row;
    int col;
    int cols;
    int rows;

    cols = ft_strln(map[0]);
    rows = count_map_row(map);
    dup = duplicate_map(map);
    if (!dup)
        return (0);
    find_player(dup,&row, &col);
    flood_fill(dup, row, col, rows, cols);
    if(!check_C_E(dup))
      return(free_map(dup),0);  
    return(free_map(dup),1);
}
