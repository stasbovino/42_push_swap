/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:36:49 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/03 17:44:53 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_b_smart_continue(t_stack **a, t_stack **b, char s)
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

void		sort_three_b_smart(t_stack **a, t_stack **b, char s)
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
		sort_three_b_smart_continue(a, b, s);
}

static void	sort_three_b_countinue(t_stack **a, t_stack **b, char s)
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

void		sort_three_b(t_stack **a, t_stack **b, char s)
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
		sort_three_b_countinue(a, b, s);
}
