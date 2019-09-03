/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_rotates.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:36:27 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/03 16:52:02 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_last(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

static t_stack	*find_prev(t_stack *a)
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

int				rotate(t_stack **a, t_stack **b, char s)
{
	t_stack	*last;
	t_stack	*tmp;

	if (s == 'a' && *a && (*a)->next)
	{
		last = find_last(*a);
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		last->next = tmp;
	}
	if (s == 'b' && *b && (*b)->next)
	{
		last = find_last(*b);
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		last->next = tmp;
	}
	return (1);
}

int				rev_rotate(t_stack **a, t_stack **b, char s)
{
	t_stack	*prev;
	t_stack	*tmp;

	if (s == 'a' && *a && (*a)->next)
	{
		prev = find_prev(*a);
		tmp = prev->next;
		tmp->next = *a;
		*a = tmp;
		prev->next = NULL;
	}
	if (s == 'b' && *b && (*b)->next)
	{
		prev = find_prev(*b);
		tmp = prev->next;
		tmp->next = *b;
		*b = tmp;
		prev->next = NULL;
	}
	return (1);
}
