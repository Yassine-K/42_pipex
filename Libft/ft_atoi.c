/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:53:25 by ykhayri           #+#    #+#             */
/*   Updated: 2023/02/22 19:27:26 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(const char *str)
{
	int			i;
	long int	res;
	int			s;

	i = 0;
	res = 0;
	s = 1;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	if (str[i])
		return (2147483648);
	return (res * s);
}
