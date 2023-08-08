/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:27:47 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/08 17:45:38 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	norm1(int ac, int *nbr_lst, t_dlst **lst)
{
	t_dlst	*head;
	int		index;
	int		i;
	int		j;

	i = 0;
	head = *lst;
	while (i < ac - 1)
	{
		j = 0;
		index = ac - 1;
		while (j < ac)
		{
			if (nbr_lst[i] < nbr_lst[j])
				index--;
			j++;
		}
		head->content = nbr_lst[i];
		head->index = index;
		head = head->next;
		i++;
	}
}

void	index_dlst(int ac, char **av, t_dlst **lst)
{
	t_dlst	*head;
	int		*nbr_lst;

	nbr_lst = av_int_array(ac, av);
	head = (*lst);
	if (!nbr_lst)
		ft_ps_exit("Error");
	norm1(ac, nbr_lst, lst);
	ft_sfree(nbr_lst);
}
