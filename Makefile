# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 16:47:10 by nazouz            #+#    #+#              #
#    Updated: 2024/01/22 21:02:09 by nazouz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror -g3

INCLUDES		=	./pipex.h

RM				=	rm -f

SRCS				=	\
					./libft/ft_split.c \
					./libft/ft_strncmp.c \
					./libft/ft_putstr_fd.c \
					./libft/ft_putchar_fd.c \
					./libft/ft_strjoin.c \
					./libft/ft_strdup.c \
					./libft/ft_strlen.c \
					./libft/ft_memcpy.c \
					./libft/ft_strlcpy.c \
					./ft_printf/ft_printf.c \
					./ft_printf/ft_print_add.c \
					./ft_printf/ft_printhex.c \
					./ft_printf/ft_printu.c \
					./ft_printf/ft_putchar.c \
					./ft_printf/ft_putnbr.c \
					./ft_printf/ft_putstr.c \
					./exit.c \
					./helpers.c \
					./parse.c \
					./parse_utils.c \
					./execute.c \
					./main.c

OBJS			=	$(SRCS:.c=.o)

all : $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all