/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdait-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:10:06 by abdait-m          #+#    #+#             */
/*   Updated: 2020/11/13 14:33:32 by abdait-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(const char *s)
{
	size_t		j;

	j = 0;
	while (*s != '\0')
	{
		j++;
		s++;
	}
	return (j);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while (*p)
	{
		if (*p == (unsigned char)c)
			return (p);
		p++;
	}
	if (c == '\0')
		return (p);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	size_t	i;

	p = (char *)s;
	i = 0;
	while (p[i])
		i++;
	if ((unsigned char)c == '\0')
		return (p + i);
	while (i)
	{
		if (p[i] == (unsigned char)c)
			return (p + i);
		i--;
	}
	if ((unsigned char)c == p[0])
		return (p);
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	*t;

	p = (unsigned char *)s1;
	t = (unsigned char *)s2;
	i = 0;
	while (p[i] != '\0' && t[i] != '\0' && i < n)
	{
		if (p[i] != t[i])
			return (p[i] - t[i]);
		i++;
	}
	if (i != n)
		return (p[i] - t[i]);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	*join;

	k = 0;
	if (!s1 || !s2)
		return (0);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	l = i + j;
	if (!(join = (char *)malloc((l + 1) * sizeof(char))))
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		join[i] = s2[j];
		i++;
	}
	join[i] = '\0';
	return (join);
}
