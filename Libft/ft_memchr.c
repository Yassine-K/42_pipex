/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:14:24 by ykhayri           #+#    #+#             */
/*   Updated: 2023/03/04 18:01:52 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	is_in_str(unsigned char *s, int c, size_t l)
{
	size_t			i;
	unsigned char	k;

	i = 0;
	k = c;
	while (l > i)
	{
		if (s[i] == k)
			return (i);
		i++;
	}
	return (-1);
}

static char	*ft_chr(const char *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		i++;
		s++;
	}
	return ((char *)s);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				f;
	unsigned char	*arr;

	f = is_in_str((unsigned char *) s, c, n);
	if (f < 0)
		return (NULL);
	arr = (unsigned char *) ft_chr((const char *) s, f);
	return ((void *) arr);
}
