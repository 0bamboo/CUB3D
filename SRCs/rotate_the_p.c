/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_the_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 23:08:54 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/16 17:55:17 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_rotate_to_right(double *oldirx, double *oldplanex, t_cub *cub)
{
	if (cub->r_r)
	{
		*oldirx = cub->pos.dirx;
		cub->pos.dirx = cub->pos.dirx * cos(R_S) -
			cub->pos.diry * sin(R_S);
		cub->pos.diry = *oldirx * sin(R_S) +
			cub->pos.diry * cos(R_S);
		*oldplanex = cub->pos.planex;
		cub->pos.planex = cub->pos.planex * cos(R_S) -
			cub->pos.planey * sin(R_S);
		cub->pos.planey = *oldplanex * sin(R_S) +
			cub->pos.planey * cos(R_S);
	}
}

void		ft_rotation_the_player(t_cub *cub)
{
	double		oldirx;
	double		oldplanex;

	if (cub->r_l)
	{
		oldirx = cub->pos.dirx;
		cub->pos.dirx = cub->pos.dirx * cos(-R_S) -
			cub->pos.diry * sin(-R_S);
		cub->pos.diry = oldirx * sin(-R_S) +
			cub->pos.diry * cos(-R_S);
		oldplanex = cub->pos.planex;
		cub->pos.planex = cub->pos.planex * cos(-R_S) -
			cub->pos.planey * sin(-R_S);
		cub->pos.planey = oldplanex * sin(-R_S) +
			cub->pos.planey * cos(-R_S);
	}
	ft_rotate_to_right(&oldirx, &oldplanex, cub);
}
