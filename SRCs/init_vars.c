/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:37:38 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/21 11:00:32 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void					ft_init_west_vect(char c, t_cub *cub)
{
	if (c == 'W')
	{
		cub->pos.dirx = -0.99;
		cub->pos.diry = 0.00;
		cub->pos.planex = 0.00;
		cub->pos.planey = -0.66;
	}
}

void						ft_init_vectors(char c, t_cub *cub)
{
	if (c == 'E')
	{
		cub->pos.dirx = 0.99;
		cub->pos.diry = 0.00;
		cub->pos.planex = 0.00;
		cub->pos.planey = 0.66;
	}
	if (c == 'N')
	{
		cub->pos.dirx = 0.00;
		cub->pos.diry = -0.99;
		cub->pos.planex = 0.66;
		cub->pos.planey = 0.00;
	}
	if (c == 'S')
	{
		cub->pos.dirx = 0.00;
		cub->pos.diry = 0.99;
		cub->pos.planex = -0.66;
		cub->pos.planey = 0.00;
	}
	ft_init_west_vect(c, cub);
}

void						ft_init_vars(t_cub *cub)
{
	cub->sp.nbr_sp = 0;
	cub->sh = 0;
	cub->sw = 0;
	cub->sv.save = 0;
	cub->x = 0;
	cub->y = 0;
	cub->prs.flg_ceil = 0;
	cub->prs.flg_floor = 0;
	cub->prs.flg_n = 0;
	cub->prs.flg_e = 0;
	cub->prs.flg_s = 0;
	cub->prs.flg_w = 0;
	cub->prs.flg_sp = 0;
	cub->prs.flg_resol = 0;
	cub->k_f = 0;
	cub->k_b = 0;
	cub->k_r = 0;
	cub->k_l = 0;
	cub->r_l = 0;
	cub->r_r = 0;
	cub->sp.z_buff = NULL;
}

void						ft_init_bmp(t_cub *cub)
{
	cub->sv.bmp = NULL;
	cub->sv.size = 0;
	cub->sv.indx = 0;
}

void						ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	l;

	l = 0;
	str = (char *)s;
	if (n == 0)
		return ;
	while (l < n)
	{
		str[l] = 0;
		l++;
	}
}
