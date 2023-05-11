#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//include
# include "libft/inc/libft.h"
# include <stdbool.h>

//struct

typedef struct s_dlst
{
	int				content;
	int 			index;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

typedef struct s_pile
{
	int 			count_a;
	int 			count_b;
	t_dlst			*a;
	t_dlst			*b;
}					t_pile;

//prototype

void				push(t_dlst **a, t_dlst **b);
void				pa(t_pile *pile);
void				pb(t_pile *pile);
void				ra(t_dlst **a, bool print);
void				rb(t_dlst **b, bool print);
void				rr(t_pile *pile, bool print);
void				rra(t_dlst **a, bool print);
void				rrb(t_dlst **b, bool print);
void				rrr(t_pile *pile, bool print);
void				ft_push_node(t_dlst **lst);
void				sa(t_dlst **a, bool print);
void				sb(t_dlst **b, bool print);
void				ss(t_dlst **a, t_dlst *b, bool print);
#endif