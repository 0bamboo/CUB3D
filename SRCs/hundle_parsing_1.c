/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_parsing_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:32:14 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/12 21:32:14 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int					ft_grab_rsl(int fd, t_cub *cub)
{
	char			tmp_c[1];
	int				nbr;

	nbr = 0;
	if (!read(fd, tmp_c, 1))
		return (-1);
	while (tmp_c[0] == ' ')
		if (!read(fd, tmp_c, 1))
			return (-1);
	if ((tmp_c[0] < '0' && tmp_c[0] > '9'))
		return (-1);
	while (tmp_c[0] >= '0' && tmp_c[0] <= '9')
	{
		nbr *= 10;
		nbr += tmp_c[0] - '0';
		if (!read(fd, tmp_c, 1))
			return (-1);
	}
	cub->tmp_c = tmp_c[0];
	return (nbr);
}

int					ft_check_rsl_flag(int fd, t_cub *cub)
{
	if ((cub->sw = ft_grab_rsl(fd, cub)) == -1
		|| cub->tmp_c != ' ')
		return (-1);
	if ((cub->sh = ft_grab_rsl(fd, cub)) == -1
		|| cub->tmp_c != '\n')
		return (-1);
	cub->prs.flg_resol++;
	return (1);
}

int					ft_check_file(int fd, char buff[3], t_cub *cub)
{
	char			tmp_c[1];
    
	if (!read(fd, tmp_c, 1))
		return (0);
	while (tmp_c[0] == ' ' || tmp_c[0] == '\n')
		if (!read(fd, tmp_c, 1))
			return (0);
	buff[0] = tmp_c[0];
	read(fd, tmp_c, 1);
	buff[1] = tmp_c[0];
	if (buff[1] != ' ' && buff[1] != '1')
		read(fd, buff + 2, 1);
	if (buff[0] == 'W' && buff[1] == 'E' && buff[2] == ' ')
		cub->prs.flg_w++;
	if (buff[0] == 'N' && buff[1] == 'O' && buff[2] == ' ')
		cub->prs.flg_n++;
	if (buff[0] == 'S' && buff[1] == 'O' && buff[2] == ' ')
		cub->prs.flg_s++;
	if (buff[0] == 'S' && buff[1] == ' ')
		cub->prs.flg_sp++;
	if (buff[0] == 'E' && buff[1] == 'A' && buff[2] == ' ')
		cub->prs.flg_e++;
	return (1);
}

int					ft_grab_flgs_data(int fd, char tmp_c[3], t_cub *cub)
{
	int				val;

	val = -1;
	if (tmp_c[0] == 'R' && tmp_c[1] == ' ')
		val = ft_check_rsl_flag(fd, cub);
	if (tmp_c[0] == 'E' && tmp_c[1] == 'A' && tmp_c[2] == ' ')
		val = get_next_line(fd, &cub->prs.p_e);
	if (tmp_c[0] == 'S' && tmp_c[1] == 'O' && tmp_c[2] == ' ')
		val = get_next_line(fd, &cub->prs.p_s);
	if (tmp_c[0] == 'N' && tmp_c[1] == 'O' && tmp_c[2] == ' ')
		val = get_next_line(fd, &cub->prs.p_n);
	if (tmp_c[0] == 'W' && tmp_c[1] == 'E' && tmp_c[2] == ' ')
		val = get_next_line(fd, &cub->prs.p_w);
	if (tmp_c[0] == 'S' && tmp_c[1] == ' ')
		val = get_next_line(fd, &cub->prs.p_sp);
	if (tmp_c[0] == 'F' && tmp_c[1] == ' ')
		val = ft_grab_colors(fd, tmp_c, cub);
	if (tmp_c[0] == 'C' && tmp_c[1] == ' ')
		val = ft_grab_colors(fd, tmp_c, cub);
	if (tmp_c[0] == '1')
		return (1);
	return (val);
}

int					ft_start_parsing(int fd, t_cub *cub)
{
	char			tmp_c[3];
	int				i;

	i = 8;
	while (i-- > 0)
	{
		if (!ft_check_file(fd, tmp_c, cub) || (ft_grab_flgs_data(fd, tmp_c, cub) == -1))
			return (-1);
		ft_bzero(tmp_c, 3);
	}
	if (!(cub->prs.flg_ceil == 1 && cub->prs.flg_floor == 1 &&
		cub->prs.flg_e == 1 && cub->prs.flg_s == 1 &&
		cub->prs.flg_resol == 1 && cub->prs.flg_n == 1 &&
		cub->prs.flg_w == 1 && cub->prs.flg_sp == 1))
		return (-1);
	(cub->sw < 360) ? cub->sw = 360 : 0;
	(cub->sw > 2560) ? cub->sw = 2560 : 0;
	(cub->sh < 240) ? cub->sh = 240 : 0;
	(cub->sh > 1600) ? cub->sh = 1600 : 0;
	if (ft_start_parsing_the_map(fd, cub) < 0)
		return (-3);
	if (cub->map_w < 3 || cub->map_h < 3)
		return (-4);
	return (0);
}
