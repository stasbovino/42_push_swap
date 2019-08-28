/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:38:01 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/08/28 22:41:07 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_isnum(char *num)
{
	int i;

	i = (num[0] == '-') ? 0 : -1;
	while (num[++i])
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (1);
	return (0);
}

static int	check_overflow(char *num)
{
	int		i;
	char	*overf;
	int		lenoverf;

	overf = (num[0] == '-') ? "-2147483648" : "2147483647";
	lenoverf = (num[0] == '-') ? 11 : 10;
	if (ft_strlen(num) > lenoverf)
		return (1);
	else if (ft_strlen(num) < lenoverf)
		return (0);
	i = (num[0] == '-') ? 0 : -1;
	while (num[++i])
	{
		if (num[i] > overf[i])
			return (1);
	}
	return (0);
}

static int	check_duplicates(int argc, char **argv)
{
	int i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = i;
		while (++j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
		}
	}
	return (0);
}

int			check_vald(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
	{
		if (check_isnum(argv[i]))
			return (1);
		if (check_overflow(argv[i]))
			return (1);
	}
	if (check_duplicates(argc, argv))
		return (1);
	return (0);
}
