/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nums.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalsadik <jalsadik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:40:00 by jalsadik          #+#    #+#             */
/*   Updated: 2025/08/29 13:53:53 by jalsadik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_hex(unsigned long n, const char *base)
{
	int	len;
	int	res;

	len = 0;
	if (n >= 16)
	{
		res = put_hex(n / 16, base);
		if (res < 0)
			return (-1);
		len += res;
	}
	res = write(1, &base[n % 16], 1);
	if (res < 0)
		return (-1);
	return (len + 1);
}

int	ft_print_nbr(int n)
{
	long	num;
	int		len;
	int		res;

	num = n;
	len = 0;
	if (num < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		num = -num;
		len++;
	}
	if (num >= 10)
	{
		res = ft_print_nbr(num / 10);
		if (res < 0)
			return (-1);
		len += res;
	}
	if (write(1, &"0123456789"[num % 10], 1) < 0)
		return (-1);
	return (len + 1);
}

int	ft_print_unsigned(unsigned int n)
{
	int	len;
	int	res;

	len = 0;
	if (n >= 10)
	{
		res = ft_print_unsigned(n / 10);
		if (res < 0)
			return (-1);
		len += res;
	}
	if (write(1, &"0123456789"[n % 10], 1) < 0)
		return (-1);
	return (len + 1);
}

int	ft_print_hex(unsigned int n, char format)
{
	if (format == 'x')
		return (put_hex(n, "0123456789abcdef"));
	return (put_hex(n, "0123456789ABCDEF"));
}

int	ft_print_ptr(void *ptr)
{
	int	len;
	int	res;

	if (!ptr)
		return (write(1, "0x0", 3));
	len = write(1, "0x", 2);
	if (len < 0)
		return (-1);
	res = put_hex((unsigned long)ptr, "0123456789abcdef");
	if (res < 0)
		return (-1);
	return (len + res);
}
