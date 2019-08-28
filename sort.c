/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:20:10 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/28 22:36:17 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_stacklen(t_stack *a)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int			count_median(t_stack *a, int size)
{
	int		i;
	int		sum;
	t_stack	*tmp;
	int		ret;

	sum = 0;
	i = -1;
	tmp = a;
	while (++i < size)
	{
		sum += tmp->n;
		tmp = tmp->next;
	}
	ret = sum / size;
	return (ret);
}

int			separation(t_stack **a, t_stack **b, char s, int size)
{
	int		median;
	t_stack	*tmp;
	int		i;
	int		count_rot;
	int		count_push;

	i = -1;
	count_push = 0;
	count_rot = 0;
	median = (s == 'a') ? count_median(*a, size) : count_median(*b, size);
	tmp = (s == 'a') ? *a : *b;
	while (++i < size)
	{
		if (tmp->n < median)
			count_push += push(a, b, s);
		else
			count_rot += rotate(a, b, s);
	}
	while (count_rot != 0)
		count_rot -= rev_rotate(a, b, s);
	return (count_push);
}

void		quicksort(t_stack **a, t_stack **b, int size, char s)
{
	int		count_push;

	if (size == 1 && s == 'b')
		push(a, b, s);
	if (size == 2)
		sort_two(a, b, s);
	if (size == 3)
		sort_three(a, b, s);
	if ((size == 1 && s == 'a') || size == 3 || size == 2)
		return ;
	count_push = separation(a, b, s, size);
	if (s == 'a')
		quicksort(a, b, size - count_push, 'a');
	else
		quicksort(a, b, count_push, 'b');
}

void		sort(t_stack **a)
{
	t_stack *b;
	int		size;

	b = NULL;
	size = count_stacklen(*a);
	if (size == 1)
		return ;
	quicksort(a, &b, size, 'a');
}
