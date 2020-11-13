/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 00:03:27 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/13 00:03:27 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int					ft_return_error(int er)
{
	ft_putstr_fd("Error\n", 1);
	if (er == -1)
		ft_putstr_fd(" ---> Error detected in the parsing block ! \n", 1);
	if (er == -2)
		ft_putstr_fd(" ---> Supports only the files with the extension '.cub' ! \n", 1);
	if (er == -3)
		ft_putstr_fd(" ---> The structure of the map is not correct ! \n", 1);
	if (er == -4)
		ft_putstr_fd(" ---> The size of the map is not correct ! ", 1);
	if (er == -5)
		ft_putstr_fd(" ---> Error of mlx window ! \n", 1);
	if (er == -6)
		ft_putstr_fd(" ---> The path of textures is not correct ! \n", 1);
	if (er == -7)
		ft_putstr_fd(" ---> You need to submit the option '--save' ! \n", 1);
	if (er == -8)
		ft_putstr_fd(" ---> Wrong number of arguments ! \n", 1);
	return (0);
}

void	ft_swap_dis(int i, int j, t_cub *cub)
{
	double	buff;

	buff = cub->sp.sp_dis[i];
	cub->sp.sp_dis[i] = cub->sp.sp_dis[j];
	cub->sp.sp_dis[j] = buff;
}

void	ft_swap_ord(int i, int j, t_cub *cub)
{
	int		buff;

	buff = cub->sp.sp_ord[i];
	cub->sp.sp_ord[i] = cub->sp.sp_ord[j];
	cub->sp.sp_ord[j] = buff;
	ft_swap_dis(i, j, cub);
}

void	ft_sort_sprite(t_cub *cub)
{
	int		x;
	int		y;

	x = -1;
	while (++x < cub->sp.nbr_sp - 1)
	{
		y = x;
		while (++y < cub->sp.nbr_sp)
		{
			if (cub->sp.sp_dis[x] < cub->sp.sp_dis[y])
				ft_swap_ord(x, y, cub);
		}
	}
}

void	ft_manage_order_sp(t_cub *cub)
{
	int		x;

	x = -1;
	while (++x < cub->sp.nbr_sp)
	{
		cub->sp.sp_ord[x] = x;
		cub->sp.sp_dis[x] = (cub->pos.posx - cub->sp.sp_x[x]) *
			(cub->pos.posx - cub->sp.sp_x[x]) +
			(cub->pos.posy - cub->sp.sp_y[x]) * (cub->pos.posy - cub->sp.sp_y[x]);
	}
	ft_sort_sprite(cub);
}
