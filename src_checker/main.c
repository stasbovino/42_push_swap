/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 00:01:02 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/29 18:53:41 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_lst	*create_lst(char *a)
{
	t_lst *lst;

	lst = (t_lst*)malloc(sizeof(t_lst));
	if (a)
		lst->s = ft_strdup(a);
	else
		lst->s = NULL;
	lst->next = NULL;
	return (lst);
}

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

int		error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

static int	checker_error(t_lst **lst)
{
	t_lst *tmp;

	while (*lst)
	{
		free((*lst)->s);
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	return (error());
}

void		create_valid_list(char ***valid)
{
	char **a;

	a = (char**)malloc(sizeof(char*) * 11);
	a[0] = ft_strdup("sa");
	a[1] = ft_strdup("sb");
	a[2] = ft_strdup("ss");
	a[3] = ft_strdup("pa");
	a[4] = ft_strdup("pb");
	a[5] = ft_strdup("ra");
	a[6] = ft_strdup("rb");
	a[7] = ft_strdup("rr");
	a[8] = ft_strdup("rra");
	a[9] = ft_strdup("rrb");
	a[10] = ft_strdup("rrr");
	*valid = a;
}

void		free_valid_list(char ***valid)
{
	int	i;

	i = -1;
	while (++i < 11)
	{
		free((*valid)[i]);
	}
	free(*valid);
}

static int	check_valid_oper(char *oper)
{
	int		i;
	char	**valid;

	valid = NULL;
	create_valid_list(&valid);
	i = -1;
	while (++i < 11)
	{
		if (ft_strcmp(oper, valid[i]) == 0)
		{
			free_valid_list(&valid);
			return (0);
		}
	}
	free_valid_list(&valid);
	return (-1);
}

static void	fill_oper(char ***oper, t_lst *lst)
{
	int		len;
	t_lst *begin;
	int		i;

	i = -1;
	len = 0;
	begin = lst;
	while (lst->next)
	{
		len++;
		lst = lst->next;
	}
	*oper = (char**)malloc(sizeof(char*) * (len + 1));
	(*oper)[len] = NULL;
	lst = begin;
	begin = begin->next;
	free(lst);
	while (++i < len)
	{
		(*oper)[i] = ft_strdup(begin->s);
		lst = begin;
		begin = begin->next;
		free(lst->s);
		free(lst);
	}
}

static int	create_oper(char ***oper)
{
	int		i;
	char	*buf;
	int		r;
	t_lst	*lst;
	t_lst	*begin;

	i = -1;
	buf = NULL;
	lst = create_lst(NULL);
	begin = lst;
	while ((r = get_next_line(0, &buf)))
	{
		if (r == -1)
			return (checker_error(&lst));
		lst->next = create_lst(buf);
		lst = lst->next;
		free(buf);
		buf = NULL;
		if (check_valid_oper(lst->s) == -1)
			return (checker_error(&lst));
	}
	fill_oper(oper, begin);
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
	if (oper == NULL && is_sorted(a) == 1)
		return (1);
	else if (oper == NULL)
		return (0);
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
				ch_rotate(a, b, 'a');
			else if (oper[i][1] == 'b' || (oper[i][1] == 'r' && oper[i][2] == '\0'))
				ch_rotate(a, b, 'b');
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
	if (create_oper(&oper) == 1)
		return (1);
	if (check(&a, oper) == 1)
		ft_printf("\x1b[32m[OK]\x1b[0m\n");
	else
		ft_printf("\x1b[31m[KO]\x1b[0m\n");
	return (0);
}
