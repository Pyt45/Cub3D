/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_save.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 19:52:16 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/18 17:58:27 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	write_body(t_cub3d *cub, t_bmp_file *sv)
{
	int x;
	int y;

	y = cub->resolution_y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < cub->resolution_x)
		{
			sv->bmp[sv->index++] = cub->screen[y * cub->resolution_x + x] >> 0;
			sv->bmp[sv->index++] = cub->screen[y * cub->resolution_x + x] >> 8;
			sv->bmp[sv->index++] = cub->screen[y * cub->resolution_x + x] >> 16;
			x++;
		}
		x = 0;
		while (x < (4 - (cub->resolution_x * 3) % 4) % 4)
		{
			sv->bmp[sv->index++] = 0;
			x++;
		}
		y--;
	}
}

static void	write_int(t_bmp_file *sv, unsigned int val)
{
	sv->bmp[sv->index++] = val >> 0;
	sv->bmp[sv->index++] = val >> 8;
	sv->bmp[sv->index++] = val >> 16;
	sv->bmp[sv->index++] = val >> 24;
}

static void	write_file_header(t_bmp_file *sv)
{
	sv->bmp[sv->index++] = 'B';
	sv->bmp[sv->index++] = 'M';
	write_int(sv, sv->size);
	write_int(sv, 0x00000000);
	sv->bmp[sv->index++] = 54;
	sv->bmp[sv->index++] = 0;
	sv->bmp[sv->index++] = 0;
	sv->bmp[sv->index++] = 0;
}

static void	write_file_info(t_cub3d *cub, t_bmp_file *sv)
{
	int		i;

	sv->bmp[sv->index++] = 40;
	sv->bmp[sv->index++] = 0;
	sv->bmp[sv->index++] = 0;
	sv->bmp[sv->index++] = 0;
	write_int(sv, cub->resolution_x);
	write_int(sv, cub->resolution_y);
	sv->bmp[sv->index++] = 1;
	sv->bmp[sv->index++] = 0;
	sv->bmp[sv->index++] = 24;
	sv->bmp[sv->index++] = 0;
	i = 0;
	while (i < 24)
	{
		sv->bmp[sv->index++] = 0;
		i++;
	}
}

int			ft_save(t_cub3d *cub, char *name)
{
	int			fd;
	t_bmp_file	sv;

	ft_init_bmp(&sv);
	sv.size = 54 + 3 * cub->resolution_x * cub->resolution_y;
	sv.bmp = malloc(sv.size);
	if ((fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0666)) < 0)
		return (-1);
	write_file_header(&sv);
	write_file_info(cub, &sv);
	write_body(cub, &sv);
	write(fd, sv.bmp, sv.size);
	close(fd);
	return (0);
}
