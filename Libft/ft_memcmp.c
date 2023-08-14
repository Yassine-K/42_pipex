/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:55:52 by ykhayri           #+#    #+#             */
/*   Updated: 2022/10/09 17:10:39 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *) s1;
	s = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && d[i] == s[i])
		i++;
	return (d[i] - s[i]);
}
