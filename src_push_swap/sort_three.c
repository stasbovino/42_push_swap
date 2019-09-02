/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:36:47 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/01 16:55:55 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_b_smart(t_stack **a, t_stack **b, char s)
{
	if ((*b)->n < (*b)->next->n)
	{
		if ((*b)->next->n < (*b)->next->next->n)
		{
			make_oper(a, b, s, "push");
			make_oper(a, b, s, "swap");
			make_oper(a, b, s, "push");
			make_oper(a, b, 'a', "swap");
			make_oper(a, b, s, "push");
			make_oper(a, b, 'a', "swap");
		}
		else
		{
			make_oper(a, b, s, "swap");
			make_oper(a, b, s, "push");
			if ((*b)->n < (*b)->next->n)
				make_oper(a, b, s, "swap");
			make_oper(a, b, s, "push");
			make_oper(a, b, s, "push");
		}
	}
	else if ((*b)->n > (*b)->next->n)
	{
		if ((*b)->n > (*b)->next->next->n)
		{
			make_oper(a, b, s, "push");
			if ((*b)->n < (*b)->next->n)
				make_oper(a, b, s, "swap");
			make_oper(a, b, s, "push");
			make_oper(a, b, s, "push");
		}
		else
		{
			make_oper(a, b, s, "push");
			make_oper(a, b, s, "swap");
			make_oper(a, b, s, "push");
			make_oper(a, b, 'a', "swap");
			make_oper(a, b, s, "push");
		}
	}
}

static void	sort_three_b(t_stack **a, t_stack **b, char s)
{
	if ((*b)->n < (*b)->next->n)
	{
		if ((*b)->n < (*b)->next->next->n)
		{
			if ((*b)->next->n > (*b)->next->next->n)
				make_oper(a, b, s, "rotate");
			else
				make_oper(a, b, s, "rev_rotate");
			make_oper(a, b, s, "push");
			if ((*b)->n < (*b)->next->n)
				make_oper(a, b, s, "swap");
			make_oper(a, b, s, "push");
			make_oper(a, b, s, "push");
		}
		else
		{
			make_oper(a, b, s, "rotate");
			make_oper(a, b, s, "push");
			make_oper(a, b, s, "push");
			make_oper(a, b, s, "push");
			make_oper(a, b, 'a', "swap");
		}
	}
	else if ((*b)->n > (*b)->next->n)
	{
		if ((*b)->n > (*b)->next->next->n)
		{
			make_oper(a, b, s, "push");
			if ((*b)->n < (*b)->next->n)
				make_oper(a, b, s, "swap");
			make_oper(a, b, s, "push");
			make_oper(a, b, s, "push");
		}
		else
		{
			make_oper(a, b, s, "rev_rotate");
			make_oper(a, b, s, "push");
			make_oper(a, b, s, "push");
			make_oper(a, b, s, "push");
		}
	}
}

static void	sort_three_a_smart(t_stack **a, t_stack **b, char s)
{
	if ((*a)->n > (*a)->next->n)
	{
		if ((*a)->n > (*a)->next->next->n)
		{
			make_oper(a, b, s, "swap");
			make_oper(a, b, s, "rotate");
			make_oper(a, b, s, "swap");
			make_oper(a, b, s, "rev_rotate");
		}
		if ((*a)->n > (*a)->next->n)
			make_oper(a, b, s, "swap");
	}
	else if ((*a)->n < (*a)->next->n)
	{
		if ((*a)->next->n > (*a)->next->next->n)
		{
			make_oper(a, b, s, "rotate");
			make_oper(a, b, s, "swap");
			make_oper(a, b, s, "rev_rotate");
			if ((*a)->n > (*a)->next->n)
				make_oper(a, b, s, "swap");
		}
	}
}

static void	sort_three_a(t_stack **a, t_stack **b, char s)
{
	if ((*a)->n > (*a)->next->n)
	{
		if ((*a)->n > (*a)->next->next->n)
			make_oper(a, b, s, "rotate");
		if ((*a)->n > (*a)->next->n)
			make_oper(a, b, s, "swap");
	}
	else if ((*a)->n < (*a)->next->n)
	{
		if ((*a)->next->n > (*a)->next->next->n)
		{
			make_oper(a, b, s, "rev_rotate");
			if ((*a)->n > (*a)->next->n)
				make_oper(a, b, s, "swap");
		}
	}
}

void		sort_three(t_stack **a, t_stack **b, char s)
{
	if (s == 'a')
	{
		if ((*a)->next->next->next)
			sort_three_a_smart(a, b, s);
		else
			sort_three_a(a, b, s);
	}
	else
	{
		if ((*b)->next->next->next)
			sort_three_b_smart(a, b, s);
		else
			sort_three_b(a, b, s);
	}
}
