/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:10:31 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/03 16:50:40 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int		checker_error(t_lst **lst, char **s)
{
	t_lst *tmp;

	free(*s);
	while (*lst)
	{
		free((*lst)->s);
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	get_next_line(0, NULL, 1);
	return (1);
}

void			clear_oper(char ***oper)
{
	int i;

	i = -1;
	while ((*oper)[++i])
	{
		free((*oper)[i]);
	}
	free(*oper);
}

int				read_to_lst(t_lst **begin, t_lst **lst)
{
	char	*buf;
	int		r;

	r = 0;
	buf = NULL;
	while ((r = get_next_line(0, &buf, 0)))
	{
		if (r == -1)
			return (checker_error(begin, &buf));
		(*lst)->next = create_lst(buf);
		(*lst) = (*lst)->next;
		free(buf);
		buf = NULL;
		if (check_valid_oper((*lst)->s) == -1)
			return (checker_error(begin, &buf));
	}
	free(buf);
	return (0);
}

int				create_oper(char ***oper)
{
	t_lst	*lst;
	t_lst	*begin;

	lst = create_lst(NULL);
	begin = lst;
	if (read_to_lst(&begin, &lst))
		return (error());
	fill_oper(oper, begin);
	return (0);
}
