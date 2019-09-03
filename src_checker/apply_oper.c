/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_oper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:31:33 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/03 17:47:23 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		apply_s(t_stack **a, t_stack **b, char *oper)
{
	if (oper[1] == 'a' || oper[1] == 's')
		ch_swap(a, b, 'a');
	if (oper[1] == 'b' || oper[1] == 's')
		ch_swap(a, b, 'b');
}

void		apply_r(t_stack **a, t_stack **b, char *oper)
{
	if (oper[1] == 'a' || (oper[1] == 'r' && oper[2] == '\0'))
		ch_rotate(a, b, 'a');
	if (oper[1] == 'b' || (oper[1] == 'r' && oper[2] == '\0'))
		ch_rotate(a, b, 'b');
	if ((oper[1] == 'r' && oper[2] == 'a') ||
			(oper[1] == 'r' && oper[2] == 'r'))
		ch_rev_rotate(a, b, 'a');
	if ((oper[1] == 'r' && oper[2] == 'b') ||
			(oper[1] == 'r' && oper[2] == 'r'))
		ch_rev_rotate(a, b, 'b');
}

void		apply_p(t_stack **a, t_stack **b, char *oper)
{
	if (oper[1] == 'a')
		ch_push(a, b, 'b');
	else if (oper[1] == 'b')
		ch_push(a, b, 'a');
}
