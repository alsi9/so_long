/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:54:51 by ephantom          #+#    #+#             */
/*   Updated: 2021/12/29 17:03:15 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_enemy(t_game_map *m, int i, int j, int count)
{
	i = m->map_height - 1;
	while (--i > 0)
	{
		j = m->map_lenght - 1;
		while (--j > 0)
		{
			if (m->map_data[i][j] == '0')
			{
				if (count == 0 && m->map_data[i][j - 1] == '0')
				{
					m->map_data[i][j - 1] = 'Z';
					count = 1;
					i -= 2;
				}
				else if (count == 1 && m->map_data[i][j - 1] == '0')
				{
					m->map_data[i][j - 1] = 'W';
					count = 2;
					break ;
				}
			}
		}
	}
}

void	ft_go_enem_one(t_game_map *m, int i, int j)
{
	static int	left;

	if (left == 1 && (m->map_data[i][j - 1] == '0'
		|| m->map_data[i][j - 1] == 'P'))
	{
		if (m->map_data[i][j - 1] == 'P')
			ft_error("Game over!\n");
		if (m->map_data[i][j - 2] != '0'
			&& m->map_data[i][j - 2] != 'P')
			left = 0;
		m->map_data[i][j - 1] = 'Z';
		m->map_data[i][j--] = '0';
	}
	else if (left == 0 && (m->map_data[i][j + 1] == '0'
		|| m->map_data[i][j + 1] == 'P'))
	{
		if (m->map_data[i][j + 1] == 'P')
			ft_error("Game over!\n");
		if (m->map_data[i][j + 2] != '0'
			&& m->map_data[i][j + 2] != 'P')
			left = 1;
		m->map_data[i][j + 1] = 'Z';
		m->map_data[i][j++] = '0';
	}
}

void	ft_go_enem_two(t_game_map *m, int i, int j)
{
	static int	front;

	if (front == 1 && (m->map_data[i - 1][j] == '0'
		|| m->map_data[i - 1][j] == 'P'))
	{
		if (m->map_data[i - 1][j] == 'P')
			ft_error("Game over!\n");
		if (m->map_data[i - 2][j] != '0'
			&& m->map_data[i - 2][j] != 'P')
			front = 0;
		m->map_data[i - 1][j] = 'W';
		m->map_data[i--][j] = '0';
	}
	else if (front == 0 && (m->map_data[i + 1][j] == '0'
		|| m->map_data[i + 1][j] == 'P'))
	{
		if (m->map_data[i + 1][j] == 'P')
			ft_error("Game over!\n");
		if (m->map_data[i + 2][j] != '0'
			&& m->map_data[i + 2][j] != 'P')
			front = 1;
		m->map_data[i + 1][j] = 'W';
		m->map_data[i++][j] = '0';
	}
}

void	enemy_one(t_game_map *m, int i, int j)
{
	static int	time;

	time++;
	if ((time % 10) == 0)
	{
		while (m->map_data[++i])
		{
			j = -1;
			while (m->map_data[i][++j])
			{
				if (m->map_data[i][j] == 'Z')
				{
					ft_go_enem_one(m, i, j);
					ft_render_bonus(m, -1, -1);
					return ;
				}
			}
		}
	}
}

void	enemy_two(t_game_map *map, int i, int j)
{
	static int	time;

	time++;
	if ((time % 10) == 0)
	{
		while (map->map_data[++i])
		{
			j = -1;
			while (map->map_data[i][++j])
			{
				if (map->map_data[i][j] == 'W')
				{
					ft_go_enem_two(map, i, j);
					ft_render_bonus(map, -1, -1);
					return ;
				}
			}
		}
	}
}
