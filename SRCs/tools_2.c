/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:26:44 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/14 09:04:08 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(const char *str, int fd)
{
	if (!str)
		return ;
	while (*str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}

char	*ft_strdup(const char *s)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = ft_strlen(s);
	if (!(tmp = (char *)malloc(len + 1)))
		return (0);
	while (i <= len)
	{
		tmp[i] = s[i];
		i++;
	}
	return (tmp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		j;
	char		*sub;

	if (!s || !(sub = (char *)malloc(len + 1)))
		return (NULL);
	if (start > len)
		return (ft_strdup(""));
	j = 0;
	while (j < len)
		sub[j++] = s[start++];
	sub[j] = '\0';
	return (sub);
}

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		pos;
	size_t		i;
	char		*s;

	s = (char *)str;
	if (!*to_find)
		return (s);
	pos = 0;
	while (s[pos] != '\0' && pos < len)
	{
		if (s[pos] == to_find[0])
		{
			i = 1;
			while (to_find[i] != '\0' && (pos + i) < len)
			{
				if (to_find[i] != s[pos + i])
					break ;
				++i;
			}
			if (to_find[i] == '\0')
				return (s + pos);
		}
		++pos;
	}
	return (0);
}
