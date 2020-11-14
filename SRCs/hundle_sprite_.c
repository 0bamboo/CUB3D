/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_sprite_.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 23:29:02 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/14 11:20:11 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_start_drawing_sp(t_cub *cub, double transfy)
{
	int		y;
	int		x;
	int		color;

	x = cub->pos.drstartx - 1;
	while (++x < cub->pos.drendx)
	{
		cub->tx.txx = (int)(2 * (x - (-cub->sp.sp_w / 2 +
			cub->sp.spsx)) * cub->tx.txw / cub->sp.sp_w) / 2;
		y = cub->pos.drstarty - 1;
		if (transfy > 0 && x > 0 && x < cub->sw &&
			transfy < cub->sp.z_buff[x])
		{
			while (++y < cub->pos.drendy)
			{
				cub->d = y * 2 - cub->sh + cub->sp.sp_h;
				cub->tx.txy = ft_return_biggest_nbr((((cub->d * cub->tx.txh) /
					cub->sp.sp_h) / 2), 0);
				color = cub->tx.sp_data[cub->tx.txw *
				cub->tx.txy + cub->tx.txx];
				if (color != 9961608)
					cub->data[x + cub->sw * y] = color;
			}
		}
	}
}

void	ft_calc_sprite_vars(t_cub *cub, double transfy)
{
	cub->sp.sp_h = abs((int)(cub->sh / transfy));
	cub->pos.drstarty = -cub->sp.sp_h / 2 + cub->sh / 2;
	cub->pos.drendy = cub->sp.sp_h / 2 + cub->sh / 2;
	(cub->pos.drstarty < 0) ? (cub->pos.drstarty = 0) : 0;
	(cub->pos.drstarty >= cub->sh) ?
		(cub->pos.drendy = cub->sh - 1) : 0;
	(cub->pos.drendy >= cub->sh) ?
		(cub->pos.drendy = cub->sh - 1) : 0;
	cub->sp.sp_w = abs((int)(cub->sh / transfy));
	cub->pos.drstartx = -cub->sp.sp_w / 2 + cub->sp.spsx;
	(cub->pos.drstartx < 0) ? (cub->pos.drstartx = 0) : 0;
	cub->pos.drendx = cub->sp.sp_w / 2 + cub->sp.spsx;
	(cub->pos.drendx >= cub->sw) ?
		(cub->pos.drendx = cub->sw - 1) : 0;
	ft_start_drawing_sp(cub, transfy);
}

void	ft_put_sprite(t_cub *cub)
{
	double		invrs;
	double		transfx;
	double		transfy;
	int			x;

	x = -1;
	ft_manage_order_sp(cub);
	cub->tx.txh = cub->tx.rsl_spy;
	cub->tx.txw = cub->tx.rsl_spx;
	while (++x < cub->sp.nbr_sp)
	{
		cub->sp.spx = 0.4 + cub->sp.sp_x[cub->sp.sp_ord[x]] -
			cub->pos.posx;
		cub->sp.spy = 0.4 + cub->sp.sp_y[cub->sp.sp_ord[x]] -
			cub->pos.posy;
		invrs = 1.0 / (cub->pos.planex *
		cub->pos.diry - cub->pos.dirx * cub->pos.planey);
		transfx = invrs * (cub->pos.diry * cub->sp.spx -
			cub->pos.dirx * cub->sp.spy);
		transfy = invrs * (-cub->pos.planey * cub->sp.spx +
			cub->pos.planex * cub->sp.spy);
		cub->sp.spsx = (int)((cub->sw / 2) *
			(1 + transfx / transfy));
		ft_calc_sprite_vars(cub, transfy);
	}
}
