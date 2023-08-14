/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:03:49 by ykhayri           #+#    #+#             */
/*   Updated: 2023/03/04 18:09:19 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;
	size_t	lens;
	size_t	i;
	int		j;

	if (!dstsize && !dst)
		return (0);
	len = ft_strlen(dst);
	lens = ft_strlen(src);
	if (len >= dstsize)
		return (dstsize + lens);
	i = len;
	j = 0;
	while (i < dstsize - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (lens + len);
}
