/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 21:56:22 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/29 21:56:49 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst			*create_lst(char *a)
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
