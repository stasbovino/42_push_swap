/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:36:47 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/03 17:37:55 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
