/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:36:52 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/29 00:05:28 by gwyman-m         ###   ########.fr       */
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

void	print_stack(t_stack *a)
{
	while (a)
	{
		ft_printf("%d ", a->n);
		a = a->next;
	}
	ft_printf("\n");
}

int		error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack *a;

	if (argc <= 1)
		return (error());
	if (check_valid(argc, argv))
		return (error());
	a = create_stack(argc, argv);
//	print_stack(a);
	sort(&a);
//	print_stack(a);
	return (0);
}
