/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:16:43 by jamila            #+#    #+#             */
/*   Updated: 2026/04/21 11:06:45 by jamila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
int validate_map(char **map)
{
    if(!is_rectangular(map))
        return(0);
    if (!has_valid_chars(map))
        return(0);
    if(!has_valid_elements(map))
        return(0);
    if (!check_valid_wall(map))
        return(0);
    if(!check_path(map))
        return(0);

    return(1);
}