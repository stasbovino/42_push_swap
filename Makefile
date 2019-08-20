# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gwyman-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/20 16:49:39 by gwyman-m          #+#    #+#              #
#    Updated: 2019/08/20 18:12:17 by gwyman-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

PSWAP = push_swap

CH_DIR = d_check/

PS_DIR = d_pswap/

INCL_DIR = incl/

FLAGS = -g -Wall -Wextra -Werror -I $(INCL_DIR)

CFILES = main.c 

OFILES = $(CFILES:%.c=%.o)

SRC = $(addprefix $(SRC_DIR),$(CFILES))

LIBOBJ = $(addprefix $(LIB_DIR),$(OLIBFILES))

VPATH := d_pswap:d_check

all: $(CHECKER) $(PSWAP)

$(CHECKER): w

$(PSWAP): w

src/%.o: %.c ft_printf.h
	gcc -c $(FLAGS) $< -o $@

clean:
	rm -fv 

fclean: clean
	rm -fv $(CHECKER) $(PSWAP)

re: fclean all
