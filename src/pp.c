/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:30:34 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/08 17:46:20 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	std_push(t_dlst **a, t_dlst **b)
{
	t_dlst	*head_a;
	t_dlst	*head_b;

	head_a = (*a)->next;
	head_a->prev = (*a)->prev;
	head_a->prev->next = head_a;
	head_b = (*a);
	head_b->next = (*b);
	head_b->prev = (*b)->prev;
	head_b->next->prev = head_b;
	head_b->prev->next = head_b;
	(*a) = head_a;
	(*b) = head_b;
}

void	empty_push(t_dlst **a, t_dlst **b)
{
	t_dlst	*head_a;
	t_dlst	*head_b;

	head_a = (*a)->next;
	head_a->prev = (*a)->prev;
	head_a->prev->next = head_a;
	head_b = (*a);
	head_b->next = head_b;
	head_b->prev = head_b;
	(*a) = head_a;
	(*b) = head_b;
}

void	last_push(t_dlst **a, t_dlst **b)
{
	t_dlst	*head_b;

	head_b = (*a);
	head_b->next = (*b);
	head_b->prev = (*b)->prev;
	head_b->next->prev = head_b;
	head_b->prev->next = head_b;
	(*a) = NULL;
	(*b) = head_b;
}

void	pa(t_pile *pile, bool print)
{
	if (!pile->b)
		return ;
	if (pile->count_a == 0)
		empty_push(&pile->b, &pile->a);
	else if (pile->count_b == 1)
		last_push(&pile->b, &pile->a);
	else
		std_push(&pile->b, &pile->a);
	pile->count_a++;
	pile->count_b--;
	if (print)
		ft_putendl_fd("pa", 1);
}

void	pb(t_pile *pile, bool print)
{
	if (!pile->a)
		return ;
	if (pile->count_b == 0)
		empty_push(&pile->a, &pile->b);
	else if (pile->count_a == 1)
		last_push(&pile->a, &pile->b);
	else
		std_push(&pile->a, &pile->b);
	pile->count_a--;
	pile->count_b++;
	if (print)
		ft_putendl_fd("pb", 1);
}
