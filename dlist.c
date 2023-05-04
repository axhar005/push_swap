/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:25:24 by oboucher          #+#    #+#             */
/*   Updated: 2023/05/04 14:40:49 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	ft_push_node(t_dlst **lst)
{
	t_dlst *head;
	t_dlst *tmp;

	head = (*lst)->next;
	tmp = *lst;
	head->prev = tmp->prev;
	tmp->next = head->next;
	tmp->prev = head;
	head->next = tmp;
	head->prev->next = head;
	*lst = head;
}

void	ft_sa(t_dlst **a, bool print)
{
	t_dlst *head;

	head = *a;
	if (head->next != head && head->next->content != head)
		ft_push_node(*a);
	else
		ft_ra();
}

void	ft_sb(t_dlst **b, bool print)
{
	t_dlst *head;

	head = *b;
	if (head->next != head && head->next->content != head)
		ft_push_node(*b);
	else
		ft_ra(*b);
}

void	ft_ss(t_dlst **a, t_dlst *b, bool print)
{
	ft_sa(a, false);
	ft_sb(b, false);
	if (print)
		ft_putendl_fd("ss", 1);
}

void	ft_pa(t_dlst **a, t_dlst *b, bool print)
{
	if (b != NULL)
	{
	}
}
