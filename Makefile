# Nome dos binários finais
NAME_CLIENT = client
NAME_SERVER = server

# Nome da biblioteca ft_printf
LIBFTPRINTF = ft_printf/libftprintf.a

# Compilador e flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Diretórios e fontes
SRC_CLIENT = client.c
SRC_SERVER = server.c
SRC_PRINTF = ft_printf/ft_printf.c ft_printf/ft_support_functions.c ft_printf/ft_support_functions2.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)

# Regras padrão
all: $(LIBFTPRINTF) $(NAME_CLIENT) $(NAME_SERVER)

# Compilar a biblioteca ft_printf
$(LIBFTPRINTF): $(OBJ_PRINTF)
	$(AR) rcs $(LIBFTPRINTF) $(OBJ_PRINTF)

# Compilar o cliente
$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFTPRINTF) -o $(NAME_CLIENT)

# Compilar o servidor
$(NAME_SERVER): $(OBJ_SERVER) $(LIBFTPRINTF)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFTPRINTF) -o $(NAME_SERVER)

# Regra para gerar objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar objetos
clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_PRINTF)

# Limpar objetos e binários
fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(LIBFTPRINTF)

# Recompilar tudo
re: fclean all

.PHONY: all clean fclean re
