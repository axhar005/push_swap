/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:24:33 by oboucher          #+#    #+#             */
/*   Updated: 2023/05/04 15:14:57 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void ft_rra(t_dlst **a, bool print)
{
    t_dlst *head;
    head = *a;
    head = head->prev;
    if (print)
        ft_putendl_fd("rra", 1);
}

void ft_rrb(t_dlst **b, bool print)
{
    t_dlst *head;
    head = *b;
    head = head->prev;
    if (print)
        ft_putendl_fd("rrb", 1);
}

void ft_rrr(t_pile *pile, bool print)
{
    ft_rra(&pile->a, false);
    ft_rrb(&pile->b, false);
    if (print)
        ft_putendl_fd("rrr", 1);
}