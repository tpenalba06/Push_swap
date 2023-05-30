# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 18:43:38 by tpenalba          #+#    #+#              #
#    Updated: 2023/05/30 16:10:16 by tpenalba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = utils.c utilschain.c checkinput.c main.c movements.c utils2.c

OBJS            = $(SOURCES:.c=.o)
NAME			= push_swap
CC              = gcc
RM              = rm -rf
FLAGS          = -Wall -Wextra -Werror
ARFLAGS = -rcs
all :           $(NAME)
$(NAME):        $(OBJS)
		gcc $(FLAGS) $(OBJS) -o $(NAME) 
clean:
				$(RM) $(OBJS)
fclean:         clean
				$(RM) $(NAME)
re:             fclean $(NAME)
.PHONY:         all clean fclean re