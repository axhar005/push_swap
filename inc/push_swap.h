#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//include
# include "libft/inc/libft.h"
# include <stdbool.h>

//struct

typedef struct s_dlst
{
	int				content;
	struct s_dlst	*next;
	struct s_dlst	*prev;
}					t_dlst;

typedef struct s_pile
{
	t_dlst			*a;
	t_dlst			*b;
}					t_pile;

//prototype

#endif