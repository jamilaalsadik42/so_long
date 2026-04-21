/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:42:53 by jamila            #+#    #+#             */
/*   Updated: 2026/04/21 12:15:16 by jamila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int ft_strln(char *s)
{
    int i;

    i = 0;
    while (s[i])
    {
        i++;
    }
    return(i);    
}
int count_map_row(char **map)
{
    int count;

    count = 0 ;
    while(map[count])
    {
        count++;
    }
    return(count);
}
void free_map(char **map)
{
    int x;

    x = 0;
    while(map[x])
    {
       free(map[x]);
        x++;
    }
    free(map);
}
int check_C_E(char **dup)
{
    int x;
    int y;

    x = 0;
    while(dup[x])
    {
        y = 0;
        while (dup[x][y])
        {
            if(dup[x][y] == 'C' || dup[x][y] == 'E')
                return(0);
            y++;
        }
       x++; 
    }
    return(1);
}