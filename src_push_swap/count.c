/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:05:36 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/03 17:05:40 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				count_stacklen(t_stack *a)
{
	int		i;
	t_stack	*tmp;

	tmp = a;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

long long int	count_median(t_stack *a, int size)
{
	int		i;
	int		sum;
	t_stack	*tmp;
	int		ret;

	sum = 0;
	i = -1;
	tmp = a;
	while (++i < size)
	{
		sum += tmp->n;
		tmp = tmp->next;
	}
	ret = sum / size;
	return (ret);
}
