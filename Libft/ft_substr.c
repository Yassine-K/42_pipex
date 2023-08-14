/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:24:54 by ykhayri           #+#    #+#             */
/*   Updated: 2022/10/12 18:40:42 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	char	*d;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	p = (char *) malloc(len + 1);
	if (!p)
		return (0);
	d = (char *) s;
	while (i < len)
	{
		p[i] = d[start + i];
		i++;
	}
	p[i] = 0;
	return (p);
}
