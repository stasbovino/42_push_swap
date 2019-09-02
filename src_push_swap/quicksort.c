/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 16:20:10 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/02 16:17:13 by sts              ###   ########.fr       */
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

int             count_to_push(t_stack *a, char s, long long int med)
{
	t_stack *tmp;
	int     i;

	tmp = a;
	i = 0;
	while (tmp)
    {
        if ((s == 'a' && tmp->n <= med) || (s == 'b' && tmp->n > med))
            i++;
        tmp = tmp->next;
    }
    return (i);
}

int				separation(t_stack **a, t_stack **b, char s, int size)
{
	long long int	median;
	t_stack			*tmp;
	int				ret;
	int				count_rot;
	int				count_push;

	count_rot = 0;
	median = (s == 'a') ? count_median(*a, size) : count_median(*b, size);
	count_push = count_to_push((s == 'a') ? *a : *b, s, median);
/*	print_stack(*a);
	ft_printf("\n");
	print_stack(*b);
	ft_printf("stack %c med %d size %d push %d\n\n", s, median, size, count_push);
*/	ret = count_push;
	tmp = (s == 'a') ? *a : *b;
	while (count_push > 0)
	{
		if ((s == 'a' && (tmp->n <= median)) || (s == 'b' && (tmp->n > median)))
		{
			count_push--;
			make_oper(a, b, s, "push");
		}
/*		else if (tmp->next && ((s == 'a' && (tmp->next->n <= median))
				|| (s == 'b' && (tmp->next->n > median))))
		{
			count_push--;
			make_oper(a, b, s, "swap");
			make_oper(a, b, s, "push");
		}
*/		else
		{
			count_rot++;
			make_oper(a, b, s, "rotate");
		}
		tmp = (s == 'a') ? *a : *b;
	}
	if (((s == 'a') ? count_stacklen(*a) : count_stacklen(*b)) != count_rot)
		while (count_rot != 0)
		{
			count_rot--;	
			make_oper(a, b, s, "rev_rotate");
		}
	return (ret);
}

void			quicksort(t_stack **a, t_stack **b, int size, char s)
{
	int		count_push;

	if (size == 1 && s == 'b')
		make_oper(a, b, s, "push");
	if (size == 2)
		sort_two(a, b, s);
	if (size == 3)
		sort_three(a, b, s);
	if (size > 1 && size <= 3)
		return ;
	count_push = separation(a, b, s, size);
	if (s == 'a')
	{
		quicksort(a, b, size - count_push, 'a');
		quicksort(a, b, count_push, 'b');
	}
	if (s == 'b')
	{
		quicksort(a, b, count_push, 'a');
		quicksort(a, b, size - count_push, 'b');
	}
}
