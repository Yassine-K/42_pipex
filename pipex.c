/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:02:18 by ykhayri           #+#    #+#             */
/*   Updated: 2023/03/16 22:35:16 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_double(char **fr)
{
	int	i;

	i = -1;
	while (fr[++i])
		free(fr[i]);
	free(fr);
}

int	run_command(char **tab, t_data *d, char *p, char **ev)
{
	char	**cmd;
	int		j[3];
	pid_t	id;

	j[i] = 0;
	j[k] = 0;
	id = 0;
	cmd = (char **) malloc(sizeof(char *) * count_command(tab) + 1);
	if (!cmd)
		return (0);
	get_cmd(tab, d, cmd, j);
	if (d->ind < d->count - 1)
		pipe(d->fd_next);
	if (!d->last)
		id = fork();
	if (id == -1)
		return (0);
	else if (!d->last && !id)
		handle_child(d, cmd, p, ev);
	else if (d->last)
		handle_child(d, cmd, p, ev);
	swap_fd(d);
	d->ind++;
	free_double(cmd);
	return (1);
}

int	what_command(t_data *d, char **final, char **ev)
{
	int		i[2];

	i[0] = -1;
	while (d->paths[++i[0]])
	{
		d->tmp2 = ft_strjoin(d->paths[i[0]], "/");
		d->tmp = ft_strjoin(d->tmp2, final[0]);
		free(d->tmp2);
		if (!access(d->tmp, X_OK))
		{
			i[1] = run_command(final, d, d->tmp, ev);
			free(d->tmp);
			free_double(final);
			d->ex_s = 0;
			if (!i[1])
				return (0);
			return (1);
		}
		if (!d->paths[i[0] + 1])
			run_command(final, d, d->tmp, ev);
		free(d->tmp);
	}
	comm_err(d, final);
	return (0);
}

void	get_path(t_data *d, char **ev)
{
	int	i;

	i = -1;
	d->paths = NULL;
	while (ev[++i])
	{
		if (!ft_strncmp(ev[i], "PATH=", 5))
		{
			d->paths = ft_split(ev[i] + 5, ':');
			break ;
		}
	}
	if (d->paths)
		return ;
	d->paths = ft_split("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:", ':');
}

int	main(int ac, char **av, char **ev)
{
	t_data	d;
	int		i;

	d.ex_s = 0;
	if (((ac == 5 && M) || (ac > 4 && !M)) && check_empty(av, ac))
	{
		d.curr = NULL;
		d.fl[out] = av[ac - 1];
		pipe_mode(&d, &i, ac, av);
		d.ind = 0;
		get_path(&d, ev);
		while (++i < ac - 1)
		{
			trim_str(av, i, ac, &d);
			if (!what_command(&d, ft_split(av[i], ' '), ev))
				error_check(&d, 'c');
		}
		error_check(&d, '2');
		free_double(d.paths);
	}
	else
		return (1);
	if (!M && d.count == ac - 4)
		unlink(d.fl[in]);
	return (d.ex_s);
}
