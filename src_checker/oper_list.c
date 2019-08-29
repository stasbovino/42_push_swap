/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oper_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:10:31 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/29 19:34:06 by gwyman-m         ###   ########.fr       */
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

static void		fill_oper(char ***oper, t_lst *lst)
{
	int		len;
	t_lst	*begin;
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

static int		checker_error(t_lst **lst)
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

int				create_oper(char ***oper)
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
