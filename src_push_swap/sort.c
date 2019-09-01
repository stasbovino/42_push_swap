/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:42:43 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/01 21:20:22 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack **a)
{
	t_stack *tmp;
	int		prev;

	if (!(*a))
		return (0);
	tmp = *a;
	prev = tmp->n;
	while (tmp)
	{
		if (prev <= tmp->n)
		{
			prev = tmp->n;
			tmp = tmp->next;
		}
		else
			return (0);
	}
	return (1);
}

void		sort(t_stack **a)
{
	t_stack *b;
	int		size;

	b = NULL;
	size = count_stacklen(*a);
	if (size == 1)
		return ;
	if (is_sorted(a))
		return ;
	quicksort(a, &b, size, 'a');
}
