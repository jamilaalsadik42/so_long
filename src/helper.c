/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:42:53 by jamila            #+#    #+#             */
/*   Updated: 2026/03/24 11:44:23 by jamila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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