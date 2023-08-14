/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:27:40 by ykhayri           #+#    #+#             */
/*   Updated: 2022/10/09 14:55:05 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t n)
{
	size_t			i;
	unsigned char	*arr;
	unsigned char	*src;

	if (!d && !s)
		return ((void *)0);
	i = 0;
	arr = (unsigned char *) d;
	src = (unsigned char *) s;
	while (i < n)
	{
		arr[i] = src[i];
		i++;
	}
	return (d);
}
