/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:10:31 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/29 22:24:27 by gwyman-m         ###   ########.fr       */
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
	return (error());
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
	buf = ft_strnew(4);
	while ((r = read(0, buf, 4)))
	{
		if (r == -1)
			return (checker_error(begin, &buf));
		if (r == 3)
			buf[2] = '\0';
		else if (r == 4)
			buf[3] = '\0';
		else
			return (checker_error(begin, &buf));
		(*lst)->next = create_lst(buf);
		(*lst) = (*lst)->next;
		free(buf);
		buf = ft_strnew(4);
		if (check_valid_oper((*lst)->s) == -1)
			return (checker_error(begin, &buf));
	}
	free(buf);
	return (0);
}

int				create_oper(char ***oper)
{
	int		i;
	t_lst	*lst;
	t_lst	*begin;

	i = -1;
	lst = create_lst(NULL);
	begin = lst;
	if (read_to_lst(&begin, &lst))
		return (error());
	fill_oper(oper, begin);
	return (0);
}
