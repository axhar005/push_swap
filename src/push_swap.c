/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:47:34 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/05 10:27:33 by oboucher         ###   ########.fr       */
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
			ft_exit("Error\n>not found");
		if (char_count(av[i], '-') > 1)
			ft_exit("Error\n>to many -");
		if (char_count(av[i], '-') == 1 && av[i][0] != '-')
			ft_exit("Error\n>not - at start");
		check_double(ac, av);
		i++;
	}
}

int main(int ac, char **av)
{
    t_pile pile;
    
    if (ac > 2)
    {
        pars(ac, av);
		index_dlst(ac, av, &pile);
		pile.total = ac;
		pile.count_a = ac;

		// if (is_list_sort(&pile.a))
		// 	ft_printf("trier");
		// if (!is_list_sort(&pile.a))
		// 	ft_printf("pas trier");
    }
    return (0);
}