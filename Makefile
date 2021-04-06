# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cerlich <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/06 12:26:33 by cerlich           #+#    #+#              #
#    Updated: 2020/12/07 13:03:38 by cerlich          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	  handling.c \
	  print_int.c \
	  print_char_str.c \
	  print_hex.c \
	  print_pointer.c \
	  print_percent.c \

OBJS = $(SRC:.c=.o)

ALL_OBJS = *.o

LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	ar rc $(NAME) $(ALL_OBJS)

$(LIBFT):
	(cd libft; make all)
	ar -x $(LIBFT)

$(OBJS) :%.o : %.c ft_printf.h
		$(CC) $(CFLAGS) -o $@ -c $<

clean :
	(cd libft; make clean)
	rm -f $(ALL_OBJS)

fclean : clean
	(cd libft; make fclean)
	rm -f $(NAME)

re : fclean all
