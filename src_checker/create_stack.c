/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:14:12 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/29 19:14:38 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_struct(void)
{
	t_stack *a;

	a = (t_stack*)malloc(sizeof(t_stack));
	a->n = 0;
	a->next = NULL;
	return (a);
}

t_stack	*create_stack(int argc, char **argv)
{
	t_stack *prev;
	t_stack	*new;
	int		i;
	t_stack	*begin;

	new = create_struct();
	begin = new;
	new->n = ft_atoi(argv[1]);
	prev = new;
	i = 1;
	while (++i < argc)
	{
		new = create_struct();
		new->n = ft_atoi(argv[i]);
		prev->next = new;
		prev = new;
	}
	return (begin);
}
