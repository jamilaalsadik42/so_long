/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:02:11 by jamila            #+#    #+#             */
/*   Updated: 2026/04/08 12:05:44 by jamila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

