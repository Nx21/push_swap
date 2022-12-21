# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 14:04:11 by nhanafi           #+#    #+#              #
#    Updated: 2022/04/26 13:43:37 by nhanafi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
BONUS = checker
HEADER = fonc.h
BHEADER = checker_bonus.h
MHEADER = push_swap.h
MSRC = decision_tree.c push_swap.c quick_sort.c quick_sort_util.c algo.c algo_utils.c 
SRC = error.c feed_back.c push_a.c push_b.c rotation.c stacks_make.c stacks_make_util.c swap.c r_rotation.c
BSRC = checker_bonus.c
OBJ = $(SRC:.c=.o)
MOBJ = $(MSRC:.c=.o)
BOBJ = $(BSRC:.c=.o)
all: $(NAME) 
bonus: $(BONUS)
$(NAME): $(OBJ) $(MOBJ) $(HEADER) $(MHEADER)
	$(CC) $(CFLAGS) $(OBJ) $(MOBJ) -o $@
$(BONUS): $(OBJ) $(BOBJ) $(HEADER) $(BHEADER)
	$(CC) $(CFLAGS) $(OBJ) $(BOBJ) -o $@
%.o: %.c 
	$(CC) -c $(CFLAGS) $<
clean:
	rm -rf $(OBJ) $(BOBJ) $(MOBJ)
fclean: clean
	rm -rf $(NAME) $(BONUS)
re: fclean all