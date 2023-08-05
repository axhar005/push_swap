/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 13:00:44 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/04 22:14:53 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_dlst	*ft_dlst_new(int content)
{
	t_dlst	*new;

	new = ft_calloc(1, sizeof(t_dlst));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = new;
	new->prev = new;
	return (new);
}

void	ft_dlst_add(t_dlst **lst, int content)
{
	t_dlst	*new;
	t_dlst	*head;
	t_dlst	*last;
    
	new = ft_dlst_new(content);
	if (!new || !lst)
	{
		return ;
	}
	if (!(*lst))
	{
		*lst = new;
	}
	else
	{
		head = *lst;
		last = head->prev;
		last->next = new;
		new->next = head;
		new->prev = last;
		head->prev = new;
	}
}