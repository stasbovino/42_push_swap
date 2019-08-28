/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:36:34 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/28 23:04:45 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				push(t_stack **a, t_stack **b, char s)
{
	t_stack	*tmp;

	if (s == 'a')
	{
		tmp = (*a)->next;
		(*a)->next = *b;
		*b = *a;
		*a = tmp;
		ft_printf("pb\n");
	}
	else
	{
		tmp = (*b)->next;
		(*b)->next = *a;
		*a = *b;
		*b = tmp;
		ft_printf("pa\n");
	}
	return (1);
}

void			swap(t_stack **a, t_stack **b, char s)
{
	int		tmp;

	if (s == 'a')
	{
		tmp = (*a)->next->n;
		(*a)->next->n = (*a)->n;
		(*a)->n = tmp;
	}
	if (s == 'b')
	{
		tmp = (*b)->next->n;
		(*b)->next->n = (*b)->n;
		(*b)->n = tmp;
	}
	else if (s == 'a')
		ft_printf("sa\n");
	else
		ft_printf("sb\n");
}
