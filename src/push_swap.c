/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:47:34 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/08 16:11:00 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pars(int ac, char **av)
{
	int i;

	i = 1;
	while(av[i])
	{
		if (find_filter(av[1], "-0123456789"))
			ft_ps_exit("Error");
		if (char_count(av[i], '-') > 1)
			ft_ps_exit("Error");
		if (char_count(av[i], '-') == 1 && av[i][0] != '-')
			ft_ps_exit("Error");
		check_double(ac, av);
		i++;
	}
}

int main(int ac, char **av)
{
    t_pile pile;
    
    if (ac > 2)
    {
		 if (ac > 501)
		 	ft_ps_exit("Error");
        pars(ac, av);
		create_dlst(ac, &pile.a);
		index_dlst(ac, av, &pile.a);
		pile.total = ac - 1;
		pile.count_a = ac - 1;
		// print_list(pile.a);
		if(!is_list_sort(&pile.a))
		{
			if (pile.total == 2)
				sort_two_a(&pile);
			else if (pile.total > 2 && pile.total < 6)
				all_small_sort(&pile);
			else 
				radix_sort(&pile);
		}
    }
    return (0);
}