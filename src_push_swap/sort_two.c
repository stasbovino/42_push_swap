/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:52:10 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/03 16:52:16 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		sort_two(t_stack **a, t_stack **b, char s)
{
	if (s == 'a')
	{
		if ((*a)->n > (*a)->next->n)
			make_oper(a, b, s, "swap");
	}
	else
	{
		if ((*b)->n < (*b)->next->n)
			make_oper(a, b, s, "swap");
		make_oper(a, b, s, "push");
		make_oper(a, b, s, "push");
	}
}
