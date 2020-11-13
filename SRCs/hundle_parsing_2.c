/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundle_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 21:07:31 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/12 21:07:31 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			ft_check_map_again(t_cub *cub)
{
	int		x;
	int		y;

	x = 0;
	if (!ft_start_end_ln(cub->map[x]))
		return (0);
	while (cub->map[x])
	{
		y = 0;
		while (cub->map[x][y])
		{
			if (cub->map[x][y] == ' ')
			{
				if (!ft_look_4_spaces(cub, x, y))
					return (0);
				cub->map[x][y] = '1';
			}
			y++;
		}
		x++;
	}
	if (!ft_start_end_ln(cub->map[--x]))
		return (0);
	return (1);
}

int			ft_check_ln_map(char *ln_map)
{
	while (*ln_map == ' ')
		ln_map++;
	if (*ln_map != '1')
		return (0);
	while (*ln_map)
	{
		if (*ln_map != '1' && *ln_map != '0' && *ln_map != ' ' && *ln_map != '2'
			&& *ln_map != 'W' && *ln_map != 'S' && *ln_map != 'E' && *ln_map != 'N')
			return (0);
		ln_map++;
	}
	if (*(ln_map - 1) != '1')
		return (0);
	return (1);
}

int			ft_map_struct(t_cub *cub, char *m_buff)
{
	int		nbr;
	int		i;

	i = 0;
	nbr = 0;
	cub->map = ft_split(m_buff, '\n');
	if (!ft_check_map_again(cub))
		return (-3);
	while (cub->map[i])
	{
		if (ft_strlen(cub->map[i]) > nbr)
			nbr = ft_strlen(cub->map[i]);
		i++;
	}
	i = 0;
	while (cub->map[i])
	{
		if (ft_strlen(cub->map[i]) < nbr)
			cub->map[i] = ft_strjoin(cub->map[i],ft_put_char_1(nbr - ft_strlen(cub->map[i])));
		i++;
	}
	if (ft_correct_map(cub, 1) < 0)
		return (-1);
	return (1);
}

int			ft_store_map(t_cub *cub, int fd, char *m_buff, char *ln_map)
{
	int			res;

	while (get_next_line(fd, &ln_map) > 0)
	{
		if (ln_map[0] == '\0')
		{
			free(ln_map);
			break ;
		}
		if (!ft_check_ln_map(ln_map))
			return (-3);
		m_buff = ft_strjoin(m_buff, ln_map);
		m_buff = ft_strjoin(m_buff, "\n");
		free(ln_map);
	}
	if (ln_map[0] != '\0')
	{
		m_buff = ft_strjoin(m_buff, ln_map);
		m_buff = ft_strjoin(m_buff, "\n");
		free(ln_map);
	}
	if ((res = ft_map_struct(cub, m_buff)) < 0)
		return (res);
	return (1);
}

int			ft_start_parsing_the_map(int fd, t_cub *cub)
{
	char	*m_buff;
	char	*ln_map;
	int		res;

	m_buff = ft_strdup("");
	while (1)
	{
		get_next_line(fd, &ln_map);
		if (ln_map[0] != '\0')
		{
			m_buff = ft_strjoin(m_buff, ln_map);
			m_buff = ft_strjoin(m_buff, "\n");
			free(ln_map);
			break ;
		}
	}
	if ((res = ft_store_map(cub, fd, m_buff, ln_map)) < 0)
		return (res);
	return (1);
}
