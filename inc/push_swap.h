#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//include
#include "libft/inc/libft.h"
//struct

typedef struct s_dlist
{
	int				content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

typedef struct s_data
{
	t_dlist *a;
	t_dlist *b;
} 					t_data;

//prototype

#endif