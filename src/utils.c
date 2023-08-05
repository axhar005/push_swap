/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:50:15 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/05 10:25:57 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int *av_int_array(int ac, char **av)
{
    int *nbr_lst;
    int i;

    i = 0;
    nbr_lst = ft_calloc(ac, sizeof(int));
    if (!nbr_lst)
        return (NULL);
    while (av[i])
    {
        nbr_lst[i] = ft_atoi(av[i]);
        i++;
    }
    return (nbr_lst);
}

void index_dlst(int ac, char **av, t_pile *pile)
{
    t_dlst *head_a;
    int *nbr_lst;
    int index;
    int i;
    int j;

    i = 1;
    head_a = pile->a;
    nbr_lst = av_int_array(ac, av);
    if (!nbr_lst)
        ft_exit("Error\n>index impossible");
    while (i < ac)
    {
        j = 0;
        index = ac - 1;
        while (j < ac)
        {
            if (nbr_lst[i] < nbr_lst[j] && j != i)
                index--;
            j++;
        }
        ft_dlst_add(&head_a, 0);
        head_a->index = index;
        head_a = head_a->next;
        ft_printf("index : %d\n", index);
        ft_printf("content : %d\n", nbr_lst[i]);
        ft_printf("\n");
        i++;
    }
    ft_sfree(nbr_lst);
}

bool    is_list_sort(t_dlst **lst)
{
    t_dlst *head;

    head = *lst;
    while (head->next != (*lst))
    {
        if (head->index > head->next->index)
            return (false);
        head = head->next;
    }
    return (true);
}