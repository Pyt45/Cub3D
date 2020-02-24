/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:50:31 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/22 15:34:28 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_is_valid(int fd, char buff[3], t_cub3d *cub)
{
	char	buffer[1];

	if (read(fd, buffer, BUFFER_SIZE) == 0)
		return (0);
	while (buffer[0] == ' ' || buffer[0] == '\n')
		if (read(fd, buffer, BUFFER_SIZE) == 0)
			return (0);
	buff[0] = buffer[0];
	read(fd, buffer, BUFFER_SIZE);
	buff[1] = buffer[0];
	if (buff[1] != ' ' && buff[1] != '1')
		read(fd, buffer, BUFFER_SIZE);
	if (buff[1] != ' ' && buff[1] != '1')
		buff[2] = buffer[0];
	if (buff[0] == 'N' && buff[1] == 'O' && buff[2] == ' ')
		cub->flag_north++;
	if (buff[0] == 'S' && buff[1] == 'O' && buff[2] == ' ')
		cub->flag_south++;
	if (buff[0] == 'W' && buff[1] == 'E' && buff[2] == ' ')
		cub->flag_west++;
	if (buff[0] == 'E' && buff[1] == 'A' && buff[2] == ' ')
		cub->flag_east++;
	if (buff[0] == 'S' && buff[1] == ' ')
		cub->flag_sprite++;
	return (1);
}

int		ft_pars_resolution(int fd, t_cub3d *cub)
{
	if ((cub->resolution_x = get_value(fd, cub, 1)) == -1)
		return (-1);
	if (cub->c_buff != ' ')
		return (-1);
	if ((cub->resolution_y = get_value(fd, cub, 1)) == -1)
		return (-1);
	if (cub->c_buff != '\n')
		return (-1);
	cub->flag_resolution++;
	return (1);
}

int		ft_get_color(int fd, char buff[3], t_cub3d *cub)
{
	if (buff[0] == 'F')
		if (get_color_floor(fd, cub) == -1)
			return (-1);
	if (buff[0] == 'C')
		if (get_color_ceiling(fd, cub) == -1)
			return (-1);
	return (1);
}

int		ft_pars_param(int fd, char buff[3], t_cub3d *cub)
{
	int		ret;

	ret = -1;
	if (buff[0] == 'R' & buff[1] == ' ')
		ret = ft_pars_resolution(fd, cub);
	if (buff[0] == 'N' && buff[1] == 'O' && buff[2] == ' ')
		ret = get_next_line(fd, &cub->north);
	if (buff[0] == 'S' && buff[1] == 'O' && buff[2] == ' ')
		ret = get_next_line(fd, &cub->south);
	if (buff[0] == 'W' && buff[1] == 'E' && buff[2] == ' ')
		ret = get_next_line(fd, &cub->west);
	if (buff[0] == 'E' && buff[1] == 'A' && buff[2] == ' ')
		ret = get_next_line(fd, &cub->east);
	if (buff[0] == 'S' && buff[1] == ' ')
		ret = get_next_line(fd, &cub->sprite);
	if (buff[0] == 'F' && buff[1] == ' ')
		ret = ft_get_color(fd, buff, cub);
	if (buff[0] == 'C' && buff[1] == ' ')
		ret = ft_get_color(fd, buff, cub);
	if (buff[0] == '1')
		return (1);
	return (ret);
}

int		ft_pars(int fd, t_cub3d *cub)
{
	char	buff[3];
	int		i;

	i = -1;
	while (++i < 8)
	{
		if (!ft_is_valid(fd, buff, cub) || (ft_pars_param(fd, buff, cub) == -1))
			return (-1);
		ft_bzero(buff, 3);
	}
	if (!(cub->flag_ceiling == 1 && cub->flag_floor == 1 &&
		cub->flag_resolution == 1 && cub->flag_north == 1 &&
		cub->flag_east == 1 && cub->flag_south == 1 &&
		cub->flag_west == 1 && cub->flag_sprite == 1))
		return (-1);
	if (cub->resolution_x > 2560 || cub->resolution_x < 150)
		cub->resolution_x = 2560;
	if (cub->resolution_y > 1440 || cub->resolution_y < 150)
		cub->resolution_y = 1440;
	if (ft_skip(fd, buff, cub) == 0 || ft_parsing_map(fd, buff, cub) < 0)
		return (-2);
	if (cub->size_map_x < 2 || cub->size_map_y < 2)
		return (-7);
	return (0);
}
