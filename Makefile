# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/10 17:16:47 by falmeida          #+#    #+#              #
#    Updated: 2021/07/10 19:35:00 by falmeida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -g

NAME = push_swap

SRC = push_swap.c		\
	  moviments.c		\
	  utils.c			\
	  tester.c			\

OBJS = $(SRC:.c=.o)

$(NAME) : $(OBJS)
	gcc $(OBJS) $(FLAGS) -o $(NAME) 

all: $(NAME)

clean:
	/bin/rm -rf $(OBJS)

fclean:
	/bin/rm -f $(NAME)

re: fclean all