/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:36:34 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/29 20:20:10 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ch_push(t_stack **a, t_stack **b, char s)
{
	t_stack	*tmp;

	if (s == 'a' && *a)
	{
		tmp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = tmp;
	}
	else if (s == 'b' && *b)
	{
		tmp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = tmp;
	}
	return (1);
}

void			ch_swap(t_stack **a, t_stack **b, char s)
{
	int		tmp;

	if (s == 'a' && *a && (*a)->next)
	{
		tmp = (*a)->next->n;
		(*a)->next->n = (*a)->n;
		(*a)->n = tmp;
	}
	if (s == 'b' && *b && (*b)->next)
	{
		tmp = (*b)->next->n;
		(*b)->next->n = (*b)->n;
		(*b)->n = tmp;
	}
}
