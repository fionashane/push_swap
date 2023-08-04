NAME = push_swap
LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a

SRCS = push_swap.c ft_sort.c ft_move.c \
	   ft_lst.c ft_find.c ft_check_error.c \
	   ft_case_b.c ft_case_a.c ft_calc.c \
	   ft_actions_single.c ft_actions_both.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(AR) $(OBJS) -o $(NAME) $(LIBFT)

$(LIBFT):
	make -C $(LIBFTDIR)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)
	make -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
