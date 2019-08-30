#include "push_swap.h"

/*
**	param 's':
**	if 'a' - make operation for 'a' stack
**	if 'b' - make operation for 'b' stack
**	if 's' - place in oper string with all previous operations
*/

void	place_new_oper(char **list, char s, char *oper)
{
	int		len;
	char	*search;
	char	*toplace;

	len = ft_strlen(*list);
	if (ft_strequ(oper, "swap"))
	{
		search = (s == 'a') ? "sb\n" : "sa\n";
		toplace = (s == 'a') ? "sa\n" : "sb\n";
		if (len > 2 && ft_strnstr(*list + (len - 3), search, 3))
			(*list)[len - 2] = 's';
		else
			*list = ft_strrejoin(*list, toplace);
	}
	else if (ft_strequ(oper, "push"))
	{
		toplace = (s == 'a') ? "pb\n" : "pa\n";
		*list = ft_strrejoin(*list, toplace);
	}
	else if (ft_strequ(oper, "rotate"))
	{
		search = (s == 'a') ? "rb\n" : "ra\n";
		toplace = (s == 'a') ? "ra\n" : "rb\n";
		if (len > 2 && ft_strnstr(*list + (len - 3), search, 3) && (*list)[len - 4] != 'r')
			(*list)[len - 2] = 'r';
		else
			*list = ft_strrejoin(*list, toplace);
	}
	else if (ft_strequ(oper, "rev_rotate"))
	{
		search = (s == 'a') ? "rrb\n" : "rra\n";
		toplace = (s == 'a') ? "rra\n" : "rrb\n";
		if (len > 3 && ft_strnstr(*list + (len - 4), search, 4))
			(*list)[len - 2] = 'r';
		else
			*list = ft_strrejoin(*list, toplace);
	}
}

char	*make_oper(t_stack **a, t_stack **b, char s, char *oper)
{
	static char	*list = NULL;

	if (!list)
		list = ft_strnew(0);
	if (ft_strequ(oper, "get"))
		return (list);
	else
	{
		if (ft_strequ(oper, "swap"))
			swap(a, b, s);
		else if (ft_strequ(oper, "push"))
			push(a, b, s);
		else if (ft_strequ(oper, "rotate"))
			rotate(a, b, s);
		else if (ft_strequ(oper, "rev_rotate"))
			rev_rotate(a, b, s);
		place_new_oper(&list, s, oper);
	}
	return (NULL);
}
