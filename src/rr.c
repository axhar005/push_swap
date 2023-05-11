/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 12:24:30 by oboucher          #+#    #+#             */
/*   Updated: 2023/05/11 10:00:47 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

/// @brief rotate the a pile
/// @param a is the a list
/// @param print bool for print ra
void ft_ra(t_dlst **a, bool print)
{
    t_dlst *head;
    head = *a;
    head = head->next;
    if (print)
        ft_putendl_fd("ra", 1);
}

/// @brief rotate the b pile
/// @param b is the b list
/// @param print bool for print rb
void ft_rb(t_dlst **b, bool print)
{
    t_dlst *head;
    head = *b;
    head = head->next;
    if (print)
        ft_putendl_fd("rb", 1);
}

/// @brief rotate the a and b pile
/// @param pile is the b list
/// @param print bool for print rr
void ft_rr(t_pile *pile, bool print)
{
    ft_ra(&pile->a, false);
    ft_rb(&pile->b, false);
    if (print)
        ft_putendl_fd("rr", 1);
}