/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oboucher <oboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 18:50:15 by oboucher          #+#    #+#             */
/*   Updated: 2023/08/06 18:33:55 by oboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int *av_int_array(int ac, char **av)
{
    int *nbr_lst;
    int i;

    i = 1;
    nbr_lst = ft_calloc(ac, sizeof(int));
    if (!nbr_lst)
        return (NULL);
    while (av[i])
    {
        nbr_lst[i-1] = ft_atoi(av[i]);
        i++;
    }
    return (nbr_lst);
}

void print_list(t_dlst *head)
{
    t_dlst *temp = head;

    ft_printf("index : %d | content : %d | test : %d\n", temp->index, temp->content, temp->test);
    ft_printf("Prev : %p | Mine : %p | Next : %p\n\n", temp->prev, temp, temp->next);
    temp = temp->next;
    while(temp != head)
    {
        ft_printf("index : %d | content : %d\n", temp->index, temp->content);
    	ft_printf("Prev : %p | Mine : %p | Next : %p\n\n", temp->prev, temp, temp->next);
        temp = temp->next;
    } 
    
}
void create_dlst(int ac, t_dlst **lst)
{
    int i;

    i = 0;
    while (i < ac - 1)
    {
        ft_dlst_add(lst, 0);
        i++;
    }
}

void index_dlst(int ac, char **av, t_dlst **lst)
{
    int *nbr_lst;
    int index;
    int i;
    int j;
    t_dlst *head;

    i = 0;
    nbr_lst = av_int_array(ac, av);
    head = (*lst);
    if (!nbr_lst)
        ft_exit("Error\n>index impossible");
    while (i < ac - 1)
    {
        j = 0;
        index = ac - 1;
        while (j < ac)
        {
            if (nbr_lst[i] < nbr_lst[j] && j != i)
                index--;
            j++;
        }
		if (i == 0)
			head->test = 88;
        head->content = nbr_lst[i];
        head->index = index;
        head = head->next;
        i++;
    }
    ft_sfree(nbr_lst);
}

bool    is_list_sort(t_dlst **lst)
{
    t_dlst *head;

    head = *lst;
    while (head->next != *lst)
    {
        if (head->index > head->next->index)
            return (false);
        head = head->next;
    }
    return (true);
}