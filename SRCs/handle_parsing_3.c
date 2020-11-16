/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_parsing_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <abdait-m@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:56:40 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/16 17:55:02 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char				*ft_put_char_1(int nbr)
{
	char			*ch;
	int				i;

	i = 0;
	ch = (char*)malloc(nbr + 1);
	while (i < nbr)
		ch[i++] = '1';
	ch[i] = '\0';
	return (ch);
}

int					ft_look_4_spaces(t_cub *cub, int x, int y)
{
	if (x > 0)
		if (cub->map[x - 1][y] != '1' && cub->map[x - 1][y] != ' ')
			return (0);
	if (cub->map[x + 1])
		if (cub->map[x + 1][y] != '1' && cub->map[x + 1][y] != ' ')
			return (0);
	if (y > 0)
		if (cub->map[x][y - 1] != '1' && cub->map[x][y - 1] != ' ')
			return (0);
	if (cub->map[x][y + 1])
		if (cub->map[x][y + 1] != '1' && cub->map[x][y + 1] != ' ')
			return (0);
	return (1);
}

int					ft_grab_colors_val(int fd, t_cub *cub)
{
	int				nbr;
	char			tmp_c[1];

	nbr = 0;
	if (!read(fd, tmp_c, 1))
		return (-1);
	while (tmp_c[0] == ' ')
		if (!read(fd, tmp_c, 1))
			return (-1);
	if (!(tmp_c[0] >= '0' && tmp_c[0] <= '9'))
		return (-1);
	while (tmp_c[0] >= '0' && tmp_c[0] <= '9')
	{
		nbr *= 10;
		nbr += tmp_c[0] - '0';
		if (!read(fd, tmp_c, 1))
			return (-1);
	}
	cub->tmp_c = tmp_c[0];
	if (nbr > 255 || nbr < 0)
		return (-1);
	return (nbr);
}

static	int			ft_ceil_rgb(int fd, t_cub *cub)
{
	if ((cub->prs.ceil_r = ft_grab_colors_val(fd, cub)) == -1
	|| cub->tmp_c != ',')
		return (-1);
	if ((cub->prs.ceil_g = ft_grab_colors_val(fd, cub)) == -1
	|| cub->tmp_c != ',')
		return (-1);
	if ((cub->prs.ceil_b = ft_grab_colors_val(fd, cub)) == -1
	|| cub->tmp_c != '\n')
		return (-1);
	return (0);
}

int					ft_grab_colors(int fd, char buff[3], t_cub *cub)
{
	if (buff[0] == 'F')
	{
		if ((cub->prs.flr_r = ft_grab_colors_val(fd, cub)) == -1
		|| cub->tmp_c != ',')
			return (-1);
		if ((cub->prs.flr_g = ft_grab_colors_val(fd, cub)) == -1
		|| cub->tmp_c != ',')
			return (-1);
		if ((cub->prs.flr_b = ft_grab_colors_val(fd, cub)) == -1
		|| cub->tmp_c != '\n')
			return (-1);
		cub->prs.flg_floor++;
	}
	else if (buff[0] == 'C')
	{
		if (ft_ceil_rgb(fd, cub) == -1)
			return (-1);
		cub->prs.flg_ceil++;
	}
	return (1);
}
