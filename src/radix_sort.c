/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:18:39 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/06 17:50:43 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void    radix_sort(t_pile *pile)
{
    int i;
    int j;

    i = 0;
    while (!is_list_sort(&pile->a))
    {
        j = 0;
        while (j++ < pile->total)
        {
            if (((pile->a->content >> i) & 1) == 1)
                ra(&pile->a, true);
            else
                pb(pile, true);
        }
        i++;
        while (pile->count_b != 0)
            pa(pile, true);
    }
    
}