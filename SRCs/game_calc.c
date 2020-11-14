/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:58:37 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/14 11:20:55 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				ft_set_p_direction(t_cub *cub)
{
	if (cub->pos.rdirx < 0)
	{
		cub->pos.stepx = -1;
		cub->pos.siddisx = (cub->pos.posx - cub->pos.mapx)
		* cub->pos.deltadis_x;
	}
	else
	{
		cub->pos.stepx = 1;
		cub->pos.siddisx = (cub->pos.mapx + 1.0 - cub->pos.posx)
		* cub->pos.deltadis_x;
	}
	if (cub->pos.rdiry < 0)
	{
		cub->pos.stepy = -1;
		cub->pos.siddisy = (cub->pos.posy - cub->pos.mapy)
		* cub->pos.deltadis_y;
	}
	else
	{
		cub->pos.stepy = 1;
		cub->pos.siddisy = (cub->pos.mapy + 1.0 - cub->pos.posy)
		* cub->pos.deltadis_y;
	}
}

void				ft_start_dda(t_cub *cub)
{
	ft_set_p_direction(cub);
	cub->pos.hit = 0;
	while (cub->pos.hit == 0)
	{
		if (cub->pos.siddisx < cub->pos.siddisy)
		{
			cub->pos.siddisx += cub->pos.deltadis_x;
			cub->pos.mapx += cub->pos.stepx;
			cub->pos.side = 0;
		}
		else
		{
			cub->pos.siddisy += cub->pos.deltadis_y;
			cub->pos.mapy += cub->pos.stepy;
			cub->pos.side = 1;
		}
		if (cub->map[(int)cub->pos.mapy][(int)cub->pos.mapx] == '1')
			cub->pos.hit = 1;
		ft_handle_sides(cub, cub->pos.side);
	}
}

void				ft_init_vars_to_draw(t_cub *cub, int x)
{
	int				b_dr;
	int				end_dr;

	if (cub->pos.side == 0)
		cub->pos.pwalldis = (cub->pos.mapx - cub->pos.posx +
		(1 - cub->pos.stepx) / 2) / cub->pos.rdirx;
	else
		cub->pos.pwalldis = (cub->pos.mapy - cub->pos.posy +
		(1 - cub->pos.stepy) / 2) / cub->pos.rdiry;
	cub->pos.line_h = (int)(cub->sh / cub->pos.pwalldis);
	b_dr = -cub->pos.line_h / 2 + cub->sh / 2;
	(b_dr < 0) ? (b_dr = 0) : 0;
	end_dr = cub->pos.line_h / 2 + cub->sh / 2;
	(end_dr >= cub->sh) ? (end_dr = cub->sh - 1) : 0;
	cub->sp.z_buff[x] = cub->pos.pwalldis;
	ft_start_drawing(b_dr, end_dr, x, cub);
}

int					ft_start_game(t_cub *cub)
{
	int				i;

	i = -1;
	ft_move_the_player(cub);
	while (++i < cub->sw - 1)
	{
		cub->pos.cam_x = 2 * i / (double)cub->sw - 1;
		cub->pos.rdirx = cub->pos.dirx + cub->pos.planex * cub->pos.cam_x;
		cub->pos.rdiry = cub->pos.diry + cub->pos.planey * cub->pos.cam_x;
		cub->pos.mapx = (int)cub->pos.posx;
		cub->pos.mapy = (int)cub->pos.posy;
		cub->pos.deltadis_x = fabs(1 / cub->pos.rdirx);
		cub->pos.deltadis_y = fabs(1 / cub->pos.rdiry);
		ft_start_dda(cub);
		ft_init_vars_to_draw(cub, i);
	}
	ft_put_sprite(cub);
	if (cub->sv.save == 0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img_ptr, 0, 0);
	return (0);
}

int					ft_init_game(t_cub *cub)
{
	if (!(cub->mlx_ptr = mlx_init()))
		return (-5);
	if (ft_set_texs(cub) < 0)
		return (-6);
	if (!(cub->win_ptr = mlx_new_window(cub->mlx_ptr, cub->sw,
		cub->sh, "CUB3D")))
		return (-5);
	cub->img_ptr = mlx_new_image(cub->mlx_ptr, cub->sw,
	cub->sh);
	cub->data = (int *)mlx_get_data_addr(cub->img_ptr, &cub->ppx,
	&cub->s_line, &cub->endian);
	mlx_hook(cub->win_ptr, 2, 1, &ft_manage_key_press, cub);
	mlx_hook(cub->win_ptr, 3, 2, &ft_manage_key_release, cub);
	mlx_hook(cub->win_ptr, 17, 0, &ft_click_exit, cub);
	mlx_loop_hook(cub->mlx_ptr, &ft_start_game, cub);
	mlx_loop(cub->mlx_ptr);
	return (0);
}
