/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:49:39 by ykhayri           #+#    #+#             */
/*   Updated: 2023/02/27 18:41:58 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define B_S 1337

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

# if BUFFER_SIZE < 0
#  undef B_S
#  define B_S -BUFFER_SIZE
#  undef BUFFER_SIZE
#  define BUFFER_SIZE B_S
#  undef B_S
#  define B_S -1
# endif

char	*get_next_line(int fd);
int		ft_lenstr(const char *s);
char	*ft_strjoin_g(char const *s1, char const *s2, int k);

#endif
