/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_tools3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:46:38 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/24 15:54:27 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	side_texture(t_cub3d *cub, int i)
{
	if (i == 0)
	{
		if (cub->block_x - (int)cub->ppos_x > 0)
			cub->text = 3;
		else
			cub->text = 1;
	}
	else
	{
		if (cub->block_y - (int)cub->ppos_y > 0)
			cub->text = 2;
		else
			cub->text = 0;
	}
}

void	ft_swap_int(int i, int j, t_cub3d *cub)
{
	int		tmp;

	tmp = cub->sprite_order[i];
	cub->sprite_order[i] = cub->sprite_order[j];
	cub->sprite_order[j] = tmp;
	ft_swap_dbl(i, j, cub);
}

void	ft_swap_dbl(int i, int j, t_cub3d *cub)
{
	double	tmp;

	tmp = cub->sprite_d[i];
	cub->sprite_d[i] = cub->sprite_d[j];
	cub->sprite_d[j] = tmp;
}

void	ft_init_vec_w_s(char c, t_cub3d *cub)
{
	if (c == 'W')
	{
		cub->v_dir_x = -0.99;
		cub->v_dir_y = 0.00;
		cub->plane_x = 0.00;
		cub->plane_y = -0.66;
	}
	if (c == 'E')
	{
		cub->v_dir_x = 0.99;
		cub->v_dir_y = 0.00;
		cub->plane_x = 0.00;
		cub->plane_y = 0.66;
	}
}

int		ft_icon_close(void *cub)
{
	(void)cub;
	exit(0);
}
