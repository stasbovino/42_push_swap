/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:20:10 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/28 19:40:16 by gwyman-m         ###   ########.fr       */
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

int			push(t_stack *a, t_stack *b, char s)
{
	t_stack	*tmp;

	if (s == 'b')
	{
		tmp = a->next;
		a->next = b;
		b = a;
		a = tmp;
		ft_printf("pb\n");
	}
	else
	{
		tmp = b->next;
		b->next = a;
		a = b;
		b = tmp;
		ft_printf("pa\n");
	}
	return (1);
}

void		swap(t_stack *a, t_stack *b, char s1, char s2)
{
	int		tmp;

	if (s1 == 'a')
	{
		tmp = a->next->n;
		a->next->n = a->n;
		a->n = tmp;
	}
	if (s2 == 'b')
	{
		tmp = a->next->n;
		a->next->n = a->n;
		a->n = tmp;
	}
	if (s1 == 'a' && s2 == 'b')
		ft_printf("ss\n");
	else if (s1 == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}

t_stack		*find_last(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

t_stack		*find_prev(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	if (tmp->next)
	{
		while (tmp->next)
		{
			if (tmp->next->next)
				tmp = tmp->next;
			else
				return (tmp);
		}
	}
	return (tmp);
}

int			rotate(t_stack **a, t_stack **b, char s)
{
	t_stack	*last;
	t_stack	*tmp;

	if (s == 'a')
	{
		last = find_last(*a);
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		last->next = tmp;
	}
	if (s == 'b')
	{
		last = find_last(*b);
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		last->next = tmp;
	}
	if (s == 'a')
		ft_printf("ra\n");
	else
		ft_printf("rb\n");
	return (1);
}

int			rev_rotate(t_stack **a, t_stack **b, char s)
{
	t_stack	*prev;
	t_stack	*tmp;

	if (s == 'a')
	{
		prev = find_prev(*a);
		tmp = prev->next;
		tmp->next = *a;
		*a = tmp;
		prev->next = NULL;
	}
	if (s == 'b')
	{
		prev = find_prev(*b);
		tmp = prev->next;
		tmp->next = *b;
		*b = tmp;
		prev->next = NULL;
	}
	if (s == 'a')
		ft_printf("rra\n");
	else
		ft_printf("rrb\n");
	return (1);
}

int			separation(t_stack *a, t_stack *b, char s, int size)
{
	int		median;
	t_stack	*tmp;
	int		i;
	int		count_rot;
	int		count_push;

	i = -1;
	count_push = 0;
	count_rot = 0;
	median = (s == 'a') ? count_median(a, size) : count_median(b, size);
	tmp = (s == 'a') ? a : b;
	while (++i < size)
	{
		if (tmp->n < median)
		{
			count_push += push(a, b, s);
		}
		else
		{
			count_rot += rotate(&a, &b, s);
		}
	}
	while (count_rot != 0)
		count_rot -= rev_rotate(&a, &b, s);
	return (count_push);
}

void		sort_two(t_stack *a, t_stack *b, char s)
{
	if (s == 'a')
	{
		if (a->n > a->next->n)
			swap(a, b, s, 0);
	}
	else
	{
		if (b->n < b->next->n)
			swap(NULL, b, 0, s);
		push(a, b, 'a');
		push(a, b, 'a');
	}
}

void		sort_three(t_stack *a, t_stack *b, char s)
{
	if (s == 'a')
	{
		while (!((a->n < a->next->n) && (a->next->n < a->next->next->n)))
		{
			if (a->n > a->next->n)
				swap(a, b, s, 0);
			if (a->next->n > a->next->next->n)
			{
				rotate(&a, &b, s);
				swap(a, b, s, 0);
				rev_rotate(&a, &b, s);
			}
		}
	}
	else
	{
		while (!((b->n < b->next->n) && (b->next->n < b->next->next->n)))
		{
			if (b->n < b->next->n)
				swap(a, b, 0, s);
			if (b->next->n < b->next->next->n)
			{
				rotate(&a, &b, s);
				swap(a, b, 0, s);
				rev_rotate(&a, &b, s);
			}
		}
	}
}

void		quicksort(t_stack *a, t_stack *b, int size, char s)
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

void		sort(t_stack *a)
{
	t_stack *b;
	int		size;

	b = NULL;
	size = count_stacklen(a);
	if (size == 1)
		return ;
	quicksort(a, b, size, 'a');
}
