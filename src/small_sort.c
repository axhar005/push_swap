/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:47:21 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/08 16:10:08 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_two_a(t_pile *pile)
{
	if (pile->a->content > pile->a->next->content)
		sa(&pile->a, pile->count_a, true);
}

void	sort_two_b(t_pile *pile)
{
	if (pile->b->content < pile->b->next->content)
		sb(&pile->b, pile->count_b, true);
}

void	sort_three_a(t_pile *pile)
{
	t_dlst	*first;
	t_dlst	*mid;
	t_dlst	*last;

	first = pile->a;
	mid = pile->a->next;
	last = pile->a->prev;
	if (first->content > last->content && first->content > mid->content)
	{
		ra(&pile->a, true);
		sort_three_a(pile);
	}
	else if (first->content < mid->content && mid->content > last->content)
	{
		rra(&pile->a, true);
		sort_three_a(pile);
	}
	else if (first->content > mid->content && first->content < last->content)
		sa(&pile->a, pile->count_a, true);
}

void	sort_three_b(t_pile *pile)
{
	t_dlst	*first;
	t_dlst	*mid;
	t_dlst	*last;

	first = pile->b;
	mid = pile->b->next;
	last = pile->b->prev;
	if (first->content < mid->content && first->content < last->content)
	{
		rb(&pile->b, true);
		sort_three_b(pile);
	}
	else if (mid->content < first->content && mid->content < last->content)
	{
		rrb(&pile->b, true);
		sort_three_b(pile);
	}
	else if (mid->content > first->content && mid->content > last->content)
		sb(&pile->b, pile->count_b, true);
}

void	all_small_sort(t_pile *pile)
{
	if (pile->total > 3)
	{
		while (pile->count_a > 3)
		{
			if (pile->a->index <= pile->total - 3)
				pb(pile, true);
			else
				ra(&pile->a, true);
		}
	}	
	if (pile->count_b == 2)
		sort_two_b(pile);
	else if (pile->count_b == 3)
		sort_three_b(pile);
	if (pile->count_a == 2)
		sort_two_a(pile);
	else if (pile->count_a == 3)
		sort_three_a(pile);
	while (pile->count_b > 0)
		pa(pile, true);
}