CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

SRCS = ft_printf.c writestr.c writechar.c writenbr.c writeunbr.c writeul_base.c
OBJS = $(SRCS:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

play : play.c $(NAME) 
	$(CC) $(CFLAGS) $^  -o play

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

%.o: %.c libftprintf.h
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all