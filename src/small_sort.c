/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:47:21 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/04 23:08:03 by oboucher         ###   ########.fr       */
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
		sa(&pile->b, pile->count_b, true);
}

void	sort_three_a(t_pile *pile)
{
	int	first;
	int	mid;
	int	last;

	first = pile->a->content;
	mid = pile->a->next->content;
	last = pile->a->prev->content;
	if (first > last && first > mid)
	{
		ra(&pile->a, true);
		sort_three_a(pile);
	}
	if (first < mid && mid > last)
	{
		rra(&pile->a, true);
		sort_three_a(pile);
	}
	if (first > mid && first < last)
		sa(&pile->a, pile->count_a, true);
}

void	sort_three_b(t_pile *pile)
{
	int	first;
	int	mid;
	int	last;

	first = pile->b->content;
	mid = pile->b->next->content;
	last = pile->b->prev->content;
	if (first < mid && first > last)
	{
		ra(&pile->b, true);
		sort_three_b(pile);
	}
	if (mid < first && mid < last)
	{
		rra(&pile->b, true);
		sort_three_b(pile);
	}
	if (mid > first && mid > last)
		sb(&pile->b, pile->count_b, true);
}

void	all_small_sort(t_pile *pile)
{
	// if (piles->total > 3)
	// {
	// 	while (piles->a_count > 3)
	// 	{
	// 		if (piles->a->index <= piles->total - 3)
	// 			pb(piles, 1);
	// 		else
	// 			ra(&piles->a, 1);
	// 	}
	// }	
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