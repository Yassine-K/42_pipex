/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:47:45 by ykhayri           #+#    #+#             */
/*   Updated: 2022/10/09 15:24:59 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*arr;
	unsigned char	k;

	i = 0;
	k = c;
	arr = (unsigned char *) b;
	while (i < len)
	{
		arr[i] = k;
		i++;
	}
	return (b);
}
