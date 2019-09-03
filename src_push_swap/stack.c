/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:28:36 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/03 21:55:46 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			free_stack(t_stack **a)
{
	t_stack *tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

static t_stack	*create_struct(void)
{
	t_stack *a;

	a = (t_stack*)malloc(sizeof(t_stack));
	a->n = 0;
	a->next = NULL;
	return (a);
}

static int		free_and_return(int **arr, int ret)
{
	free(*arr);
	return (ret);
}

static int		check_duplicates(t_stack *a)
{
	int *arr;
	int stacklen;
	int	i;
	int	j;

	stacklen = count_stacklen(a);
	arr = (int*)malloc(sizeof(int) * stacklen);
	i = -1;
	while (++i < stacklen)
	{
		arr[i] = a->n;
		a = a->next;
	}
	i = -1;
	while (++i < stacklen)
	{
		j = i;
		while (++j < stacklen)
			if (arr[j] == arr[i])
				return (free_and_return(&arr, 1));
	}
	return (free_and_return(&arr, 0));
}

t_stack			*create_stack(int argc, char **argv)
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
	if (check_duplicates(begin))
	{
		free_stack(&begin);
		return (NULL);
	}
	return (begin);
}
