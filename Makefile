# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/28 23:35:25 by gwyman-m          #+#    #+#              #
#    Updated: 2019/08/30 21:14:30 by sts              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

CHECKER = checker

#FLAGS = -g -Wall -Wextra -Werror -I. -I libft/ -L libft/ -lft
FLAGS = -g -Wall -Wextra -Werror -I. -I libft/
LIB = -L libft/ -lft

PUSH_SWAP_SRC_DIR= src_push_swap/

CHECKER_SRC_DIR= src_checker/

CPUSH_SWAP= main.c oper_push_swap.c oper_rotates.c validation.c \
			quicksort.c sort.c sort_three.c sort_two.c operations.c

CCHECKER= main.c oper_push_swap.c oper_rotates.c validation_stack.c apply_oper.c create_stack.c \
		  create_oper.c validation_oper.c create_lst.c

PUSH_SWAP_SRC = $(addprefix $(PUSH_SWAP_SRC_DIR),$(CPUSH_SWAP))

CHECKER_SRC = $(addprefix $(CHECKER_SRC_DIR),$(CCHECKER))

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(PUSH_SWAP_SRC)
	make -C libft/
	gcc $(FLAGS) $(PUSH_SWAP_SRC) -o $(PUSH_SWAP) $(LIB)

$(CHECKER): $(CHECKER_SRC)
	make -C libft/
	gcc $(FLAGS) $(CHECKER_SRC) -o $(CHECKER) $(LIB)

clean:
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm -fv $(PUSH_SWAP) $(CHECKER)

re: fclean all
