/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 00:01:02 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/29 19:32:43 by gwyman-m         ###   ########.fr       */
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

	tmp = *a;
	prev = tmp->n;
	while (tmp)
	{
		if (prev <= tmp->n)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int			check(t_stack **a, char **oper)
{
	int		i;
	t_stack **b;

	b = NULL;
	i = -1;
	if (oper == NULL && is_sorted(a) == 1)
		return (1);
	else if (oper == NULL)
		return (0);
	while (oper[++i])
	{
		if (oper[i][0] == 's')
			apply_s(a, b, oper[i]);
		else if (oper[i][0] == 'p')
			apply_p(a, b, oper[i]);
		else if (oper[i][0] == 'r')
			apply_r(a, b, oper[i]);
	}
	if (is_sorted(a))
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_stack *a;
	char	**oper;

	if (argc <= 1)
		return (error());
	if (check_valid(argc, argv))
		return (error());
	a = create_stack(argc, argv);
	oper = NULL;
	if (create_oper(&oper) == 1)
		return (1);
	if (check(&a, oper) == 1)
		ft_printf("\x1b[32m[OK]\x1b[0m\n");
	else
		ft_printf("\x1b[31m[KO]\x1b[0m\n");
	return (0);
}
