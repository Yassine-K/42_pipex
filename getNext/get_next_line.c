/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:49:02 by ykhayri           #+#    #+#             */
/*   Updated: 2023/02/27 18:41:45 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	has_n(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_cutstr(char *s, int k)
{
	int	i;

	i = 0;
	if (k < 0)
	{
		free(s);
		return (0);
	}
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		s[i + 1] = '\0';
	return (s);
}

static void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = -1;
	if (n < 0)
		n++;
	while (src[++i] && i < n)
		dest[i] = src[i];
	while (i < n || i < BUFFER_SIZE)
	{
		dest[i] = '\0';
		i++;
	}
}

char	*ft_strjoin_g(char const *s1, char const *s2, int k)
{
	char	*str;
	int		h;

	h = -1;
	k += ft_lenstr(s1);
	str = (char *) malloc(k + 1);
	if (!str)
		return (0);
	k = -1;
	while (s1[++k])
		str[k] = s1[k];
	while (s2[++h])
		str[k + h] = s2[h];
	str[k + h] = '\0';
	if (s1[0])
		free((void *)s1);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE + 1];
	char		*f;
	int			k;

	if (fd == 1 || fd == 2 || fd < 0 || B_S < 0)
		return (0);
	k = BUFFER_SIZE;
	if (!str[0] && k > 0)
		k = read(fd, str, BUFFER_SIZE);
	if (k <= 0)
		return (0);
	f = "";
	f = ft_strjoin_g(f, str, k);
	while (has_n(str) < 0 && k > 0)
	{
		k = read(fd, str, BUFFER_SIZE);
		if (k < BUFFER_SIZE)
			ft_strncpy(str, str, k);
		if (k > 0)
			f = ft_strjoin_g(f, str, k);
	}
	f = ft_cutstr(f, k);
	ft_strncpy(str, str + has_n(str) + 1, BUFFER_SIZE);
	return (f);
}
