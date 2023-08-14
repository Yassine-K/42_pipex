/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 16:30:07 by ykhayri           #+#    #+#             */
/*   Updated: 2023/02/22 21:26:17 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int val, int ind)
{
	t_list	*new_n;

	new_n = (t_list *) malloc(sizeof(t_list));
	if (!new_n)
		return (0);
	new_n->index = ind;
	new_n->val = val;
	new_n->next = NULL;
	return (new_n);
}
