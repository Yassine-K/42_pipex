/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:04:23 by ykhayri           #+#    #+#             */
/*   Updated: 2022/10/11 20:10:56 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	is_in_str(unsigned char *s, int k)
{
	int				i;
	unsigned char	c;

	i = 0;
	c = (unsigned char) k;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (!c)
		return (i);
	return (-1);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	l;

	i = 0;
	l = is_in_str((unsigned char *)s, c);
	if (l >= 0)
	{
		while (i < l)
		{
			i++;
			s++;
		}
		return ((char *)s);
	}
	return (0);
}
