/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:24:33 by oboucher          #+#    #+#             */
/*   Updated: 2023/05/11 10:01:29 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

/// @brief reverse rotate a pile
/// @param a is the a list
/// @param print bool for print rra
void rra(t_dlst **a, bool print)
{
    t_dlst *head;
    head = *a;
    head = head->prev;
    if (print)
        ft_putendl_fd("rra", 1);
}

void rrb(t_dlst **b, bool print)
{
    t_dlst *head;
    head = *b;
    head = head->prev;
    if (print)
        ft_putendl_fd("rrb", 1);
}

void rrr(t_pile *pile, bool print)
{
    rra(&pile->a, false);
    rrb(&pile->b, false);
    if (print)
        ft_putendl_fd("rrr", 1);
}