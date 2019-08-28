#include "push_swap.h"

int		check_isnum(char *num)
{
	int i;

	i = (num[0] == '-') ? 0 : -1;
	while (num[++i])
		if (!(num[i] >= '0' && num[i] <= '9'))
			return (1);
	return (0);
}

int		check_overflow(char *num)
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

int		check_duplicates(int argc, char **argv)
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

void	print_stack(t_stack *a)
{
	while (a)
	{
		ft_printf("%d ", a->n);
		a = a->next;
	}
	ft_printf("\n");
}

int		error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	int		i;

	if (argc <= 1)
		return (error());
	i = 0;
	while (++i < argc)
	{
		if (check_isnum(argv[i]))
			return (error());
		if (check_overflow(argv[i]))
			return (error());
	}
	if (check_duplicates(argc, argv))
		return (error());
	a = create_stack(argc, argv);
	print_stack(a);
	sort(a);
	print_stack(a);
	return (0);
}
