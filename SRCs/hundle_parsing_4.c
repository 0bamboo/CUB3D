/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_parsing_4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:09:48 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/12 22:09:48 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int					ft_grab_map_h(char **map)
{
	int				i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

static int					ft_grab_map_w(char **map)
{
	int				i;

	i = 0;
	while (map[0][i])
		i++;
	return (i);
}

static double				ft_adjust_player_pos(t_cub *cub, double add)
{
	if (cub->y < cub->sw / 2 && cub->x < cub->sh / 2)
		add = 0.5;
	else if (cub->y > cub->sw / 2 && cub->x > cub->sh / 2)
		add = -0.5;
	return (add);
}

int					ft_check_map_data(char c, int p, t_cub *cub)
{
	double			add;

	add = 0;
	if (c == '2' && cub->y != 0)
	{
		cub->sp.sp_x[cub->sp.nbr_sp] = cub->y;
		cub->sp.sp_y[cub->sp.nbr_sp] = cub->x;
		cub->sp.nbr_sp++;
	}
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && p == 2)
		return (0);
	if (c == '\n' || c == '0' || c == '1' || c == '2' || c == '\0')
		return (p);
	if ((c == 'N' || c == 'S' || c == 'W' || c == 'E') && p == 1)
	{
		if (cub->y == 0)
			return (0);
		else
			add = ft_adjust_player_pos(cub, add);
		cub->pos.posx = cub->y + add;
		cub->pos.posy = cub->x + add;
		ft_init_vectors(c, cub);
		return (p + 1);
	}
	return (1);
}

int					ft_correct_map(t_cub *cub, int p)
{
	cub->map_w = ft_grab_map_w(cub->map);
	cub->map_h = ft_grab_map_h(cub->map);
	cub->x = -1;
	while (++cub->x < cub->map_h)
	{
		cub->y = -1;
		while (++cub->y < cub->map_w)
		{
			if (!(p = ft_check_map_data(cub->map[cub->x][cub->y], p, cub)))
				return (-1);
		}
	}
	if (p != 2)
		return (-1);
	return (0);
}
