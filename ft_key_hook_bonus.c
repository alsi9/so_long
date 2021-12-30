/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:05:16 by ephantom          #+#    #+#             */
/*   Updated: 2021/12/29 16:58:34 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_go_front(t_game_map *m)
{
	if (m->map_data[m->pos_y - 1][m->pos_x] == 'C'
	|| m->map_data[m->pos_y - 1][m->pos_x] == '0'
	|| m->map_data[m->pos_y - 1][m->pos_x] == 'Z'
	|| m->map_data[m->pos_y - 1][m->pos_x] == 'W')
	{
		if (m->map_data[m->pos_y - 1][m->pos_x] == 'C')
			(m->game_score)++;
		if (m->map_data[m->pos_y - 1][m->pos_x] == 'Z'
		|| m->map_data[m->pos_y - 1][m->pos_x] == 'W')
			ft_error("Game over!\n");
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
	|| m->map_data[m->pos_y + 1][m->pos_x] == '0'
	|| m->map_data[m->pos_y + 1][m->pos_x] == 'Z'
	|| m->map_data[m->pos_y + 1][m->pos_x] == 'W')
	{
		if (m->map_data[m->pos_y + 1][m->pos_x] == 'C')
			(m->game_score)++;
		if (m->map_data[m->pos_y + 1][m->pos_x] == 'Z'
		|| m->map_data[m->pos_y + 1][m->pos_x] == 'W')
			ft_error("Game over!\n");
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
	|| m->map_data[m->pos_y][m->pos_x - 1] == '0'
	|| m->map_data[m->pos_y][m->pos_x - 1] == 'Z'
	|| m->map_data[m->pos_y][m->pos_x - 1] == 'W')
	{
		if (m->map_data[m->pos_y][m->pos_x - 1] == 'C')
			(m->game_score)++;
		if (m->map_data[m->pos_y][m->pos_x - 1] == 'Z'
		|| m->map_data[m->pos_y][m->pos_x - 1] == 'W')
			ft_error("Game over!\n");
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
	|| m->map_data[m->pos_y][m->pos_x + 1] == '0'
	|| m->map_data[m->pos_y][m->pos_x + 1] == 'Z'
	|| m->map_data[m->pos_y][m->pos_x + 1] == 'W')
	{
		if (m->map_data[m->pos_y][m->pos_x + 1] == 'C')
			(m->game_score)++;
		if (m->map_data[m->pos_y][m->pos_x + 1] == 'Z'
		|| m->map_data[m->pos_y][m->pos_x + 1] == 'W')
			ft_error("Game over!\n");
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
		m->steps += 1;
		ft_render_bonus(m, -1, -1);
	}
	return (0);
}
