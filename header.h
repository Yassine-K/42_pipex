/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:02:27 by ykhayri           #+#    #+#             */
/*   Updated: 2023/03/16 22:33:36 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "Libft/libft.h"
# include "getNext/get_next_line.h"
# include <fcntl.h>

typedef struct s_data{
	char	**paths;
	char	*fl[2];
	char	*tmp2;
	char	*tmp;
	char	*curr;
	int		fd[2];
	int		fd_next[2];
	int		fd_curr[2];
	int		count;
	int		ind;
	int		ex_s;
	int		last;
}		t_data;

int		has_them(char *s, char c);
int		count_command(char **tab);
void	swap_fd(t_data *d);
void	get_cmd(char **tab, t_data *d, char **cmd, int i[3]);
void	handle_child(t_data *d, char **cmd, char *p, char **ev);
int		check_empty(char **av, int ac);
void	pipe_mode(t_data *d, int *i, int ac, char **av);
void	error_check(t_data *d, char c);
void	error_m(char *s, int i);
void	trim_str(char **av, int i, int ac, t_data *d);
char	*offset_s(char *s, int i);
void	comm_err(t_data *d, char **final);
void	free_double(char **fr);
void	output_err(t_data *d, char **cmd);

enum e_files {in, out};
enum e_vars {i, k, c};

#endif
