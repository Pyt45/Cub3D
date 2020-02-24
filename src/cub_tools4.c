/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_tools4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:33:10 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/19 11:47:26 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_sort_sprite(t_cub3d *cub)
{
	int		i;
	int		j;

	i = -1;
	while (++i < cub->num_sprite - 1)
	{
		j = i;
		while (++j < cub->num_sprite)
		{
			if (cub->sprite_d[i] < cub->sprite_d[j])
				ft_swap_int(i, j, cub);
		}
	}
}

void	ft_sprite_order(t_cub3d *cub)
{
	int		i;

	i = -1;
	while (++i < cub->num_sprite)
	{
		cub->sprite_order[i] = i;
		cub->sprite_d[i] = ((cub->ppos_x - cub->sprite_x[i]) *
		(cub->ppos_x - cub->sprite_x[i]) + (cub->ppos_y -
		cub->sprite_y[i]) * (cub->ppos_y - cub->sprite_y[i]));
	}
	ft_sort_sprite(cub);
}

void	ft_draw_sprite(t_cub3d *cub, double transform_y)
{
	int		i;
	int		j;
	int		d;
	int		color;

	i = cub->drawstart_x - 1;
	while (++i < cub->drawend_x)
	{
		cub->tex_x = (int)(2 * (i - (-cub->sprite_width / 2
		+ cub->sprite_s_x)) * cub->tex_w / cub->sprite_width) / 2;
		j = cub->drawstart_y - 1;
		if (transform_y > 0 && i > 0 && i < cub->resolution_x
		&& transform_y < cub->z_buffer[i])
		{
			while (++j < cub->drawend_y)
			{
				d = j * 2 - cub->resolution_y + cub->sprite_height;
				cub->tex_y = ft_max((((d * cub->tex_h) / cub->sprite_height) /
				2), 0);
				color = cub->data_sprite[cub->tex_w * cub->tex_y + cub->tex_x];
				if (color != 9961608)
					cub->data[i + cub->resolution_x * j] = color;
			}
		}
	}
}

void	ft_height_sp(t_cub3d *cub, double transform_y)
{
	cub->sprite_height = fabs((int)cub->resolution_y / transform_y);
	cub->drawstart_y = -cub->sprite_height / 2 + cub->resolution_y / 2;
	cub->drawend_y = cub->sprite_height / 2 + cub->resolution_y / 2;
	if (cub->drawstart_y < 0)
		cub->drawstart_y = 0;
	if (cub->drawstart_y >= cub->resolution_y)
		cub->drawend_y = cub->resolution_y - 1;
	(cub->drawend_y >= cub->resolution_y) ?
	(cub->drawend_y = cub->resolution_y - 1) : 0;
	cub->sprite_width = fabs((int)cub->resolution_y / transform_y);
	cub->drawstart_x = -cub->sprite_width / 2 + cub->sprite_s_x;
	(cub->drawstart_x < 0) ? (cub->drawstart_x = 0) : 0;
	cub->drawend_x = cub->sprite_width / 2 + cub->sprite_s_x;
	(cub->drawend_x >= cub->resolution_x)
	? (cub->drawend_x = cub->resolution_x - 1) : 0;
	ft_draw_sprite(cub, transform_y);
}

void	ft_sprite(t_cub3d *cub)
{
	double		invdet;
	double		transform_x;
	double		transform_y;
	int			i;

	i = -1;
	ft_sprite_order(cub);
	cub->tex_h = cub->reso_sp_y;
	cub->tex_w = cub->reso_sp_x;
	while (++i < cub->num_sprite)
	{
		cub->sprite_X = 0.5 + cub->sprite_x[cub->sprite_order[i]] - cub->ppos_x;
		cub->sprite_Y = 0.5 + cub->sprite_y[cub->sprite_order[i]] - cub->ppos_y;
		invdet = 1.0 / (cub->plane_x * cub->v_dir_y - cub->v_dir_x
		* cub->plane_y);
		transform_x = invdet * (cub->v_dir_y * cub->sprite_X
		- cub->v_dir_x * cub->sprite_Y);
		transform_y = invdet * (-cub->plane_y * cub->sprite_X
		+ cub->plane_x * cub->sprite_Y);
		cub->sprite_s_x = (int)(cub->resolution_x / 2)
		* (1 + transform_x / transform_y);
		ft_height_sp(cub, transform_y);
	}
}
