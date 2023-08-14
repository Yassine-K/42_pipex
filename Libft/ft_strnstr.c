/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 16:04:52 by ykhayri           #+#    #+#             */
/*   Updated: 2022/10/11 21:48:15 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	int		i;
	size_t	j;

	j = 0;
	i = (int) len;
	if (i < 0)
		len = ft_strlen(h) + 1;
	i = 0;
	if (!len && !h)
		return (0);
	if (n[i] == '\0')
		return ((char *) h);
	while (h[i] && j < len)
	{
		while (h[i] == n[i] && j + i < len)
		{
			i++;
			if (n[i] == '\0')
				return ((char *) h);
		}
		j++;
		i = 0;
		h++;
	}
	return (0);
}
