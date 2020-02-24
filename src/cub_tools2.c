/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_tools2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 14:35:22 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/24 15:45:44 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_choose_texture(t_cub3d *cub)
{
	if (cub->text == 0)
	{
		cub->tex_h = cub->reso_so_y;
		cub->tex_w = cub->reso_so_x;
		cub->data_print = cub->data_south;
	}
	else if (cub->text == 1)
	{
		cub->tex_h = cub->reso_ea_y;
		cub->tex_w = cub->reso_ea_x;
		cub->data_print = cub->data_east;
	}
	else if (cub->text == 2)
	{
		cub->tex_h = cub->reso_no_y;
		cub->tex_w = cub->reso_no_x;
		cub->data_print = cub->data_north;
	}
	else if (cub->text == 3)
	{
		cub->tex_h = cub->reso_we_y;
		cub->tex_w = cub->reso_we_x;
		cub->data_print = cub->data_west;
	}
}

int		ft_recup_texture(t_cub3d *cub)
{
	int	r;

	r = 0;
	r += ft_texture_no(cub);
	r += ft_texture_so(cub);
	r += ft_texture_we(cub);
	r += ft_texture_es(cub);
	r += ft_texture_sp(cub);
	return (r);
}

void	ft_texture(t_cub3d *cub)
{
	if (cub->side == 0)
		cub->wall_x = cub->ppos_y + cub->perp_wd * cub->ray_dir_y;
	else
		cub->wall_x = cub->ppos_x + cub->perp_wd * cub->ray_dir_x;
	cub->wall_x = cub->wall_x - (int)cub->wall_x;
	cub->tex_x = cub->wall_x * (double)cub->tex_w;
	if (cub->side == 0 && cub->ray_dir_x < 0)
		cub->tex_x = cub->tex_w - cub->tex_x - 1;
	if (cub->side == 1 && cub->ray_dir_y > 0)
		cub->tex_x = cub->tex_w - cub->tex_x - 1;
}

void	ft_draw(int start, int end, int index, t_cub3d *cub)
{
	int		j;
	int		k;

	j = -1;
	ft_choose_texture(cub);
	ft_texture(cub);
	while (++j < start)
		cub->data[index + cub->resolution_x * j] = (cub->ceiling_r << 16) +
		(cub->ceiling_g << 8) + cub->ceiling_b;
	j = start - 1;
	while (++j < end)
	{
		k = j * 2 - cub->resolution_y + cub->line_height;
		cub->tex_y = ft_max((((k * cub->tex_h) / cub->line_height) / 2), 0);
		cub->data[index + cub->resolution_x * j] =
		cub->data_print[cub->tex_w * cub->tex_y + cub->tex_x];
	}
	j = end - 1;
	while (++j < cub->resolution_y)
		cub->data[index + cub->resolution_x * j] = (cub->floor_r << 16) +
		(cub->floor_g << 8) + cub->floor_b;
}

void	ft_init_vecteur_direction(char c, t_cub3d *cub)
{
	if (c == 'N')
	{
		cub->v_dir_x = 0.00;
		cub->v_dir_y = -0.99;
		cub->plane_x = 0.66;
		cub->plane_y = 0.00;
	}
	if (c == 'S')
	{
		cub->v_dir_x = 0.00;
		cub->v_dir_y = 0.99;
		cub->plane_x = -0.66;
		cub->plane_y = 0.00;
	}
	ft_init_vec_w_s(c, cub);
}
