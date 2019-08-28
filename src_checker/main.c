/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 00:01:02 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/29 00:48:42 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	checker_error(char **oper, int size)
{
	int i;

	i = -1;
	while (++i <= size)
		free(oper[i]);
	free(oper);
	return (error());
}

void		create_valid_list()
{
}

static int	check_valid_oper(char *oper)
{
	int i;
	char **valid;

	create_valid_list(valid);
	i = -1;
	while (++i < 11)
	{
		if (ft_strcmp(oper, valid[i]) == 0)
			return (0);
	}
	free_valid_list(valid);
	return (1);
}

static int	create_oper(char **oper)
{
	int		i;
	char	*buf;
	int		r;

	i = -1;
	oper = (char**)malloc(sizeof(char*));
	while ((r = get_next_line(1, &buf)) == 1)
	{
		oper[++i] = ft_strdup(buf);
		free(buf);
		if (check_valid_oper(oper[i]) == 1)
			return (checker_error(oper, i));
	}
	oper[i] = NULL;
	return (0);
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
	while (oper[++i])
	{
		if (oper[i][0] == 's')
		{
			if (oper[i][1] == 'a' || oper[i][1] == 's')
				ch_swap(a, b, 'a');
			else if (oper[i][1] == 'b' || oper[i][1] == 's')
				ch_swap(a, b, 'b');
		}
		else if (oper[i][0] == 'p')
		{
			if (oper[i][1] == 'a')
				ch_push(a, b, 'b');
			else if (oper[i][1] == 'b')
				ch_push(a, b, 'a');
		}
		else if (oper[i][0] == 'r')
		{
			if (oper[i][1] == 'a' || (oper[i][1] == 'r' && oper[i][2] == '\0'))
				ch_rotate(a, b, 'b');
			else if (oper[i][1] == 'b' || (oper[i][1] == 'r' && oper[i][2] == '\0'))
				ch_rotate(a, b, 'a');
			else if ((oper[i][1] == 'r' && oper[i][2] == 'a') ||
					(oper[i][1] == 'r' && oper[i][2] == 'r'))
				ch_rev_rotate(a, b, 'a');
			else if ((oper[i][1] == 'r' && oper[i][2] == 'a') ||
					(oper[i][1] == 'r' && oper[i][2] == 'r'))
				ch_rev_rotate(a, b, 'b');
		}
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
	if (create_oper(oper) == 1)
		return (1);
	if (check(&a, oper) == 1)
		ft_printf("[OK]");
	else
		ft_printf("[KO]");
	return (0);
}
