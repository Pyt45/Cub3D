/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:35:23 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/19 11:25:29 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_quit_game(t_cub3d *cub)
{
	mlx_destroy_image(cub->mlx_ptr, cub->texture_north);
	mlx_destroy_image(cub->mlx_ptr, cub->texture_south);
	mlx_destroy_image(cub->mlx_ptr, cub->texture_east);
	mlx_destroy_image(cub->mlx_ptr, cub->texture_west);
	mlx_destroy_image(cub->mlx_ptr, cub->texture_sprite);
	mlx_destroy_image(cub->mlx_ptr, cub->img);
	if (cub->save == 0)
	{
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
		free(cub->mlx_ptr);
	}
	free(cub->map);
	free(cub->north);
	free(cub->south);
	free(cub->east);
	free(cub->west);
	exit(0);
}

static int	ft_check(char **argv, t_cub3d *cub)
{
	int		r;

	if (argv[2][0] == '-' && argv[2][1] == '-' &&
	argv[2][2] == 's' && argv[2][3] == 'a' && argv[2][4] == 'v'
	&& argv[2][5] == 'e')
	{
		cub->mlx_ptr = mlx_init();
		cub->save = 1;
		r = ft_recup_texture(cub);
		cub->img = mlx_new_image(cub->mlx_ptr, cub->resolution_x,
		cub->resolution_y);
		cub->data = (int *)mlx_get_data_addr(cub->img, &cub->per_pixel,
		&cub->size_line, &cub->endian);
		ft_loop_game(cub);
		cub->screen = cub->data;
		ft_save(cub, "cub3d.bmp");
		ft_quit_game(cub);
		free(cub->screen);
		return (0);
	}
	return (-3);
}

int			ft_err_msg(int error)
{
	ft_putstr_fd("Error\n", 1);
	if (error == -1)
		ft_putstr_fd("problem parsing\n", 1);
	if (error == -2)
		ft_putstr_fd("problem map\n", 1);
	if (error == -3)
		ft_putstr_fd("bad writing '-save'\n", 1);
	if (error == -4)
		ft_putstr_fd("error pointer\n", 1);
	if (error == -5)
		ft_putstr_fd("window problem\n", 1);
	if (error == -6)
		ft_putstr_fd("Bad path sprite/texture\n", 1);
	if (error == -7)
		ft_putstr_fd("Wrong size map\n", 1);
	if (error == -8)
		ft_putstr_fd("wrong number arg\n", 1);
	if (error == -9)
		ft_putstr_fd("only '.cub' support\n", 1);
	return (0);
}

void		ft_init_cub(t_cub3d *cub)
{
	ft_init_1_cub(cub);
	cub->block_x = 0;
	cub->block_y = 0;
	cub->step_x = 0;
	cub->step_y = 0;
	cub->side_dist_x = 0;
	cub->side_dist_y = 0;
	cub->ray_dir_y = 0;
	cub->ray_dir_x = 0;
	cub->v_dir_x = 0;
	cub->plane_x = 0;
	cub->plane_y = 0;
	cub->v_dir_y = 0;
	cub->num_sprite = 0;
}

int			main(int argc, char **argv)
{
	int		fd;
	int		error;
	t_cub3d cub;

	if (argc < 2 || argc > 3)
		return (ft_err_msg(-8));
	if ((error = ft_check_cub(argv[1])) == -9)
		return (ft_err_msg(error));
	ft_init_cub(&cub);
	fd = open(argv[1], O_RDONLY);
	if ((error = ft_pars(fd, &cub)) < 0)
		return (ft_err_msg(error));
	if (argc == 3)
	{
		if (ft_check(argv, &cub) == -3)
			ft_err_msg(-3);
		return (0);
	}
	close(fd);
	if ((error = ft_make_game(&cub)) < 0)
		return (ft_err_msg(error));
	return (0);
}
