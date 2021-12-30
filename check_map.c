/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ephantom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 12:13:54 by ephantom          #+#    #+#             */
/*   Updated: 2021/12/29 12:29:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_open_error(char *str, int fd)
{
	if (fd < 0)
	{
		write(2, "so_long: ", 9);
		ft_perror(str);
	}
}

int	read_text(int fd, t_game_map *m, int *count_str)
{
	int		i;
	char	*string;

	i = 0;
	m->map_data[0] = NULL;
	while (get_next_line(&string, fd) > 0)
	{
		if (*string == '\0' && i > 0)
			break ;
		if (*string == '\0')
		{
			free(string);
			continue ;
		}
		m->map_data[i] = string;
		i++;
	}
	(m->map_data)[i] = NULL;
	(*count_str) = i;
	if (m->map_data[0] == NULL)
		return (-1);
	return (0);
}

int	ft_read_map(char *str, t_game_map *m, int *count_str)
{
	int		fd;
	char	buffer[1];

	fd = open(str, O_RDONLY);
	ft_open_error(str, fd);
	while (read(fd, buffer, 1) > 0)
	{
		if (*buffer == '\n')
			(*count_str)++;
	}
	close(fd);
	m->map_data = (char **)malloc(sizeof(char *) * ((*count_str) + 1));
	if (!(m->map_data))
		return (-1);
	fd = open(str, O_RDONLY);
	ft_open_error(str, fd);
	if (read_text(fd, m, count_str) == -1)
		return (-1);
	return (0);
}

void	ft_problem(int problem)
{
	if (problem == -1)
		ft_error("Error: no walls!\n");
	else if (problem == -2)
		ft_error("Error: wrong number of exits!\n");
	else if (problem == -3)
		ft_error("Error: wrong number of players!\n");
	else if (problem == -4)
		ft_error("Error: wrong characters!\n");
	else if (problem == -5)
		ft_error("Error: no coins!\n");
	else if (problem == -6)
		ft_error("Error: this is not a rectangle!\n");
}

int	check_map(t_game_map *m, int *count_str, int *coin)
{
	int	problem;

	problem = check_rectangle(m, 0, *count_str);
	if (problem == 0)
	{
		problem = check_char_and_coin(m, coin, 0, 0);
		if (problem == 0)
		{
			problem = check_exit_person(m, -1, -1);
			if (problem == 0)
			{
				problem = check_wall(m, 0, 0, *count_str);
				if (problem == 0)
					return (0);
			}
		}
	}
	if (problem != 0)
		ft_problem(problem);
	return (-1);
}
