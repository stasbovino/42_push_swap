#include "push_swap.h"

void		sort_two(t_stack **a, t_stack **b, char s)
{
	if (s == 'a')
	{
		if ((*a)->n > (*a)->next->n)
			swap(a, b, s);
	}
	else
	{
		if ((*b)->n < (*b)->next->n)
			swap(a, b, s);
		push(a, b, s);
		push(a, b, s);
	}
}
