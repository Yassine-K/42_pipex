/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:41:25 by ykhayri           #+#    #+#             */
/*   Updated: 2023/02/25 20:23:26 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s1)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2) + len1;
	str = (char *) malloc(len2 + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, len1 + 1);
	ft_strlcat(str, s2, len2 + 1);
	return (str);
}
