/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 18:30:20 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/14 09:59:40 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				ft_handle_sides(t_cub *cub, int side)
{
	if (side == 0)
	{
		if (cub->pos.mapx - (int)cub->pos.posx > 0)
			cub->pos.check = 2;
		else
			cub->pos.check = 0;
	}
	else
	{
		if (cub->pos.mapy - (int)cub->pos.posy > 0)
			cub->pos.check = 3;
		else
			cub->pos.check = 1;
	}
}

int					ft_return_biggest_nbr(int x, int y)
{
	int				val;

	if (x < 0)
		x = 0;
	val = x - y;
	return (val);
}

void				ft_tex_calc(t_cub *cub)
{
	if (cub->pos.side == 0)
		cub->pos.wallx = cub->pos.posy + cub->pos.pwalldis * cub->pos.rdiry;
	else
		cub->pos.wallx = cub->pos.posx + cub->pos.pwalldis * cub->pos.rdirx;
	cub->pos.wallx = cub->pos.wallx - (int)cub->pos.wallx;
	cub->tx.txx = cub->pos.wallx * (double)cub->tx.txw;
	if (cub->pos.side == 0 && cub->pos.rdirx < 0)
		cub->tx.txx = cub->tx.txw - cub->tx.txx - 1;
	if (cub->pos.side == 1 && cub->pos.rdiry > 0)
		cub->tx.txx = cub->tx.txw - cub->tx.txx - 1;
}

void				ft_handle_texs(t_cub *cub)
{
	if (cub->pos.check == 0)
	{
		cub->tx.txh = cub->tx.rsl_wy;
		cub->tx.txw = cub->tx.rsl_wx;
		cub->tx.buff_data = cub->tx.w_data;
	}
	else if (cub->pos.check == 1)
	{
		cub->tx.txh = cub->tx.rsl_ny;
		cub->tx.txw = cub->tx.rsl_nx;
		cub->tx.buff_data = cub->tx.n_data;
	}
	else if (cub->pos.check == 2)
	{
		cub->tx.txh = cub->tx.rsl_ey;
		cub->tx.txw = cub->tx.rsl_ex;
		cub->tx.buff_data = cub->tx.e_data;
	}
	else if (cub->pos.check == 3)
	{
		cub->tx.txh = cub->tx.rsl_sy;
		cub->tx.txw = cub->tx.rsl_sx;
		cub->tx.buff_data = cub->tx.s_data;
	}
}

void				ft_start_drawing(int b_dr, int end_dr, int x, t_cub *cub)
{
	int			y;
	int			z;

	y = -1;
	ft_handle_texs(cub);
	ft_tex_calc(cub);
	while (++y < b_dr)
		cub->data[x + cub->sw * y] = (cub->prs.ceil_r << 16) +
		(cub->prs.ceil_g << 8) + cub->prs.ceil_b;
	y = b_dr - 1;
	while (++y < end_dr)
	{
		z = y * 2 - cub->sh + cub->pos.line_h;
		cub->tx.txy =
		ft_return_biggest_nbr((((z * cub->tx.txh) / cub->pos.line_h) / 2), 0);
		cub->data[x + cub->sw * y] =
		cub->tx.buff_data[cub->tx.txw * cub->tx.txy + cub->tx.txx];
	}
	while (++y < cub->sh)
		cub->data[x + cub->sw * y] = (cub->prs.flr_r << 16)
		+ (cub->prs.flr_b << 8) + cub->prs.flr_b;
}
