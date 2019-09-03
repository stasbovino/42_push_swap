/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:38:01 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/04 01:04:52 by sts              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_isnum(char *num)
{
	int i;

	i = (num[0] == '-') ? 0 : -1;
	if (!num[i + 1])
		return (1);
	while (num[++i])
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (1);
	return (0);
}

static int	check_overflow(char *num)
{
	int		i;
	char	*overf;
	int		j;
	int		numlen;

	overf = (num[0] == '-') ? "-2147483648" : "2147483647";
	i = (num[0] == '-') ? 0 : -1;
	j = i + 1;
	while (num[++i])
		if (num[i] != '0')
			break;
	numlen = ft_strlen(num) - i;
	if (numlen > 10)
		return (1);
	else if (numlen < 10)
		return (0);
	while (num[i])
	{
		if (num[i] > overf[j])
			return (1);
		i++;
		j++;
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

int			check_valid(int argc, char **argv)
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
