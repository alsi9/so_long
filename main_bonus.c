/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:15:59 by ephantom          #+#    #+#             */
/*   Updated: 2021/12/29 20:31:56 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game_map *m)
{
	int	a;

	m->mlx = mlx_init();
	if (m->mlx == NULL)
		ft_error("so_long: mlx_init returns NULL\n");
	m->wn = mlx_new_window(m->mlx, 40 * m->map_lenght,
			40 * m->map_height, "so_long");
	if (m->wn == NULL)
		ft_error("so_long: mlx_new_window returns NULL\n");
	m->go = mlx_xpm_file_to_image(m->mlx, "conv/0.xpm", &a, &a);
	m->wall = mlx_xpm_file_to_image(m->mlx, "conv/1.xpm", &a, &a);
	m->exit = mlx_xpm_file_to_image(m->mlx, "conv/e.xpm", &a, &a);
	m->person = mlx_xpm_file_to_image(m->mlx, "conv/p.xpm", &a, &a);
	m->coin = mlx_xpm_file_to_image(m->mlx, "anim/jewel1_0.xpm", &a, &a);
	m->en_one = mlx_xpm_file_to_image(m->mlx, "conv/enemy.xpm", &a, &a);
	m->en_two = mlx_xpm_file_to_image(m->mlx, "conv/enemy.xpm", &a, &a);
	m->steps = 0;
	m->game_score = 0;
	add_enemy(m, 0, 0, 0);
}

void	ft_render_bonus(t_game_map *m, int i, int j)
{
	while (m->map_data[++i])
	{
		j = -1;
		while (m->map_data[i][++j])
		{
			mlx_put_image_to_window(m->mlx, m->wn, m->go, j * 40, i * 40);
			if (m->map_data[i][j] == '1')
				mlx_put_image_to_window(m->mlx, m->wn, m->wall, j * 40, i * 40);
			else if (m->map_data[i][j] == 'E')
				mlx_put_image_to_window(m->mlx, m->wn, m->exit, j * 40, i * 40);
			else if (m->map_data[i][j] == 'P')
				mlx_put_image_to_window(m->mlx, m->wn, m->person,
					j * 40, i * 40);
			else if (m->map_data[i][j] == 'C')
				mlx_put_image_to_window(m->mlx, m->wn, m->coin, j * 40, i * 40);
			else if (m->map_data[i][j] == 'Z')
				mlx_put_image_to_window(m->mlx, m->wn, m->en_one,
					j * 40, i * 40);
			else if (m->map_data[i][j] == 'W')
				mlx_put_image_to_window(m->mlx, m->wn, m->en_two,
					j * 40, i * 40);
		}
	}
	print_moves(m);
}

int	ft_exit(void *param)
{
	if (param)
		ft_putstr_fd(param, 2);
	exit(0);
}

int	ft_get_map(int argc, char **argv, t_game_map *m)
{
	int	read_result;
	int	count_str;
	int	coin;

	if (argc != 2)
		ft_error("so_long: wrong count of arguments\n");
	coin = 0;
	count_str = 1;
	read_result = -1;
	if (ft_check_filename(argv[1]))
	{
		read_result = ft_read_map(argv[1], m, &count_str);
		if (read_result == 0)
		{
			if (check_map(m, &count_str, &coin) == 0)
				return (0);
		}
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	t_game_map	m;

	if (argc < 2)
		ft_error("so_long: wrong count of arguments\n");
	if (ft_get_map(argc, argv, &m) == -1)
		ft_error("so_long: invalid file\n");
	init_map(&m);
	init_animation(&m);
	ft_render_bonus(&m, -1, -1);
	mlx_key_hook(m.wn, ft_key_hook, &m);
	mlx_hook(m.wn, 17, 0, ft_exit, 0);
	mlx_loop_hook(m.mlx, ft_animation, &m);
	mlx_loop(m.mlx);
}
