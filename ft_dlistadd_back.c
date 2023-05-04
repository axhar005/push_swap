/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlistadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:00:44 by oboucher          #+#    #+#             */
/*   Updated: 2023/05/04 15:01:17 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	ft_dlstadd_back(t_dlst **lst, t_dlst *new)
{
	t_dlst	*head;
	t_dlst	*last;

	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		head = *lst;
		last = head->prev;
		last->next = new;
		new->prev = last;
		new->next = *lst;
		head->prev = new;
	}
}
