/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaqlzim <aaqlzim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:41:21 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/24 13:53:03 by aaqlzim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_check_char_map(char c, int player, t_cub3d *cub)
{
	float	inc;

	inc = 0.0;
	if (c == '2' && cub->j != 0)
	{
		cub->sprite_x[cub->num_sprite] = cub->j;
		cub->sprite_y[cub->num_sprite] = cub->i;
		cub->num_sprite++;
	}
	if (c == '\n' || c == '0' || c == '1' || c == '2' || c == '\0')
		return (player);
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && player == 2)
		return (0);
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && player == 1)
	{
		if (cub->j == 0)
			return (0);
		else
			inc = ft_inc_var(cub, inc);
		cub->ppos_y = cub->i + inc;
		cub->ppos_x = cub->j + inc;
		ft_init_vecteur_direction(c, cub);
		return (player + 1);
	}
	return (0);
}

int		ft_check_board_map(t_cub3d *cub)
{
	cub->i = 0;
	while (cub->i < cub->size_map_y)
	{
		cub->j = 0;
		while (cub->j < cub->size_map_x)
		{
			if ((cub->map[cub->i][cub->j] != '1'
			&& cub->map[cub->i][cub->j] != '\n')
			&& (((cub->i == 0 || cub->i == cub->size_map_y - 1)) ||
			((cub->j == cub->size_map_x - 1) || (cub->j == 0))))
				return (-1);
			cub->j++;
		}
		cub->i++;
	}
	return (0);
}

int		ft_check_map_size(t_cub3d *cub)
{
	int		player;
	int		len;
	int		i;

	player = 1;
	len = 0;
	i = 0;
	if ((ft_get_size_map(cub)) == -1)
		return (-1);
	cub->i = 0;
	while (cub->i < cub->size_map_y)
	{
		cub->j = 0;
		while (cub->j < cub->size_map_x)
		{
			if (!(player =
			ft_check_char_map(cub->map[cub->i][cub->j], player, cub)))
				return (-1);
			cub->j++;
		}
		cub->i++;
	}
	if (player != 2)
		return (-1);
	return (0);
}

int		check_line(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int		ft_parsing_map(int fd, char buff[3], t_cub3d *cub)
{
	char	*tmp_map;
	int		check;
	char	*line;

	tmp_map = ft_strdup(buff);
	check = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tmp_map = ft_strjoin(tmp_map, line);
		(line[0] == '1') ? (check = 1) : 0;
		if (!ft_strcmp(line, "") && check == 1)
			return (-1);
		tmp_map = ft_strjoin(tmp_map, "\n");
		free(line);
		(check_line(line)) ? (check = 0) : 0;
	}
	tmp_map = ft_strjoin(tmp_map, line);
	ft_bzero(line, ft_strlen(line));
	free(line);
	cub->map = ft_split(tmp_map, '\n');
	if (ft_check_map_size(cub) == -1)
		return (-1);
	if (ft_check_board_map(cub) == -1)
		return (-1);
	return (1);
}
