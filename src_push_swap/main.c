/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 22:36:52 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/03 21:34:17 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int		main(int argc, char **argv)
{
	t_stack *a;
	char	*oper;

	if (argc <= 1)
		return (error());
	if (check_valid(argc, argv))
		return (error());
	a = create_stack(argc, argv);
	if (!a)
		return (error());
	sort(&a);
	oper = make_oper(NULL, NULL, 'a', "get");
	ft_printf("%s", oper);
	free(oper);
	free_stack(&a);
	return (0);
}
