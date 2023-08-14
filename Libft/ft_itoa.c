/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:30:47 by ykhayri           #+#    #+#             */
/*   Updated: 2022/10/05 10:20:31 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nbr(int n)
{
	int			l;
	long int	nbr;

	l = 0;
	nbr = n;
	if (nbr < 0)
	{
		l++;
		nbr *= -1;
	}
	if (nbr < 10)
		l++;
	else
	{
		l++;
		l += len_nbr(nbr / 10);
	}
	return (l);
}

char	*ft_itoa(int n)
{
	char		*s;
	int			len;
	long int	nbr;

	len = len_nbr(n);
	nbr = n;
	s = (char *) malloc(len + 1);
	if (!s)
		return (0);
	s[len] = '\0';
	if (n < 0)
		nbr *= -1;
	while (--len > 0)
	{
		s[len] = nbr % 10 + 48;
		nbr /= 10;
	}
	s[len] = nbr + 48;
	if (n < 0)
		s[0] = '-';
	return (s);
}
