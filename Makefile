# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: majones <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/12 14:04:26 by majones           #+#    #+#              #
#    Updated: 2018/08/12 14:52:07 by majones          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCW = gcc -Wall -Wextra -Werror 
NAME = fillit
SRC = 	main.c\
		tetriminos.c\
		arrange.c\
		read.c\
		shape.c\
		usage.c\
		solve.c\
		check.c\

OBJECT = $(SRC:.c=.o)

all: $(NAME) 

$(NAME): libft_compile 
	@echo "Compiling Project..."
	@$(GCCW) -I. -c $(SRC)
	@$(GCCW) $(OBJECT) ./libft/libft.a -o $(NAME)
	@echo "Finished!"

libft_compile:
	@+$(MAKE) -C ./libft

libft_clean:
	@+$(MAKE) clean -C ./libft

libft_fclean:
	@+$(MAKE) fclean -C ./libft

clean: libft_clean
	@echo "Cleanning Project..."
	@/bin/rm -f $(OBJECT)
	@echo "Cleaned"

fclean: clean libft_fclean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft_clean libft_compile
