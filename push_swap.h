#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft.h"
#include <stdlib.h>

typedef struct	s_stack
{
	int				n;
	struct s_stack	*next;
}				t_stack;

t_stack		*create_struct(void);
t_stack		*create_stack(int argc, char **argv);
int			error(void);

void		sort(t_stack **a);
void		print_stack(t_stack *a);

int			push(t_stack **a, t_stack **b, char s);
void		swap(t_stack **a, t_stack **b, char s);
int			rotate(t_stack **a, t_stack **b, char s);
int			rev_rotate(t_stack **a, t_stack **b, char s);

void		sort_three(t_stack **a, t_stack **b, char s);
void		sort_two(t_stack **a, t_stack **b, char s);

int			check_valid(int argc, char **argv);

int			ch_push(t_stack **a, t_stack **b, char s);
void		ch_swap(t_stack **a, t_stack **b, char s);
int			ch_rotate(t_stack **a, t_stack **b, char s);
int			ch_rev_rotate(t_stack **a, t_stack **b, char s);

#endif
