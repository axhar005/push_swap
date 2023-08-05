/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:47:34 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/04 23:07:49 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int find_filter(char *str, char *filter)
{
	size_t i;
	size_t j;

	i = 0;
	if (!str || !filter)
		return (-1);
	while (str[i])
	{
		j = 0;
		while (filter[j])
		{
			if (str[i] == filter[j])
				break;
			j++;
		}
		if (j == ft_strlen(filter))
			return (1);
		i++;
	}
	return (0);
}

void check_double(int ac, char **av)
{
	int i;
	int j;
	int *nbr_lst;

	i = 0;
	nbr_lst = av_int_array(ac, av);
	while (i < ac)
	{
		j = 0;
		while (j < ac)
		{
			if (nbr_lst[i] == nbr_lst[j] && j != i)
				ft_exit("Error\n>double number");
			j++;
		}
		i++;
	}
}

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
    }
    return (0);
}