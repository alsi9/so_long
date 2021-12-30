/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:54:39 by ephantom          #+#    #+#             */
/*   Updated: 2021/12/29 17:04:42 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_animation(t_game_map *m)
{
	int	a;

	m->anim.pic0 = mlx_xpm_file_to_image(m->mlx, "anim/jewel1_0.xpm", &a, &a);
	m->anim.pic1 = mlx_xpm_file_to_image(m->mlx, "anim/jewel1_1.xpm", &a, &a);
	m->anim.pic2 = mlx_xpm_file_to_image(m->mlx, "anim/jewel1_2.xpm", &a, &a);
	m->anim.pic3 = mlx_xpm_file_to_image(m->mlx, "anim/jewel1_3.xpm", &a, &a);
	m->anim.pic4 = mlx_xpm_file_to_image(m->mlx, "anim/jewel1_4.xpm", &a, &a);
	m->anim.pic5 = mlx_xpm_file_to_image(m->mlx, "anim/jewel1_5.xpm", &a, &a);
}

void	ft_put_animation(int i, int j, t_game_map *m, int an)
{
	if (an == 0)
		mlx_put_image_to_window(m->mlx, m->wn,
			m->anim.pic0, j * 40, i * 40);
	else if (an == 1)
		mlx_put_image_to_window(m->mlx, m->wn,
			m->anim.pic1, j * 40, i * 40);
	else if (an == 2)
		mlx_put_image_to_window(m->mlx, m->wn,
			m->anim.pic2, j * 40, i * 40);
	else if (an == 3)
		mlx_put_image_to_window(m->mlx, m->wn,
			m->anim.pic3, j * 40, i * 40);
	else if (an == 4)
		mlx_put_image_to_window(m->mlx, m->wn,
			m->anim.pic4, j * 40, i * 40);
	else if (an == 5)
		mlx_put_image_to_window(m->mlx, m->wn,
			m->anim.pic5, j * 40, i * 40);
}

int	ft_animation(t_game_map *m)
{
	int			i;
	int			j;
	static int	animation;

	i = -1;
	while (m->map_data[++i])
	{
		j = -1;
		while (m->map_data[i][++j])
		{
			if (m->map_data[i][j] == 'C')
				ft_put_animation(i, j, m, animation);
		}
	}
	animation++;
	if (animation > 5)
		animation = 0;
	usleep(100000);
	enemy_one(m, -1, -1);
	enemy_two(m, -1, -1);
	return (1);
}

void	print_moves(t_game_map *m)
{
	char	*str;

	str = ft_itoa(m->steps);
	mlx_string_put(m->mlx, m->wn, 5, 6, 0xFF1493, "Moves: ");
	mlx_string_put(m->mlx, m->wn, 70, 6, 0xFF1493, str);
	free(str);
}
