# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/28 23:35:25 by gwyman-m          #+#    #+#              #
#    Updated: 2019/11/10 00:21:44 by sts              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

CHECKER = checker

FLAGS = -g -Wall -Wextra -Werror -I. -I libft/

LIB = -L libft/ -lft

PUSH_SWAP_SRC_DIR= src_push_swap/

CHECKER_SRC_DIR= src_checker/

HEADER= push_swap.h

CPUSH_SWAP= main.c oper_push_swap.c oper_rotates.c validation.c \
			quicksort.c sort.c sort_three.c sort_two.c operations.c \
			count.c sort_three_b.c stack.c

CCHECKER= main.c oper_push_swap.c oper_rotates.c validation_stack.c \
		  apply_oper.c create_stack.c count_stacklen.c \
		  create_oper.c validation_oper.c create_lst.c

PUSH_SWAP_SRC = $(addprefix $(PUSH_SWAP_SRC_DIR),$(CPUSH_SWAP))

CHECKER_SRC = $(addprefix $(CHECKER_SRC_DIR),$(CCHECKER))

PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:%.c=%.o)

CHECKER_OBJ = $(CHECKER_SRC:%.c=%.o)

submodule = `git submodule | grep "-"`

RULE=$(firstword $(MAKECMDGOALS))

.PHONY: subm all clean fclean re

.SILENT: subm

all: subm $(PUSH_SWAP) $(CHECKER)

subm:
	if [[ -n $(submodule) ]]; then\
		git submodule init;\
		git submodule update;\
	fi

$(PUSH_SWAP): $(PUSH_SWAP_OBJ) $(HEADER)
	make -C libft
	gcc $(FLAGS) $(PUSH_SWAP_OBJ) -o $(PUSH_SWAP) $(LIB)

$(PUSH_SWAP_SRC_DIR)%.o : $(PUSH_SWAP_SRC_DIR)%.c $(HEADER)
	gcc $(FLAGS) $< -o $@

$(CHECKER): $(CHECKER_SRC) $(HEADER)
	make -C libft
	gcc $(FLAGS) $(CHECKER_OBJ) -o $(CHECKER) $(LIB)

$(CHECKER_SRC_DIR)%.o : $(CHECKER_SRC_DIR)%.c $(HEADER)
	gcc $(FLAGS) $< -o $@

clean:
	@rm -f $(OBJ)
ifneq ($(RULE), $(filter $(RULE), fclean re))
	@make clean -C libft/
endif
	@echo "\033[0;33mthe src directories are cleaned\033[0m"

fclean: clean
	make fclean -C libft/
	rm -fv $(PUSH_SWAP) $(CHECKER)

re: fclean all
