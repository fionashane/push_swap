# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsalimba <fsalimba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/04 13:54:08 by fsalimba          #+#    #+#              #
#    Updated: 2023/08/04 13:54:12 by fsalimba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap

LIBFTDIR 		= libft/
LIBFT 			= $(LIBFTDIR)libft.a

SRCS 			=	push_swap.c ft_sort.c ft_move.c ft_lst.c \
	   				ft_find.c ft_check_error.c ft_case.c ft_calc.c \
	   				ft_actions_single.c ft_actions_both.c

OBJS 			= $(SRCS:.c=.o)

CC 				= gcc
RM 				= rm -f
CFLAGS 			= -Wall -Wextra -Werror

all: 			$(NAME)

$(NAME): 		$(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT):
				make -C $(LIBFTDIR)

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
				make -C $(LIBFTDIR) clean
				$(RM) $(OBJS)

fclean: 		clean
				make -C $(LIBFTDIR) fclean
				$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re
