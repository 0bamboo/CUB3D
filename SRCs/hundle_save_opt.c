/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_save_opt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:36:39 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/14 13:09:41 by abdait-m         ###   ########.fr       */
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


// typedef	struct	s_bmp
// {
// 	int				w;
// 	int				h;
// 	unsigned short	bitcount;
// 	int				w_in_bytes;
// 	unsigned int	img_size;
// 	unsigned int	bi_size;
// 	unsigned int	bfi_size;
// 	unsigned int	file_size;
// 	unsigned short	bi_planes;
// 	unsigned char	header[54];
// 	int				*buff;
// }				t_bmp;
//void	init_saving(t_bmp *b, t_cub *cub)
// {
// 	b->w = cub->rsl.x;
// 	b->h = cub->rsl.y;
// 	b->bitcount = 32;
// 	b->w_in_bytes = ((b->w * b->bitcount + 31) / 32) * 4;
// 	b->img_size = b->w_in_bytes * b->h;
// 	b->bi_size = 40;
// 	b->bfi_size = 54;
// 	b->file_size = 54 + b->img_size;
// 	b->bi_planes = 1;
// 	ft_memcpy(b->header, "BM", 2);
// 	ft_memcpy(b->header + 2, &b->file_size, 4);
// 	ft_memcpy(b->header + 10, &b->bfi_size, 4);
// 	ft_memcpy(b->header + 14, &b->bi_size, 4);
// 	ft_memcpy(b->header + 18, &b->w, 4);
// 	ft_memcpy(b->header + 22, &b->h, 4);
// 	ft_memcpy(b->header + 26, &b->bi_planes, 2);
// 	ft_memcpy(b->header + 28, &b->bitcount, 2);
// 	ft_memcpy(b->header + 34, &b->img_size, 4);
// }

// int		save_bmp(t_cub *cub, int *buff)
// {
// 	int fd;
// 	int i;
// 	int j;
// 	int l;
// 	int m;

// 	if ((fd = open("./first_frame.bmp", O_RDWR | O_CREAT)) == -1 ||
// 			!(buff = (int *)malloc(cub->rsl.x * cub->rsl.y * sizeof(int))))
// 		free_cub_exit(cub, SAVING_BMP_ERROR);
// 	init_saving(&cub->bmp, cub);
// 	i = cub->rsl.y;
// 	l = 0;
// 	while (--i >= 0 && (j = cub->rsl.x))
// 	{
// 		m = -1;
// 		while (--j >= 0)
// 			buff[l * cub->rsl.x + ++m] = cub->img.buff[i * cub->rsl.x + j];
// 		l++;
// 	}
// 	write(fd, cub->bmp.header, 54);
// 	write(fd, buff, cub->rsl.x * cub->rsl.y * sizeof(int));
// 	free(buff);
// 	ft_putstr_fd("\nFirst frame saved successfully !\n", 1);
// 	close(fd);
// 	return (1);
// }