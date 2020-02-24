/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_tools1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:33:59 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/18 18:20:30 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_max(int a, int b)
{
	int		r;

	if (a < 0)
		a = 0;
	r = a - b;
	return (r);
}

void	ft_init_1_cub(t_cub3d *cub)
{
	cub->flag_north = 0;
	cub->flag_south = 0;
	cub->flag_east = 0;
	cub->flag_west = 0;
	cub->flag_floor = 0;
	cub->flag_resolution = 0;
	cub->flag_sprite = 0;
	cub->flag_ceiling = 0;
	cub->save = 0;
	cub->i = 0;
	cub->j = 0;
	cub->key_a = 0;
	cub->key_s = 0;
	cub->key_d = 0;
	cub->key_w = 0;
	cub->key_left = 0;
	cub->key_right = 0;
}

int		ft_check_cub(char *str)
{
	int		i;

	i = ft_strlen(str);
	if (i < 4)
		return (-9);
	if (str[i - 1] != 'b')
		return (-9);
	if (str[i - 2] != 'u')
		return (-9);
	if (str[i - 3] != 'c')
		return (-9);
	if (str[i - 4] != '.')
		return (-9);
	return (0);
}

void	ft_init_bmp(t_bmp_file *sv)
{
	sv->bmp = NULL;
	sv->index = 0;
	sv->size = 0;
}

int		ft_get_size_map(t_cub3d *cub)
{
	int		len;
	int		i;

	i = 0;
	len = 0;
	cub->size_map_x = ft_map_width(cub->map);
	cub->size_map_y = ft_map_height(cub->map);
	if (cub->size_map_x <= 2 || cub->size_map_y <= 2)
		return (-1);
	len = (int)ft_strlen(cub->map[0]);
	while (cub->map[++i])
		if (len != (int)ft_strlen(cub->map[i]))
			return (-1);
	return (0);
}
