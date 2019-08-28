# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/28 23:35:25 by gwyman-m          #+#    #+#              #
#    Updated: 2019/08/28 23:44:59 by gwyman-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

FLAGS = -Wall -Wextra -Werror -I.

PUSH_SWAP_SRC_DIR= src_push_swap/

CPUSH_SWAP=  main.c oper_push_swap.c oper_rotates.c sort.c sort_for_onetwothree.c validation.c

PUSH_SWAP_SRC = $(addprefix $(PUSH_SWAP_DIR),$(CPUSH_SWAP))

all: $(NAME)

$(NAME): $(PUSH_SWAP_SRC)
	make -C libft/
	gcc $(FLAGS) $(PUSH_SWAP_SRC) -o push_swap

clean:
	make clean -C libft/

fclean: clean
	make fclean -C libft/
	rm -fv $(NAME)

re: fclean all
