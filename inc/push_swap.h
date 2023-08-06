#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//include
# include "../libft_/inc/libft.h"
# include <stdbool.h>
# include <unistd.h>

//struct

typedef struct s_dlst
{
	int				content;
	int				index;
	int				test;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

typedef struct s_pile
{
	int				count_a;
	int				count_b;
	int				total;
	t_dlst			*a;
	t_dlst			*b;
}					t_pile;

//prototype

//string

size_t				char_count(char *str, char c);

//pushswap

void				std_push(t_dlst **a, t_dlst **b);
void				empty_push(t_dlst **a, t_dlst **b);
void				last_push(t_dlst **a, t_dlst **b);
void				swap_node(t_dlst **lst);
void				pa(t_pile *pile, bool print);
void				pb(t_pile *pile, bool print);
void				ra(t_dlst **a, bool print);
void				rb(t_dlst **b, bool print);
void				ft_rr(t_pile *pile, bool print);
void				rra(t_dlst **a, bool print);
void				rrb(t_dlst **b, bool print);
void				rrr(t_pile *pile, bool print);
void				sa(t_dlst **a, int count, bool print);
void				sb(t_dlst **b, int count, bool print);
void				ss(t_pile pile, bool print);
void				index_dlst(int ac, char **av, t_dlst **lst);
int					*av_int_array(int ac, char **av);
void				sort_two_a(t_pile *pile);
void				all_small_sort(t_pile *pile);
void				radix_sort(t_pile *pile);

//dlst

void				ft_dlst_add(t_dlst **lst, int content);
t_dlst				*ft_dlst_new(int content);
t_pile				*set_pile(int ac, char **av);
void				create_dlst(int ac, t_dlst **lst);
void				print_list(t_dlst *head);
bool				is_list_sort(t_dlst **lst);

//pars

int					find_filter(char *str, char *filter);
void				check_double(int ac, char **av);

#endif