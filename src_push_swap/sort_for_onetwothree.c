/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_onetwothree.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:36:47 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/28 23:32:02 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	sort_three_b(t_stack **a, t_stack **b, char s)
{
	if ((*b)->n < (*b)->next->n)
	{
		if ((*b)->n < (*b)->next->next->n)
			rotate(a, b, s);
		if ((*b)->n < (*b)->next->n)
			swap(a, b, s);
	}
	else if ((*b)->n > (*b)->next->n)
	{
		if ((*b)->next->n < (*b)->next->next->n)
		{
			rev_rotate(a, b, s);
			if ((*b)->n < (*b)->next->n)
				swap(a, b, s);
		}
	}
	push(a, b, s);
	push(a, b, s);
	push(a, b, s);
}

static void	sort_three_a(t_stack **a, t_stack **b, char s)
{
	if ((*a)->n > (*a)->next->n)
	{
		if ((*a)->n > (*a)->next->next->n)
			rotate(a, b, s);
		if ((*a)->n > (*a)->next->n)
			swap(a, b, s);
	}
	else if ((*a)->n < (*a)->next->n)
	{
		if ((*a)->next->n > (*a)->next->next->n)
		{
			rev_rotate(a, b, s);
			if ((*a)->n > (*a)->next->n)
				swap(a, b, s);
		}
	}
}

void		sort_three(t_stack **a, t_stack **b, char s)
{
	if (s == 'a')
		sort_three_a(a, b, s);
	else
		sort_three_b(a, b, s);
}