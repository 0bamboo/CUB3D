/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 17:26:53 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/12 17:26:53 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int					ft_set_texs(t_cub *cub)
{
	if (ft_sprite_tex(cub) < 0)
		return (-1);
	if (ft_south_tex(cub) < 0)
		return (-1);
	if (ft_west_tex(cub) < 0)
		return (-1);
	if (ft_east_tex(cub) < 0)
		return (-1);
	if (ft_north_tex(cub) < 0)
		return (-1);
	return (1);
}

int					ft_start_end_ln(char *ln)
{
	while (*ln)
	{
		if (*ln != '1' && *ln != ' ')
			return (0);
		ln++;
	}
	return (1);
}

static int					ft_check_file_extension(char *str)
{
	if (ft_strnstr(str, ".cub", ft_strlen(str)) && !ft_strncmp(ft_strnstr(str, ".cub",ft_strlen(str)), ".cub", 5))
		return (1);
	return (0);
}

static int					ft_check_save_opt(char *str, t_cub *cub)
{
	int				val;

	if (!ft_strncmp(str, "--save", 7))
	{
		cub->mlx_ptr = mlx_init();
		cub->sv.save = 1;
		val = ft_set_texs(cub);
		cub->img_ptr = mlx_new_image(cub->mlx_ptr, cub->sw, cub->sh);
		cub->data = (int *)mlx_get_data_addr(cub->img_ptr, &cub->ppx, &cub->s_line, &cub->endian);
		ft_start_game(cub);
		cub->sc = cub->data;
		ft_store_the_img(cub, "cub3d.bmp");
		ft_game_over(cub);
		free(cub->sc);
		return (1);
	}
	return (0);
}

int					main(int ac, char **av)
{
	int				er;
	int				fd;
	t_cub			cub;
    
	if (ac != 2 && ac != 3)
		return (ft_return_error(-8));
	if (!ft_check_file_extension(av[1]))
		return (ft_return_error(-2));
	ft_init_vars(&cub);
	fd = open(av[1], O_RDONLY);
	if ((er = ft_start_parsing(fd, &cub)) < 0)
		return (ft_return_error(er));
	close(fd);
	if (ac == 3)
	{
		if (!ft_check_save_opt(av[2], &cub))
			ft_return_error(-7);
		return (0);
	}
	if ((er = ft_init_game(&cub)) < 0)
		return (ft_return_error(er));
	return (0);
}
