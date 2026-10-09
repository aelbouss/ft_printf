CC = cc
CFLAGS = -Wall -Wextra -Werror
PRINTF = ft_print_address.c ft_print_lower_hex.c ft_print_unsigned.c ft_print_upper_hex.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c
PRINTF_OBJ = $(PRINTF:%.c=%.o)
NAME = libftprintf.a
RM = rm -f

all: $(NAME)

$(NAME): $(PRINTF_OBJ)
	ar rcs $@ $?

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(PRINTF_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
