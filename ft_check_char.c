/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:03:34 by ephantom          #+#    #+#             */
/*   Updated: 2021/12/27 15:48:53 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_filename(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	while (str && i < len - 4)
	{
		str++;
		i++;
	}
	if (ft_strncmp(str, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	check_rectangle(t_game_map *m, int i, int count_str)
{
	int	n;
	int	n1;

	while (i < count_str - 1)
	{
		n = ft_strlen(m->map_data[i]);
		n1 = ft_strlen(m->map_data[i + 1]);
		if (n != n1)
			return (-6);
		i++;
	}
	return (0);
}

int	check_char_and_coin(t_game_map *m, int *coin, int i, int j)
{
	while (m->map_data[i])
	{
		j = 0;
		while (m->map_data[i][j])
		{
			if (m->map_data[i][j] != '1' && m->map_data[i][j] != '0'
			&& m->map_data[i][j] != 'C' && m->map_data[i][j] != 'P'
			&& m->map_data[i][j] != 'E')
				return (-4);
			if (m->map_data[i][j] == 'C')
				(*coin)++;
			j++;
		}
		i++;
	}
	m->max_score = *coin;
	if (*coin == 0)
		return (-5);
	return (0);
}

int	check_exit_person(t_game_map *m, int i, int j)
{
	int	exit;
	int	person;

	exit = 0;
	person = 0;
	while (m->map_data[++i])
	{
		j = 0;
		while (m->map_data[i][++j])
		{
			if (m->map_data[i][j] == 'E')
				exit++;
			if (m->map_data[i][j] == 'P')
			{
				m->pos_x = j;
				m->pos_y = i;
				person++;
			}
		}
	}
	if (exit <= 0)
		return (-2);
	if (person != 1)
		return (-3);
	return (0);
}

int	check_wall(t_game_map *m, int i, int j, int count_str)
{
	int	max_i;
	int	max_j;

	max_i = count_str - 1;
	max_j = (ft_strlen(m->map_data[0])) - 1;
	m->map_lenght = (ft_strlen(m->map_data[0]));
	m->map_height = count_str;
	while (m->map_data[i])
	{
		j = 0;
		while (m->map_data[i][j])
		{
			if (m->map_data[0][j] != '1' || m->map_data[i][0] != '1'
			|| m->map_data[max_i][j] != '1' || m->map_data[i][max_j] != '1')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
