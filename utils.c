/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:37:17 by ykhayri           #+#    #+#             */
/*   Updated: 2023/03/16 22:33:24 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	has_them(char *s, char c)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (s[++i])
		if (s[i] == c)
			j++;
	return (j);
}

int	count_command(char **tab)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (tab[i])
	{
		if (has_them(tab[i], '\''))
		{
			if (has_them(tab[i], '\'') == 1)
			{
				i++;
				while (tab[i] && !has_them(tab[i], '\''))
					i++;
			}
		}
		s++;
		i++;
	}
	return (s);
}

char	*ft_joincmd(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s1)
		return (0);
	if (!s2)
		return (s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2) + len1 + 1;
	str = (char *) malloc(len2 + 1);
	if (!str)
		return (0);
	ft_strlcpy(str, s1, len1 + 1);
	if (s1[0])
		free(s1);
	if (s2[0] != '\'' || s2[0] != '\"')
		str[len1++] = ' ';
	str[len1] = '\0';
	ft_strlcat(str, s2, len2 + 1);
	return (str);
}

void	get_cmd(char **tab, t_data *d, char **cmd, int j[3])
{
	j[c] = 0;
	while (tab[j[i]])
	{
		if (has_them(tab[j[i]], '\'') || has_them(tab[j[i]], '\"'))
		{
			j[c] = '\'';
			if (!(has_them(tab[j[i]], '\'')))
				j[c] = '\"';
			if (has_them(tab[j[i]], j[c]) == 1)
			{
				d->tmp2 = ft_strdup(tab[j[i]]);
				while (tab[++j[i]] && !has_them(tab[j[i]], j[c]))
					d->tmp2 = ft_joincmd(d->tmp2, tab[j[i]]);
				d->tmp2 = offset_s(ft_joincmd(d->tmp2, tab[j[i]++]), 1);
				cmd[j[k]++] = ft_strdup(d->tmp2);
				free(d->tmp2);
			}
			else
				cmd[j[k]++] = ft_strdup(offset_s(tab[j[i]++], 0));
		}
		else
			cmd[j[k]++] = ft_strdup(tab[j[i]++]);
	}
	cmd[j[k]] = 0;
}

void	handle_child(t_data *d, char **cmd, char *p, char **ev)
{
	if (d->ind == 0)
		dup2(d->fd[in], 0);
	if (d->fd[in] < 0 && d->ind == 0)
		exit(1);
	if (d->ind > 0)
	{
		dup2(d->fd_curr[in], 0);
		close(d->fd_curr[in]);
		close(d->fd_curr[out]);
	}
	if (d->ind == d->count - 1)
		dup2(d->fd[out], 1);
	if (d->ind < d->count - 1)
	{
		dup2(d->fd_next[out], 1);
		close(d->fd_next[in]);
		close(d->fd_next[out]);
	}
	output_err(d, cmd);
	execve(p, cmd, ev);
	if (d->last)
		error_check(d, 'c');
	exit(127);
}
