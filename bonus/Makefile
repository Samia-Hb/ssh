CFLAGS = -Wall -Wextra -Werror
CC = gcc
NAME = push_bonus.a
AR = ar rcs
SRCS = get/*.c checker.c check_arg.c movements_bonus_P2.c push_swap_utils_bonus.c movements_bonus.c ft_split.c ft_atoi.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $(OBJS)

clean:
	rm -f $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re%