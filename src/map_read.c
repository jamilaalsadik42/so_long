/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 02:52:05 by jamila            #+#    #+#             */
/*   Updated: 2026/03/24 12:16:39 by jamila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../get_next_line/get_next_line.h"
#include <fcntl.h>

int count_lines(char *filename)
{
 int    fd;
 int    count;
 char   *line;
 
 fd = open(filename, O_RDONLY);
 if(fd < 0)
    return(-1);
count = 0;
line = get_next_line(fd);
while (line)
{
    count++;
    free(line);
    line = get_next_line(fd);
}
close(fd);
return(count);

}

char **read_map(char *filename)
{
    int fd;
    int i;
    int lines;
    char    **map;
    
    lines = count_lines(filename);
    if(lines <= 0)
        return(NULL);
    map = malloc(sizeof(char*)* (lines + 1));
    if(!map)
        return(NULL);
    fd = open(filename, O_RDONLY);
    if(fd < 0)
        return(free(map), NULL);
    i = 0;
    map[i] = get_next_line(fd);
    while (map[i])
    {
        remove_newline(map[i]);
        i++;
        map[i] = get_next_line(fd);
    }
    close(fd);
    return(map);
}
void    remove_newline(char *line)
{
    int i;
    
    i = 0;
    while (line[i])
    {
        if(line[i] == '\n')
        {
            line[i] = '\0';
            return;
        }
        i++;
    }
    
}
