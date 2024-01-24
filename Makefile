# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 16:47:10 by nazouz            #+#    #+#              #
#    Updated: 2024/01/24 14:37:57 by nazouz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	pipex

NAME_BONUS		=	pipex_bonus

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror -g3

INCLUDES		=	./includes/pipex.h

INCLUDES_BONUS	=	./includes/pipex_bonus.h

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
					./srcs/mandatory/parse.c \
					./srcs/mandatory/execute.c \
					./srcs/mandatory/main.c
					
SRCS_BONUS			=	\
					./libft/ft_split.c \
					./libft/ft_strcmp.c \
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
					./get_next_line/get_next_line.c \
					./srcs/bonus/parse.c \
					./srcs/bonus/execute.c \
					./srcs/bonus/here_doc.c \
					./srcs/bonus/main.c

OBJS			=	$(SRCS:.c=.o)

OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

all : $(NAME)

%.o : %.c $(INCLUDES) $(INCLUDES_BONUS)
	$(CC) -c $(CFLAGS) $< -o $@

bonus : $(NAME_BONUS)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $@

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(OBJS_BONUS) -o $@

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all