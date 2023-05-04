/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:25:24 by oboucher          #+#    #+#             */
/*   Updated: 2023/05/03 20:11:18 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sa(t_dlist *a)
{
	int	temp;

	if (a->next != NULL)
	{
		temp = a->content;
		a->content = a->next->content;
		a = a->next;
		a->content = temp;
	}
}

void ft_sb(t_dlist *b)
{
	int	temp;

	if (b->next != NULL)
	{
		temp = b->content;
		b->content = b->next->content;
		b = b->next;
		b->content = temp;
	}
}

void ft_ss(t_dlist *a, t_dlist *b)
{
	ft_sa(a);
	ft_sb(b);
}

void ft_pa(t_dlist *a, t_dlist *b)
{
	if (b != NULL)
	{
		
	}
}
