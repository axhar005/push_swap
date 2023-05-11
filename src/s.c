/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:25:24 by oboucher          #+#    #+#             */
/*   Updated: 2023/05/11 10:00:07 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/// @brief swap two node in the same pile
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

/// @brief swap the 2 first node in a pile
/// @param a is the list
/// @param print bool for print sa
void	sa(t_dlst **a, bool print)
{
	t_dlst *head;

	head = *a;
	if (head->next != head && head->next->content != head)
		ft_push_node(*a);
	else
		ra(*a, false);
}

/// @brief swap the 2 first node in b pile
/// @param b is the list
/// @param print bool for print sb
void	sb(t_dlst **b, bool print)
{
	t_dlst *head;

	head = *b;
	if (head->next != head && head->next->content != head)
		ft_push_node(*b);
	else
		ra(*b, false);
}

/// @brief swap the 2 first node in a pile and b pile in same time 
/// @param a is the list a
/// @param b is the list b
/// @param print bool for print ss
void	ss(t_dlst **a, t_dlst *b, bool print)
{
	sa(a, false);
	sb(b, false);
	if (print)
		ft_putendl_fd("ss", 1);
}