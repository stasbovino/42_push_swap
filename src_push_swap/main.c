/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:36:52 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/31 20:24:04 by sts              ###   ########.fr       */
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

void	free_stack(t_stack **a)
{
	t_stack *tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

void	print_stack(t_stack *a)
{
	if (!a)
		ft_printf("stack is empty");
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
	char	*oper;

	if (argc <= 1)
		return (error());
	if (check_valid(argc, argv))
		return (error());
	a = create_stack(argc, argv);
//	print_stack(a);
	sort(&a);
	oper = make_oper(NULL, NULL, 'a', "get");
	ft_printf("%s", oper);
	free(oper);
//	ft_printf("\x1b[31m%s\x1b[0m", oper);
//	print_stack(a);
	free_stack(&a);
	return (0);
}
