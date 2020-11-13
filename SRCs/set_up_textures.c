/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_txures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 22:28:59 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/12 22:28:59 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int					ft_north_tex(t_cub *cub)
{
	char			*tx;

	tx = ft_strtrim(cub->prs.p_n, " ");
	if (!(cub->tx.tex_n = mlx_xpm_file_to_image(cub->mlx_ptr,
		tx, &cub->tx.rsl_nx, &cub->tx.rsl_ny)))
		return (-1);
	cub->tx.n_data = (int *)mlx_get_data_addr(cub->tx.tex_n,
	&cub->tx.ppn, &cub->tx.sln, &cub->tx.en);
	free(tx);
	return (0);
}

int					ft_south_tex(t_cub *cub)
{
	char			*tx;

	tx = ft_strtrim(cub->prs.p_s, " ");
	if (!(cub->tx.tex_s = mlx_xpm_file_to_image(cub->mlx_ptr,
		tx, &cub->tx.rsl_sx, &cub->tx.rsl_sy)))
		return (-1);
	cub->tx.s_data = (int *)mlx_get_data_addr(cub->tx.tex_s,
	&cub->tx.pps, &cub->tx.sls, &cub->tx.es);
	free(tx);
	return (0);
}

int					ft_west_tex(t_cub *cub)
{
	char			*tx;

	tx = ft_strtrim(cub->prs.p_w, " ");
	if (!(cub->tx.tex_w = mlx_xpm_file_to_image(cub->mlx_ptr,
		tx, &cub->tx.rsl_wx, &cub->tx.rsl_wy)))
		return (-1);
	cub->tx.w_data = (int *)mlx_get_data_addr(cub->tx.tex_w,
	&cub->tx.ppw, &cub->tx.slw, &cub->tx.ew);
	free(tx);
	return (0);
}

int					ft_east_tex(t_cub *cub)
{
	char			*tx;

	tx = ft_strtrim(cub->prs.p_e, " ");
	if (!(cub->tx.tex_e = mlx_xpm_file_to_image(cub->mlx_ptr,
		tx, &cub->tx.rsl_ex, &cub->tx.rsl_ey)))
		return (-1);
	cub->tx.e_data = (int *)mlx_get_data_addr(cub->tx.tex_e,
	&cub->tx.ppe, &cub->tx.sle, &cub->tx.ee);
	free(tx);
	return (0);
}

int					ft_sprite_tex(t_cub *cub)
{
	char			*tx;

	tx = ft_strtrim(cub->prs.p_sp, " ");
	if (!(cub->tx.tex_sp = mlx_xpm_file_to_image(cub->mlx_ptr,
		tx, &cub->tx.rsl_spx, &cub->tx.rsl_spy)))
		return (-1);
	cub->tx.sp_data = (int *)mlx_get_data_addr(cub->tx.tex_sp,
	&cub->tx.ppsp, &cub->tx.slsp, &cub->tx.esp);
    free(tx);
	return (0);
}
