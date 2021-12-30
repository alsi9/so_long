/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:04:17 by ephantom          #+#    #+#             */
/*   Updated: 2021/10/19 10:37:20 by ephantom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_count(int n, int len)
{
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static int	ft_exclusion(int m, char *dst, int i)
{
	if (m == -2147483648)
	{
		dst[i] = '-';
		dst[i + 1] = '2';
		m = 147483648;
		return (m);
	}
	else if (m < 0)
	{
		dst[i] = '-';
		m = m * -1;
		return (m);
	}
	return (0);
}

char	*ft_itoa(int n)
{
	char	*dst;
	int		len;
	int		i;
	int		m;

	len = 0;
	i = 0;
	if (n <= 0)
		len = 1;
	m = n;
	len = ft_count(n, len);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == 0)
		return (0);
	if (ft_exclusion(m, dst, i))
		m = ft_exclusion(m, dst, i);
	i = len - 1;
	while (m > 9)
	{
		dst[i--] = m % 10 + 48;
		m = m / 10;
	}
	dst[i] = m % 10 + 48;
	dst[len] = '\0';
	return (dst);
}
