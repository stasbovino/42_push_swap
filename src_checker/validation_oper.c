/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_oper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:05:59 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/29 19:08:02 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	create_valid_list(char ***valid)
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

static void	free_valid_list(char ***valid)
{
	int	i;

	i = -1;
	while (++i < 11)
	{
		free((*valid)[i]);
	}
	free(*valid);
}

int			check_valid_oper(char *oper)
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
