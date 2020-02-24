/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:22:45 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/24 16:19:56 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move_left(t_cub3d *cub)
{
	if (cub->map[(int)(cub->ppos_y)][(int)(cub->ppos_x + cub->v_dir_y
	* MOVE_SPEED)] != '1')
		cub->ppos_x += cub->v_dir_y * MOVE_SPEED;
	if (cub->map[(int)(cub->ppos_y - cub->v_dir_x
	* MOVE_SPEED)][(int)(cub->ppos_x)] != '1')
		cub->ppos_y -= cub->v_dir_x * MOVE_SPEED;
}

void	ft_move_right(t_cub3d *cub)
{
	if (cub->map[(int)(cub->ppos_y)][(int)(cub->ppos_x - cub->v_dir_y
	* MOVE_SPEED)] != '1')
		cub->ppos_x -= cub->v_dir_y * MOVE_SPEED;
	if (cub->map[(int)(cub->ppos_y + cub->v_dir_x
	* MOVE_SPEED)][(int)(cub->ppos_x)] != '1')
		cub->ppos_y += cub->v_dir_x * MOVE_SPEED;
}

void	ft_move_up(t_cub3d *cub)
{
	if (cub->map[(int)(cub->ppos_y)][(int)(cub->ppos_x + cub->v_dir_x
	* MOVE_SPEED)] != '1')
		cub->ppos_x += cub->v_dir_x * MOVE_SPEED;
	if (cub->map[(int)(cub->ppos_y + cub->v_dir_y
	* MOVE_SPEED)][(int)(cub->ppos_x)] != '1')
		cub->ppos_y += cub->v_dir_y * MOVE_SPEED;
}

void	ft_move_down(t_cub3d *cub)
{
	if (cub->map[(int)(cub->ppos_y)][(int)(cub->ppos_x - cub->v_dir_x
	* MOVE_SPEED)] != '1')
		cub->ppos_x -= cub->v_dir_x * MOVE_SPEED;
	if (cub->map[(int)(cub->ppos_y - cub->v_dir_y
	* MOVE_SPEED)][(int)(cub->ppos_x)] != '1')
		cub->ppos_y -= cub->v_dir_y * MOVE_SPEED;
}

void	ft_rotation_camera(t_cub3d *cub)
{
	double	old_v;
	double	old_p;

	if (cub->key_left)
	{
		old_v = cub->v_dir_x;
		cub->v_dir_x = cub->v_dir_x * cos(-ROT_S) - cub->v_dir_y * sin(-ROT_S);
		cub->v_dir_y = old_v * sin(-ROT_S) + cub->v_dir_y * cos(-ROT_S);
		old_p = cub->plane_x;
		cub->plane_x = cub->plane_x * cos(-ROT_S) - cub->plane_y * sin(-ROT_S);
		cub->plane_y = old_p * sin(-ROT_S) + cub->plane_y * cos(-ROT_S);
	}
	if (cub->key_right)
	{
		old_v = cub->v_dir_x;
		cub->v_dir_x = cub->v_dir_x * cos(ROT_S) - cub->v_dir_y * sin(ROT_S);
		cub->v_dir_y = old_v * sin(ROT_S) + cub->v_dir_y * cos(ROT_S);
		old_p = cub->plane_x;
		cub->plane_x = cub->plane_x * cos(ROT_S) - cub->plane_y * sin(ROT_S);
		cub->plane_y = old_p * sin(ROT_S) + cub->plane_y * cos(ROT_S);
	}
}
