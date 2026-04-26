/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalsadik <jalsadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 11:42:53 by jamila            #+#    #+#             */
/*   Updated: 2026/04/26 15:21:06 by jalsadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_strln(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	count_map_row(char **map)
{
	int	count;

	count = 0;
	while (map[count])
		count++;
	return (count);
}

void	free_map(char **map)
{
	int	x;

	x = 0;
	while (map[x])
	{
		free(map[x]);
		x++;
	}
	free(map);
}

int	check_c_e(char **dup)
{
	int	x;
	int	y;

	x = 0;
	while (dup[x])
	{
		y = 0;
		while (dup[x][y])
		{
			if (dup[x][y] == 'C' || dup[x][y] == 'E')
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int	close_window(t_game *game)
{
	clean_exit(game);
	return (0);
}
