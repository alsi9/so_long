/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:05:16 by ephantom          #+#    #+#             */
/*   Updated: 2021/12/27 19:08:58 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_go_front(t_game_map *m)
{
	if (m->map_data[m->pos_y - 1][m->pos_x] == 'C'
	|| m->map_data[m->pos_y - 1][m->pos_x] == '0')
	{
		if (m->map_data[m->pos_y - 1][m->pos_x] == 'C')
			(m->game_score)++;
		m->map_data[m->pos_y - 1][m->pos_x] = 'P';
		m->map_data[m->pos_y--][m->pos_x] = '0';
		return (1);
	}
	if ((m->map_data[m->pos_y - 1][m->pos_x] == 'E')
	&& (m->game_score == m->max_score))
		exit(0);
	return (0);
}

static int	ft_go_back(t_game_map *m)
{
	if (m->map_data[m->pos_y + 1][m->pos_x] == 'C'
	|| m->map_data[m->pos_y + 1][m->pos_x] == '0')
	{
		if (m->map_data[m->pos_y + 1][m->pos_x] == 'C')
			(m->game_score)++;
		m->map_data[m->pos_y + 1][m->pos_x] = 'P';
		m->map_data[m->pos_y++][m->pos_x] = '0';
		return (1);
	}
	if ((m->map_data[m->pos_y + 1][m->pos_x] == 'E')
	&& (m->game_score == m->max_score))
		exit(0);
	return (0);
}

static int	ft_go_left(t_game_map *m)
{
	if (m->map_data[m->pos_y][m->pos_x - 1] == 'C'
	|| m->map_data[m->pos_y][m->pos_x - 1] == '0')
	{
		if (m->map_data[m->pos_y][m->pos_x - 1] == 'C')
			(m->game_score)++;
		m->map_data[m->pos_y][m->pos_x - 1] = 'P';
		m->map_data[m->pos_y][m->pos_x--] = '0';
		return (1);
	}
	if ((m->map_data[m->pos_y][m->pos_x - 1] == 'E')
	&& (m->game_score == m->max_score))
		exit(0);
	return (0);
}

static int	ft_go_right(t_game_map *m)
{
	if (m->map_data[m->pos_y][m->pos_x + 1] == 'C'
	|| m->map_data[m->pos_y][m->pos_x + 1] == '0')
	{
		if (m->map_data[m->pos_y][m->pos_x + 1] == 'C')
			(m->game_score)++;
		m->map_data[m->pos_y][m->pos_x + 1] = 'P';
		m->map_data[m->pos_y][m->pos_x++] = '0';
		return (1);
	}
	if ((m->map_data[m->pos_y][m->pos_x + 1] == 'E')
	&& (m->game_score == m->max_score))
		exit(0);
	return (0);
}

int	ft_key_hook(int keycode, t_game_map *m)
{
	int			step;
	static int	steps;

	step = 0;
	if (keycode == 13)
		step += ft_go_front(m);
	else if (keycode == 1)
		step += ft_go_back(m);
	else if (keycode == 0)
		step += ft_go_left(m);
	else if (keycode == 2)
		step += ft_go_right(m);
	else if (keycode == 53)
		exit(0);
	if (step != 0)
	{
		printf("Moves: %d\n", ++steps);
		ft_render(m);
	}
	return (0);
}
