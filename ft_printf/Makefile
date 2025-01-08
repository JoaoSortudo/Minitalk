NAME = libftprintf.a

COMP = cc -Wall -Werror -Wextra

SRC = ft_printf.c ft_support_functions.c ft_support_functions2.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

.o: .c
	$(COMP) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
