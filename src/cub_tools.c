/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:21:27 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/18 18:16:53 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_skip(int fd, char buff[3], t_cub3d *cub)
{
	int		i;
	int		check;

	i = 0;
	check = 0;
	read(fd, buff, BUFFER_SIZE);
	while (buff[0] == ' ' || buff[0] == '\n')
	{
		read(fd, buff, BUFFER_SIZE);
		if (buff[0] == '\n')
			check++;
		i++;
	}
	if (check == 0 && cub->c_buff == '\n')
		return (1);
	if (check == 0 && cub->c_buff == ' ')
		return (0);
	return (1);
}

int		ft_map_height(char **map)
{
	int		i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int		ft_map_width(char **map)
{
	int		i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

double	ft_inc_var(t_cub3d *cub, double inc)
{
	if (cub->j < cub->resolution_x / 2 && cub->i < cub->resolution_y / 2)
		inc = 0.5;
	else if (cub->j > cub->resolution_x / 2 && cub->i > cub->resolution_y / 2)
		inc = -0.5;
	return (inc);
}

int		get_value(int fd, t_cub3d *cub, int opt)
{
	char	buff[1];
	int		n;

	n = 0;
	if (read(fd, buff, BUFFER_SIZE) == 0)
		return (-1);
	while (buff[0] == ' ')
		if (read(fd, buff, BUFFER_SIZE) == 0)
			return (-1);
	if (!(buff[0] >= '0' && buff[0] <= '9'))
		return (-1);
	while (buff[0] >= '0' && buff[0] <= '9')
	{
		n *= 10;
		n += buff[0] - '0';
		if (read(fd, buff, BUFFER_SIZE) == 0)
			return (-1);
	}
	cub->c_buff = buff[0];
	if (!opt)
	{
		if (n > 255 || n < 0)
			return (-1);
	}
	return (n);
}
