/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:25:24 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/08 17:47:29 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/// @brief swap two node in the same pile
void	swap_node(t_dlst **lst)
{
	t_dlst	*head;
	t_dlst	*tmp;

	tmp = *lst;
	head = (*lst)->next;
	head->prev = tmp->prev;
	tmp->next = head->next;
	tmp->prev = head;
	head->next = tmp;
	head->prev->next = head;
	tmp->prev->next = tmp;
	*lst = head;
}

/// @brief swap the 2 first node in a pile
/// @param a is the list
/// @param print bool for print sa
void	sa(t_dlst **a, int count, bool print)
{
	if (count > 2)
		swap_node(a);
	else
		ra(a, false);
	if (print)
		ft_putendl_fd("sa", 1);
}

/// @brief swap the 2 first node in b pile
/// @param b is the list
/// @param print bool for print sb
void	sb(t_dlst **b, int count, bool print)
{
	if (count > 2)
		swap_node(b);
	else
		ra(b, false);
	if (print)
		ft_putendl_fd("sb", 1);
}

/// @brief swap the 2 first node in a pile and b pile in same time
/// @param a is the list a
/// @param b is the list b
/// @param print bool for print ss
void	ss(t_pile pile, bool print)
{
	sa(&pile.a, pile.count_a, false);
	sb(&pile.b, pile.count_b, false);
	if (print)
		ft_putendl_fd("ss", 1);
}
