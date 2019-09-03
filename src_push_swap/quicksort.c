/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:20:10 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/03 17:30:20 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				count_to_push(t_stack *a, char s, long long int med)
{
	t_stack *tmp;
	int		i;

	tmp = a;
	i = 0;
	while (tmp)
	{
		if ((s == 'a' && tmp->n <= med) || (s == 'b' && tmp->n > med))
			i++;
		tmp = tmp->next;
	}
	return (i);
}

void			make_order_right(t_stack **a, char s, int size, int count_rot)
{
	int stacklen;

	stacklen = count_stacklen(*a);
	if (size != stacklen && stacklen != count_rot)
		while (count_rot != 0)
		{
			count_rot--;
			if (s == 'a')
				make_oper(a, NULL, s, "rev_rotate");
			else
				make_oper(NULL, a, s, "rev_rotate");
		}
}

int				make_push_or_rotate(t_stack **a, t_stack **b, char s, int opt)
{
	if (opt == 1)
		make_oper(a, b, s, "push");
	else
		make_oper(a, b, s, "rotate");
	return (1);
}

int				separation(t_stack **a, t_stack **b, char s, int size)
{
	long long int	med;
	t_stack			*tmp;
	int				ret;
	int				count_rot;
	int				count_push;

	count_rot = 0;
	med = (s == 'a') ? count_median(*a, size) : count_median(*b, size);
	count_push = count_to_push((s == 'a') ? *a : *b, s, med);
	ret = count_push;
	while (count_push > 0)
	{
		tmp = (s == 'a') ? *a : *b;
		if ((s == 'a' && (tmp->n <= med)) || (s == 'b' && (tmp->n > med)))
			count_push -= make_push_or_rotate(a, b, s, 1);
		else
			count_rot += make_push_or_rotate(a, b, s, 0);
	}
	make_order_right((s == 'a') ? a : b, s, size, count_rot);
	return (ret);
}

void			quicksort(t_stack **a, t_stack **b, int size, char s)
{
	int		count_push;

	if (size == 1 && s == 'b')
		make_oper(a, b, s, "push");
	if (size == 2)
		sort_two(a, b, s);
	if (size == 3)
		sort_three(a, b, s);
	if (size >= 1 && size <= 3)
		return ;
	count_push = separation(a, b, s, size);
	if (s == 'a')
	{
		quicksort(a, b, size - count_push, 'a');
		quicksort(a, b, count_push, 'b');
	}
	if (s == 'b')
	{
		quicksort(a, b, count_push, 'a');
		quicksort(a, b, size - count_push, 'b');
	}
}
