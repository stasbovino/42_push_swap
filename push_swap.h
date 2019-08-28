#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <stdlib.h>

typedef struct	s_stack
{
	int				n;
	struct s_stack	*next;
}				t_stack;

void		sort(t_stack *a);
void		print_stack(t_stack *a);

#endif
