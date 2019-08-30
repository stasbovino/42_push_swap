/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 00:01:02 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/30 18:09:59 by sts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

static int	is_sorted(t_stack **a)
{
	t_stack *tmp;
	int		prev;

	if (!(*a))
		return (0);
	tmp = *a;
	prev = tmp->n;
	while (tmp)
	{
		if (prev <= tmp->n)
		{
			prev = tmp->n;
			tmp = tmp->next;
		}
		else
			return (0);
	}
	return (1);
}

int			check(t_stack **a, t_stack **b, char **oper)
{
	int		i;

	i = -1;
	if (oper == NULL && is_sorted(a) == 1)
		return (1);
	else if (oper == NULL)
		return (0);
//	ft_printf("\nBEGIN\n");
//	print_stack(*a);
//	print_stack(*b);
	while (oper[++i])
	{
		if (oper[i][0] == 's')
			apply_s(a, b, oper[i]);
		else if (oper[i][0] == 'p')
			apply_p(a, b, oper[i]);
		else if (oper[i][0] == 'r')
			apply_r(a, b, oper[i]);
//		ft_printf("\nOPER IS %s\n", oper[i]);
//		print_stack(*a);
//		print_stack(*b);
	}
	if (is_sorted(a) && !(*b))
		return (1);
	return (0);
}

void	print_stack(t_stack *a)
{
	if (!a)
		ft_printf("stack is empty\n");
	while (a)
	{
		ft_printf("%d ", a->n);
		a = a->next;
	}
	ft_printf("\n");
}

int			main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	char	**oper;

	if (argc == 1)
		return (1);
	if (check_valid(argc, argv))
		return (error());
	oper = NULL;
	if (create_oper(&oper) == 1)
		return (1);
	a = create_stack(argc, argv);
	b = NULL;
	if (check(&a, &b, oper) == 1)
	{
		print_stack(a);
		print_stack(b);
		ft_printf("\x1b[32m[OK]\x1b[0m\n");
	}
	else
	{
		print_stack(a);
		print_stack(b);
		ft_printf("\x1b[31m[KO]\x1b[0m\n");
	}
	clear_oper(&oper);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
