/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_walls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 10:05:56 by jamila            #+#    #+#             */
/*   Updated: 2026/04/21 12:16:20 by jamila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static int check_i(char **map, int last_col)
{
    int i;

    i = 0;
     while (map[i])
    {
        if(map[i][0] != '1')
            return(0);
        if(map[i][last_col] != '1')
            return(0);
        i++;
    }
    return(1);
}
static int check_j(char **map, int last_row)
{
    int j;
    
    j = 0;
        while(map[0][j])
    {
        if(map[0][j] != '1')
            return(0);
        j++;
    }
    j = 0;
    while (map[last_row][j])
    {
        if(map[last_row][j] != '1')
            return(0);
        j++;   
    }
    return(1);
}
int check_valid_wall(char **map )
{
    int last_row;
    int last_col;
    int i;
    
    i = 0;
    while (map[i])
        i++;
    last_row = i - 1;
    last_col = ft_strln(map[0]) - 1;
    
    if(!check_i(map, last_col))
        return(0);
    if(!check_j(map, last_row))
        return(0);
    return(1);    
}
