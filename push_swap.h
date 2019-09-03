/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 17:09:25 by gwyman-m          #+#    #+#             */
/*   Updated: 2019/09/03 17:49:01 by gwyman-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdlib.h>

typedef struct		s_stack
{
	int				n;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_lst
{
	char			*s;
	struct s_lst	*next;
}					t_lst;

t_stack				*create_stack(int argc, char **argv);
void				free_stack(t_stack **a);
int					count_stacklen(t_stack *a);
long long int		count_median(t_stack *a, int size);

char				*make_oper(t_stack **a, t_stack **b, char s, char *oper);
void				print_stack(t_stack *a);
int					error(void);

void				sort(t_stack **a);
void				quicksort(t_stack **a, t_stack **b, int size, char s);
void				sort_three(t_stack **a, t_stack **b, char s);
void				sort_two(t_stack **a, t_stack **b, char s);
void				sort_three_b(t_stack **a, t_stack **b, char s);
void				sort_three_b_smart(t_stack **a, t_stack **b, char s);

int					push(t_stack **a, t_stack **b, char s);
void				swap(t_stack **a, t_stack **b, char s);
int					rotate(t_stack **a, t_stack **b, char s);
int					rev_rotate(t_stack **a, t_stack **b, char s);

int					check_valid(int argc, char **argv);

int					ch_push(t_stack **a, t_stack **b, char s);
void				ch_swap(t_stack **a, t_stack **b, char s);
int					ch_rotate(t_stack **a, t_stack **b, char s);
int					ch_rev_rotate(t_stack **a, t_stack **b, char s);

int					check_valid_oper(char *oper);
int					create_oper(char ***oper);
void				clear_oper(char ***oper);
t_lst				*create_lst(char *a);

void				apply_s(t_stack **a, t_stack **b, char *oper);
void				apply_r(t_stack **a, t_stack **b, char *oper);
void				apply_p(t_stack **a, t_stack **b, char *oper);

#endif
