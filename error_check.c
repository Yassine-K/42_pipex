/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:31:32 by ykhayri           #+#    #+#             */
/*   Updated: 2023/03/16 22:32:50 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	error_check(t_data *d, char c)
{
	if (d->fd[in] == -1 && c == '1')
	{
		d->ex_s = 1;
		if (access(d->fl[in], F_OK) < 0)
			error_m(d->fl[in], 1);
		else if (access(d->fl[in], R_OK) < 0)
			error_m(d->fl[in], 0);
	}
	if (d->fd[out] == -1 && c == '2')
	{
		d->ex_s = 1;
		error_m(d->fl[out], 0);
		exit(1);
	}
	if (c == 'c')
	{
		d->ex_s = 127;
		error_m(d->curr, 2);
	}
}

void	trim_str(char **av, int i, int ac, t_data *d)
{
	while (av[i][0] == '\"' || av[i][0] == '\'')
	{
		av[i][ft_strlen(av[i]) - 1] = '\0';
		av[i]++;
	}
	if (i + 1 == ac - 1)
		d->last = 1;
	else
		d->last = 0;
}

char	*offset_s(char *s, int k)
{
	char	*tmp;
	int		i;

	i = 0;
	if (s[i] == '\'' || s[i] == '\"')
	{
		s[ft_strlen(s) - 1] = '\0';
		i++;
	}
	tmp = ft_strdup(s + i);
	if (k)
		free(s);
	return (tmp);
}

void	comm_err(t_data *d, char **final)
{
	if (d->curr)
		free(d->curr);
	d->curr = ft_strdup(final[0]);
	free_double(final);
}

void	output_err(t_data *d, char **cmd)
{
	if (d->last)
	{
		free(d->curr);
		d->curr = cmd[0];
		error_check(d, '2');
	}
}
