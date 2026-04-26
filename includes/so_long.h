/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamila <jamila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 02:18:49 by jamila            #+#    #+#             */
/*   Updated: 2026/04/26 08:21:54 by jamila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

#include "../minilibx-linux/mlx.h"
#include "../get_next_line/get_next_line.h"
#include<stdlib.h>
#include<unistd.h>

# define TILE_SIZE 64
typedef struct s_game
{
    void *mlx;
    void *win;
    char **map;
    int map_height;
    int map_width;
    int	player_row;
	int	player_col;
	int	moves;
    int	collectibles;
    void *wall_img;
    void *floor_img;
    void *player_img;
    void *collectible_img;
    void *exit_img;
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
int     Count_collectibles(char **map);
int     check_valid_wall(char **map );
void    find_player(char **map, int *row, int *col);
int     count_map_row(char **map);
char    **duplicate_map(char **map);
void    free_map(char **map);
void	flood_fill(char **map, int row, int col, int cols, int rows);
int     check_path(char **map);
int     check_C_E(char **dup);
int     validate_map(char **map);
void	draw_square(t_game *game, int row, int col, int color);
void	render_map(t_game *game);
int     key_hook(int keycode, t_game *game);
#endif