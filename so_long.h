/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 11:40:44 by ephantom          #+#    #+#             */
/*   Updated: 2021/12/29 16:23:26 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_anim
{
	void	*pic0;
	void	*pic1;
	void	*pic2;
	void	*pic3;
	void	*pic4;
	void	*pic5;
}	t_anim;

typedef struct s_game_map
{
	int		map_height;
	int		map_lenght;
	char	**map_data;
	int		game_score;
	int		max_score;
	int		pos_x;
	int		pos_y;
	int		steps;
	void	*wn;
	void	*go;
	void	*coin;
	void	*mlx;
	void	*wall;
	void	*exit;
	void	*person;
	void	*en_one;
	void	*en_two;
	t_anim	anim;
}	t_game_map;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(const char *str);
void	ft_putstr_fd(char *s, int fd);
int		get_next_line(char **line, int fd);
int		main(int argc, char **argv);
void	ft_perror(char *str);
void	ft_error(char *str);
int		ft_get_map(int argc, char **argv, t_game_map *map);
int		ft_check_filename(char *str);
int		ft_read_map(char *str, t_game_map *map, int *count_str);
int		check_map(t_game_map *map, int *count_str, int *coin);
int		check_char_and_coin(t_game_map *map, int *coin, int i, int j);
int		ft_key_hook(int keycode, t_game_map *map);
void	ft_render(t_game_map *map);
void	ft_render_bonus(t_game_map *map, int i, int j);
int		check_rectangle(t_game_map *map, int i, int count_str);
int		check_exit_person(t_game_map *map, int i, int j);
int		check_wall(t_game_map *map, int i, int j, int count_str);
int		ft_animation(t_game_map *map);
void	init_animation(t_game_map *map);
char	*ft_itoa(int n);
void	print_moves(t_game_map *map);
void	add_enemy(t_game_map *m, int i, int j, int count);
void	enemy_two(t_game_map *map, int i, int j);
void	enemy_one(t_game_map *map, int i, int j);

#endif
