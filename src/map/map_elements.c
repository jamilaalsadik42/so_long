/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalsadik <jalsadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 13:04:48 by jamila            #+#    #+#             */
/*   Updated: 2026/04/26 14:45:20 by jalsadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_count	count_elements(char **map)
{
	t_count	count;
	int		i;
	int		j;

	count.p = 0;
	count.e = 0;
	count.c = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				count.p++;
			else if (map[i][j] == 'C')
				count.c++;
			else if (map[i][j] == 'E')
				count.e++;
			j++;
		}
		i++;
	}
	return (count);
}

int	has_valid_elements(char **map)
{
	t_count	count;

	count = count_elements(map);
	if (count.p != 1)
		return (0);
	if (count.e != 1)
		return (0);
	if (count.c < 1)
		return (0);
	return (1);
}

int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
