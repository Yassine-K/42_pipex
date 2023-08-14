/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:02:46 by ykhayri           #+#    #+#             */
/*   Updated: 2023/02/22 21:28:43 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	if (lst)
	{
		tmp = *lst;
		while (*lst)
		{
			tmp = tmp -> next;
			free(*lst);
			*lst = tmp;
		}
	}
}
