# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slaree <slaree@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 23:28:44 by chfederi          #+#    #+#              #
#    Updated: 2022/07/15 20:32:27 by slaree           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS =	main.c envinit.c utils1.c\
		dash/cmd.c dash/ft_putstr_fd.c dash/ft_split.c dash/ft_strjoin.c dash/ft_strlen.c dash/ft_strncmp.c dash/parse.c dash/ft_isspace.c dash/ft_substr.c\
		pwd.c

HEADER = minishell.h

OBJS		=	$(SRCS:.c=.o)

CC = gcc -g -fsanitize=address
# CFLAGS = -Wall -Wextra -Werror
# -g -fsanitize=address
RLFLAGS = -lreadline -L ~/.brew/opt/readline/lib
all:		$(NAME)

$(NAME):	$(OBJS)
				$(CC) $(RLFLAGS) $^ -o $@
				
%.o		:	%.c $(HEADER) Makefile
			$(CC) -c $< -o $@ 

clean	:	
			rm -rf $(OBJS)

fclean	:	clean
			rm -rf $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
