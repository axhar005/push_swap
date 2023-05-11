/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:30:34 by oboucher          #+#    #+#             */
/*   Updated: 2023/05/10 12:46:50 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void push(t_dlst **a, t_dlst **b)
{
	t_dlst *head_a;
	t_dlst *head_b;
	
	head_a = (*a)->next;
	head_a->prev = (*a)->prev;
	head_a->prev->next = head_a;
	head_b = (*a);
	if (!(*a))
	{
		head_b->next = head_b;
		head_b->prev = head_b;
		*a = NULL;
	}
	else
	{
		head_b->next = (*b);
		head_b->prev = (*b)->prev;
		head_b->next->prev = head_b;
		head_b->prev->next = head_b;
		*a = head_a;
		*b = head_b;
	}
}

void	ft_pa(t_pile *pile)
{
	if (!pile->b)
		return ;
	if (!pile->a)
	{
		push(&pile->a, &pile->b);
		ft_putendl_fd("pa", 1);
	}
}

void	ft_pb(t_pile *pile)
{
	if (!pile->a)
		return ;
	if (!pile->b)
	{
		push(&pile->b, &pile->a);
		ft_putendl_fd("pb", 1);
	}
}

// void empty_push(t_dlst **a, t_dlst **b)
// {
// 	t_dlst *head_a;
// 	t_dlst *head_b;
	
// 	head_a = (*a)->next;
// 	head_a->prev = (*a)->prev;
// 	head_a->prev->next = head_a;
// 	head_b = (*a);
// 	head_b->next = head_b;
// 	head_b->prev = head_b;
// 	(*a) = head_a;
// 	(*b) = head_b;
// }