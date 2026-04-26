/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalsadik <jalsadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 11:02:11 by jamila            #+#    #+#             */
/*   Updated: 2026/04/26 14:49:17 by jalsadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	find_player(char **map, int *row, int *col)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == 'P')
			{
				*row = x;
				*col = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

static void	copy_to_dup(char **map, char **dup, int size)
{
	int	x;
	int	y;

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

char	**duplicate_map(char **map)
{
	int		size;
	char	**dup;
	int		x;
	int		y;

	x = 0;
	size = count_map_row(map);
	if (size <= 0)
		return (NULL);
	dup = malloc(sizeof(char *) * (size + 1));
	if (!dup)
		return (NULL);
	while (map[x])
	{
		y = ft_strln(map[x]);
		dup[x] = malloc(sizeof(char) * (y + 1));
		if (!dup[x])
			return (free_partial(dup, x), NULL);
		x++;
	}
	copy_to_dup(map, dup, size);
	return (dup);
}

static void	flood_fill(char **map, int row, int col, int *size)
{
	if (row < 0 || col < 0 || row >= size[0] || col >= size[1]
		|| map[row][col] == '1' || map[row][col] == 'X')
		return ;
	if (map[row][col] == 'E')
	{
		map[row][col] = 'X';
		return ;
	}
	map[row][col] = 'X';
	flood_fill(map, row - 1, col, size);
	flood_fill(map, row + 1, col, size);
	flood_fill(map, row, col - 1, size);
	flood_fill(map, row, col + 1, size);
}

int	check_path(char **map)
{
	char	**dup;
	int		row;
	int		col;
	int		size[2];

	row = -1;
	col = -1;
	size[0] = count_map_row(map);
	size[1] = ft_strln(map[0]);
	dup = duplicate_map(map);
	if (!dup)
		return (0);
	find_player(dup, &row, &col);
	if (row == -1 || col == -1)
		return (free_map(dup), 0);
	flood_fill(dup, row, col, size);
	if (!check_c_e(dup))
		return (free_map(dup), 0);
	return (free_map(dup), 1);
}
