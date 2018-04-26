# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmerli <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/09 16:38:31 by tmerli            #+#    #+#              #
#    Updated: 2018/02/28 04:21:53 by tmerli           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME2 = checker

CHECKER = checker.c\

PUSH_SWAP = push_swap.c\
			sort.c\

SRC = get_next_line.c\
	  get_stack.c\
	  pivot.c\
	  stack_utils.c\
	  stack_utils2.c\
	  check_put.c\
	  check_stack.c\
	  move1.c\
	  move2.c\
	  move_utils.c\
	  ft_free.c\
	  small_sort.c\

LIBPATH = libft/

LIB = libft.a

HEADER = push_swap.h\
		 get_next_line.h\

FLAGS = -Wall -Wextra -Werror

CC= gcc

OBJ = $(SRC:.c=.o)

all : $(LIB) $(NAME)

$(LIB) :
	make -C $(LIBPATH)

$(NAME) : $(SRC) $(HEADER) $(PUSH_SWAP) $(CHECKER)
	$(CC) -c $(FLAGS) $(SRC)
	$(CC) -o $(NAME) $(OBJ) $(LIBPATH)$(LIB) $(PUSH_SWAP)
	$(CC) -o $(NAME2) $(OBJ) $(LIBPATH)$(LIB) $(CHECKER)

clean :
	make clean -C $(LIBPATH)
	rm -f $(OBJ)

fclean : clean
	rm -f $(LIBPATH)$(LIB)
	rm -f $(NAME)
	rm -f $(NAME2)

re : fclean all
