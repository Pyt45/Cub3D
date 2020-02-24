/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_tools5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 15:22:17 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/22 15:25:59 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		get_color_floor(int fd, t_cub3d *cub)
{
	if ((cub->floor_r = get_value(fd, cub, 0)) == -1)
		return (-1);
	if (cub->c_buff != ',')
		return (-1);
	if ((cub->floor_g = get_value(fd, cub, 0)) == -1)
		return (-1);
	if (cub->c_buff != ',')
		return (-1);
	if ((cub->floor_b = get_value(fd, cub, 0)) == -1)
		return (-1);
	if (cub->c_buff != '\n')
		return (-1);
	cub->flag_floor++;
	return (1);
}

int		get_color_ceiling(int fd, t_cub3d *cub)
{
	if ((cub->ceiling_r = get_value(fd, cub, 0)) == -1)
		return (-1);
	if (cub->c_buff != ',')
		return (-1);
	if ((cub->ceiling_g = get_value(fd, cub, 0)) == -1)
		return (-1);
	if (cub->c_buff != ',')
		return (-1);
	if ((cub->ceiling_b = get_value(fd, cub, 0)) == -1)
		return (-1);
	if (cub->c_buff != '\n')
		return (-1);
	cub->flag_ceiling++;
	return (1);
}
