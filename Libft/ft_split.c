/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:22:44 by ykhayri           #+#    #+#             */
/*   Updated: 2023/03/04 18:02:23 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	alloc_sp(char const *s, char c)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i] == c)
			len++;
	}
	if (s[i - 1] != c)
		len++;
	if (!len)
		len = 1;
	return (len);
}

static int	ft_end(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static char	**fill_arr(char **a, const char *s, int l, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		l = ft_end(s, c);
		if (l > 0)
		{
			a[i] = (char *) malloc(l + 1);
			if (!a[i])
				return (0);
			ft_strlcpy(a[i], s, l + 1);
			s += l;
			i++;
		}
		if (*s)
			s++;
	}
	a[i] = 0;
	return (a);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		len;

	if (!s)
		return (0);
	len = alloc_sp(s, c);
	if (!len)
		len = 1;
	arr = (char **) malloc(sizeof(char *) * (len + 1));
	if (!arr)
		return (0);
	if (!s)
	{
		arr[0] = (char *)malloc(1);
		arr[0] = "\0";
	}
	else
		arr = fill_arr(arr, s, len, c);
	return (arr);
}
