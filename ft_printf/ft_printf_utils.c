/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalsadik <jalsadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:40:00 by jalsadik          #+#    #+#             */
/*   Updated: 2025/09/01 10:00:30 by jalsadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *s)
{
	int	len;
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	len = 0;
	while (s[i])
	{
		if (write(1, &s[i], 1) < 0)
			return (-1);
		i++;
		len++;
	}
	return (len);
}
