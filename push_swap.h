#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <stdlib.h>

typedef struct	s_stack
{
	int				n;
	struct s_stack	*next;
}				t_stack;

void		sort(t_stack **a);
void		print_stack(t_stack *a);
int			push(t_stack **a, t_stack **b, char s);
void		swap(t_stack **a, t_stack **b, char s);
int			rotate(t_stack **a, t_stack **b, char s);
int			rev_rotate(t_stack **a, t_stack **b, char s);

void		sort_three(t_stack **a, t_stack **b, char s);
void		sort_two(t_stack **a, t_stack **b, char s);

int			check_valid(int argc, char **argv);

#endif
