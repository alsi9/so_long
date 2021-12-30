/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:59:51 by ephantom          #+#    #+#             */
/*   Updated: 2021/12/28 15:02:12 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen((char *)s1);
	str = malloc(sizeof(char) * (len + ft_strlen((char *)s2) + 1));
	if (!str)
		return (NULL);
	while (*s1)
		str[i++] = *s1++;
	while (*s2)
		str[i++] = *s2++;
	str[i] = '\0';
	free((void *)(s1 - len));
	return (str);
}

int	get_next_line(char **line, int fd)
{
	int		bytes_buf;
	char	buffer[2];

	bytes_buf = 0;
	*line = malloc(1);
	if (!(*line))
		return (-1);
	(*line)[0] = '\0';
	buffer[1] = '\0';
	while ((read(fd, buffer, 1)) > 0)
	{
		bytes_buf = 1;
		if (buffer[0] == '\n')
			break ;
		*line = ft_strjoin((*line), buffer);
	}
	if (!bytes_buf)
		free(*line);
	return (bytes_buf);
}
