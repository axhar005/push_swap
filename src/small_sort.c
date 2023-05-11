/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:47:21 by oboucher          #+#    #+#             */
/*   Updated: 2023/05/11 12:02:31 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void	sort_three_a(t_pile *pile)
{
	int	first;
	int	middle;
	int	last;

	first = pile->a->index;
	middle = pile->a->next->index;
	last = pile->a->prev->index;
	if (first < middle && middle > last && first > last)
	{
		ra(pile->a, true);
		sort_three_a(pile);
	}
	if (first > middle && middle < first && first < last)
	{
		rra(pile->a, true);
		sort_three_a(pile);
	}
	if (first > middle && middle < last && first < last)
	{
		sa(pile->a, true);
		sort_three_a(pile);
	}
}

void	sort_four(t_pile *pile)
{
	t_dlst	*head;

	head = pile->a;
	if (head->prev->index == 1)
		rra(pile->a, true);
	else
		ra(pile->a, true);
	if (head->index == 1)
	{
		pb(pile);
		sort_three_a(pile);
		pa(pile);
		return ;
	}
	sort_four(pile);
}

void	sort_five(t_pile *pile)
{
    t_dlst	*head;

	head = pile->a;
	if (head->prev->index == 1 || head->prev->prev->index == 1)
		rra(pile->a, true);
	else
		ra(pile->a, true);
	if (head->index == 1)
	{
		pb(pile);
		sort_four(pile);
		pa(pile);
		return ;
	}
	sort_five(pile);
}