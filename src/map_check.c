/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:16:43 by jamila            #+#    #+#             */
/*   Updated: 2026/04/08 11:14:46 by jamila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include <fcntl.h>

int is_rectangular(char **map)
{
    int i;
    int width;
    if(!map || !map[0])
        return(0);
    width = ft_strlen(map[0]);
    i = 1;
    while (map[i])
    {
        if(width != ft_strlen(map[i]))
            return (0);
        i++;
    }
    return(1);
    
}
int is_valid_char(char c)
{
    if(c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
        return(1);
    return(0);
}
int has_valid_chars(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if(!is_valid_char(map[i][j]))
                return(0);
            j++;
        }
        i++;
    }
    return(1);
}
int check_i(char **map, int last_col)
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
int check_j(char **map, int last_row)
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
    last_col = ft_strlen(map[0]) - 1;
    
    if(!check_i(map, last_col))
        return(0);
    if(!check_j(map, last_row))
        return(0);
    return(1);    
}
