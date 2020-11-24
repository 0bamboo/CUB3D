/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:12:21 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/21 10:44:46 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void				ft_game_over(t_cub *cub)
{
	mlx_destroy_image(cub->mlx_ptr, cub->tx.tex_n);
	mlx_destroy_image(cub->mlx_ptr, cub->tx.tex_e);
	mlx_destroy_image(cub->mlx_ptr, cub->tx.tex_w);
	mlx_destroy_image(cub->mlx_ptr, cub->tx.tex_s);
	mlx_destroy_image(cub->mlx_ptr, cub->tx.tex_sp);
	mlx_destroy_image(cub->mlx_ptr, cub->img_ptr);
	if (cub->sv.save == 0)
	{
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
		free(cub->mlx_ptr);
	}
	free(cub->sp.z_buff);
	free(cub->map);
	free(cub->prs.p_sp);
	free(cub->prs.p_e);
	free(cub->prs.p_s);
	free(cub->prs.p_w);
	free(cub->prs.p_n);
	exit(0);
}

int					ft_manage_key_press(int key, t_cub *cub)
{
	if (key == K_B)
		cub->k_b = 1;
	if (key == K_F)
		cub->k_f = 1;
	if (key == K_R)
		cub->k_r = 1;
	if (key == K_L)
		cub->k_l = 1;
	if (key == R_L)
		cub->r_l = 1;
	if (key == R_R)
		cub->r_r = 1;
	if (key == ESC)
		ft_game_over(cub);
	return (0);
}

int					ft_manage_key_release(int key, t_cub *cub)
{
	if (key == K_B)
		cub->k_b = 0;
	if (key == K_F)
		cub->k_f = 0;
	if (key == K_R)
		cub->k_r = 0;
	if (key == K_L)
		cub->k_l = 0;
	if (key == R_L)
		cub->r_l = 0;
	if (key == R_R)
		cub->r_r = 0;
	return (0);
}

void				ft_move_the_player(t_cub *cub)
{
	if (cub->k_r)
		ft_go_right(cub);
	if (cub->k_f)
		ft_go_forward(cub);
	if (cub->k_l)
		ft_go_left(cub);
	if (cub->k_b)
		ft_go_backward(cub);
	if (cub->r_r || cub->r_l)
		ft_rotation_the_player(cub);
}

int					ft_click_exit(void *cub)
{
	(void)cub;
	exit(0);
}
