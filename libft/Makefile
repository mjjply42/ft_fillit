# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majones <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/30 13:11:29 by majones           #+#    #+#              #
#    Updated: 2018/09/14 20:31:16 by majones          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -c -Wall -Wextra -Werror

HEADER = libft.h

SRCS = *.c    

BINS =	$(SRCS:.c=.o)

all:	$(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) -I.
	ar rc $(NAME) $(BINS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(BINS)

fclean:	clean
	/bin/rm -f $(NAME)

re:	fclean all
