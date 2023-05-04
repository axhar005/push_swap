/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:24:30 by oboucher          #+#    #+#             */
/*   Updated: 2023/05/04 15:14:37 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

void ft_ra(t_dlst **a, bool print)
{
    t_dlst *head;
    head = *a;
    head = head->next;
    if (print)
        ft_putendl_fd("ra", 1);
}

void ft_rb(t_dlst **b, bool print)
{
    t_dlst *head;
    head = *b;
    head = head->next;
    if (print)
        ft_putendl_fd("rb", 1);
}

void ft_rr(t_pile *pile, bool print)
{
    ft_ra(&pile->a, false);
    ft_rb(&pile->b, false);
    if (print)
        ft_putendl_fd("rr", 1);
}