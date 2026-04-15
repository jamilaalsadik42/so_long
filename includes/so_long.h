/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 02:18:49 by jamila            #+#    #+#             */
/*   Updated: 2026/04/08 11:09:18 by jamila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct s_game
{
    void *mlx;
    void *win;
    char **map;//2D array of strings
    int map_height;//height of map
} t_game;
typedef struct s_count
{
    int p;
    int e;
    int c;
}   t_count;
void    error_exit(const char *msg);
int     count_lines(char *filename);
char    **read_map(char *filename);
void    remove_newline(char *line);
int     ft_strln(char *s);
int     is_rectangular(char **map);
int     is_valid_char(char c);
int     has_valid_chars(char **map);
t_count	count_elements(char **map);
int		has_valid_elements(char **map);
int     check_valid_wall(char **map );
void    find_player(char **map, int *row, int *col);
int     count_map_row(char **map);
char    **duplicate_map(char **map);
void    free_map(char **map);

#endif