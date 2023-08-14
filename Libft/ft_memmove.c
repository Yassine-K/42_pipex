/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:58:47 by ykhayri           #+#    #+#             */
/*   Updated: 2022/10/09 16:04:23 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *) src;
	d = (unsigned char *) dst;
	if (!src && !dst)
		return (0);
	if (d > s)
	{
		while (len--)
			d[len] = s[len];
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}
