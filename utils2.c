/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:39:18 by ykhayri           #+#    #+#             */
/*   Updated: 2023/03/16 18:00:37 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	swap_fd(t_data *d)
{
	if (d->ind > 0)
	{
		close(d->fd_curr[in]);
		close(d->fd_curr[out]);
	}
	if (d->ind < d->count - 1)
	{
		d->fd_curr[in] = d->fd_next[in];
		d->fd_curr[out] = d->fd_next[out];
	}
}

int	check_empty(char **av, int ac)
{
	int	i;

	i = 0;
	while (i < ac)
	{
		if (!av[i][0])
			return (0);
		i++;
	}
	return (1);
}

void	fill_file(t_data *d, char *lim)
{
	char	*final;
	char	*tmp;

	final = ft_strdup("");
	while (1)
	{
		tmp = get_next_line(0);
		if (!tmp)
			break ;
		if (!ft_strncmp(tmp, lim, ft_strlen(lim)))
			break ;
		final = ft_strjoin_g(final, tmp, ft_strlen(tmp));
		free(tmp);
	}
	if (tmp)
		free(tmp);
	ft_putstr_fd(final, d->fd[in]);
	close(d->fd[in]);
	free(final);
	d->fd[in] = open(d->fl[in], O_RDONLY);
}

void	error_m(char *s, int i)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(s, 2);
	if (i == 0)
		ft_putstr_fd(": Permission denied\n", 2);
	if (i == 1)
		ft_putstr_fd(": No such file or directory\n", 2);
	if (i == 2)
		ft_putstr_fd(": command not found\n", 2);
}

void	pipe_mode(t_data *d, int *i, int ac, char **av)
{
	if (!M && !ft_strncmp(av[1], "here_doc", 8))
	{
		d->fl[in] = "/tmp/here_doc_f";
		d->fd[in] = open(d->fl[in], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		fill_file(d, av[2]);
		d->fd[out] = open(d->fl[out], O_RDWR | O_APPEND | O_CREAT, 0644);
		d->count = ac - 4;
		*i = 2;
	}
	else
	{
		d->fl[in] = av[1];
		d->fd[in] = open(d->fl[in], O_RDONLY);
		d->fd[out] = open(d->fl[out], O_WRONLY | O_TRUNC | O_CREAT, 0644);
		d->count = ac - 3;
		*i = 1;
	}
	error_check(d, '1');
}
