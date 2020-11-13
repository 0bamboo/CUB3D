/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_directions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:59:55 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/12 22:59:55 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "cub3d.h"

void				ft_go_forward(t_cub *cub)
{
	if (cub->map[(int)(cub->pos.posy)][(int)(cub->pos.posx + cub->pos.dirx *
		M_S)] != '1')
		cub->pos.posx += cub->pos.dirx * M_S;
	if (cub->map[(int)(cub->pos.posy + cub->pos.diry * M_S)]
		[(int)(cub->pos.posx)] != '1')
		cub->pos.posy += cub->pos.diry * M_S;
}

void				ft_go_backward(t_cub *cub)
{
	if (cub->map[(int)(cub->pos.posy)][(int)(cub->pos.posx - cub->pos.dirx *
		M_S)] != '1')
		cub->pos.posx -= cub->pos.dirx * M_S;
	if (cub->map[(int)(cub->pos.posy - cub->pos.diry * M_S)]
		[(int)(cub->pos.posx)] != '1')
		cub->pos.posy -= cub->pos.diry * M_S;
}

void				ft_go_left(t_cub *cub)
{
	if (cub->map[(int)(cub->pos.posy)][(int)(cub->pos.posx + cub->pos.diry *
		M_S)] != '1')
		cub->pos.posx += cub->pos.diry * M_S;
	if (cub->map[(int)(cub->pos.posy - cub->pos.dirx * M_S)]
		[(int)(cub->pos.posx)] != '1')
		cub->pos.posy -= cub->pos.dirx * M_S;
}

void				ft_go_right(t_cub *cub)
{
	if (cub->map[(int)(cub->pos.posy)][(int)(cub->pos.posx - cub->pos.diry *
		M_S)] != '1')
		cub->pos.posx -= cub->pos.diry * M_S;
	if (cub->map[(int)(cub->pos.posy + cub->pos.dirx * M_S)]
		[(int)(cub->pos.posx)] != '1')
		cub->pos.posy += cub->pos.dirx * M_S;
}
