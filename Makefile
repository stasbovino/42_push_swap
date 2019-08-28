# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/28 23:35:25 by gwyman-m          #+#    #+#              #
#    Updated: 2019/08/29 00:41:55 by gwyman-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

CHECKER = checker

FLAGS = -Wall -Wextra -Werror -I. -I libft/ -L libft/ -lft

PUSH_SWAP_SRC_DIR= src_push_swap/

CHECKER_SRC_DIR= src_checker/

CPUSH_SWAP= main.c oper_push_swap.c oper_rotates.c sort.c sort_for_onetwothree.c validation.c

CCHECKER= main.c oper_push_swap.c oper_rotates.c 

PUSH_SWAP_SRC = $(addprefix $(PUSH_SWAP_SRC_DIR),$(CPUSH_SWAP))

CHECKER_SRC = $(addprefix $(CHECKER_SRC_DIR),$(CCHECKER))

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): $(PUSH_SWAP_SRC)
	make -C libft/
	gcc $(FLAGS) $(PUSH_SWAP_SRC) -o $(PUSH_SWAP)

$(CHECKER): $(PUSH_SWAP_SRC) $(CHECKER)
	make -C libft/
	gcc $(FLAGS) $(CHECKER_SRC) -o $(CHECKER)

clean:
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm -fv $(PUSH_SWAP)

re: fclean all