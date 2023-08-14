/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:06:15 by ykhayri           #+#    #+#             */
/*   Updated: 2022/10/10 16:13:07 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	size_t	len;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	while (is_in(set, s1[0]) && len)
	{
		s1++;
		len--;
	}
	while (is_in(set, s1[len - 1]) && len)
		len--;
	s = (char *) malloc(len + 1);
	if (!s)
		return (0);
	s[0] = 0;
	if (len > 0)
		ft_strlcpy(s, s1, len + 1);
	return (s);
}
