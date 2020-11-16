/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_save_opt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:36:39 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/16 10:33:24 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		ft_write_int(t_cub *cub, unsigned int val)
{
	cub->sv.bmp[cub->sv.indx++] = val >> 0;
	cub->sv.bmp[cub->sv.indx++] = val >> 8;
	cub->sv.bmp[cub->sv.indx++] = val >> 16;
	cub->sv.bmp[cub->sv.indx++] = val >> 24;
}

static void		ft_write_file_header(t_cub *cub)
{
	cub->sv.bmp[cub->sv.indx++] = 'B';
	cub->sv.bmp[cub->sv.indx++] = 'M';
	ft_write_int(cub, cub->sv.size);
	ft_write_int(cub, 0x00000000);
	cub->sv.bmp[cub->sv.indx++] = 54;
	cub->sv.bmp[cub->sv.indx++] = 0;
	cub->sv.bmp[cub->sv.indx++] = 0;
	cub->sv.bmp[cub->sv.indx++] = 0;
}

static void		ft_write_file_data(t_cub *cub)
{
	int		i;

	cub->sv.bmp[cub->sv.indx++] = 40;
	cub->sv.bmp[cub->sv.indx++] = 0;
	cub->sv.bmp[cub->sv.indx++] = 0;
	cub->sv.bmp[cub->sv.indx++] = 0;
	ft_write_int(cub, cub->sw);
	ft_write_int(cub, cub->sh);
	cub->sv.bmp[cub->sv.indx++] = 1;
	cub->sv.bmp[cub->sv.indx++] = 0;
	cub->sv.bmp[cub->sv.indx++] = 24;
	cub->sv.bmp[cub->sv.indx++] = 0;
	i = 0;
	while (i < 24)
	{
		cub->sv.bmp[cub->sv.indx++] = 0;
		i++;
	}
}

static void		ft_write_body(t_cub *cub)
{
	int		x;
	int		y;

	y = cub->sh - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < cub->sw)
		{
			cub->sv.bmp[cub->sv.indx++] = cub->sc[y * cub->sw + x] >> 0;
			cub->sv.bmp[cub->sv.indx++] = cub->sc[y * cub->sw + x] >> 8;
			cub->sv.bmp[cub->sv.indx++] = cub->sc[y * cub->sw + x] >> 16;
			x++;
		}
		x = 0;
		while (x < (4 - (cub->sw * 3) % 4) % 4)
		{
			cub->sv.bmp[cub->sv.indx++] = 0;
			x++;
		}
		y--;
	}
}

int				ft_store_the_img(t_cub *cub, char *name)
{
	int			fd;

	ft_init_bmp(cub);
	cub->sv.size = 54 + 3 * cub->sw * cub->sh;
	cub->sv.bmp = malloc(cub->sv.size);
	if ((fd = open(name, O_WRONLY | O_TRUNC | O_CREAT, 0666)) < 0)
		return (-1);
	ft_write_file_header(cub);
	ft_write_file_data(cub);
	ft_write_body(cub);
	if (!write(fd, cub->sv.bmp, cub->sv.size))
		return (-1);
	close(fd);
	free(cub->sv.bmp);
	return (0);
}
