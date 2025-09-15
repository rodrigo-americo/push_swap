# =======================
# Makefile - test_intvec
# =======================

# Binário de teste
NAME        := test_intvec

# Compilador e flags
CC          := cc
CFLAGS      := -Wall -Wextra -Werror

# Includes
INCLUDE_DIR := include
LIBFT_INC   := libft/include                 # onde está libft.h
PRINTF_INC  := printf/include     # ajuste se o teu ft_printf usar outro path

INCS        := -I$(INCLUDE_DIR) -I$(LIBFT_INC) -I$(PRINTF_INC)

# Pastas das libs
LIBFT_DIR   := libft
PRINTF_DIR  := printf

# Artefatos das libs (nomes padrão da 42)
LIBFT_A     := $(LIBFT_DIR)/libft.a
PRINTF_A    := $(PRINTF_DIR)/libftprintf.a

# Fontes do teste
SRC_DIR     := src/mandatory
TEST_DIR    := tests
OBJ_DIR     := obj

SRCS        := $(TEST_DIR)/main.c \
               $(SRC_DIR)/ft_intvec.c

OBJS        := $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

# =======================
# Regras principais
# =======================

.PHONY: all clean fclean re run libs

all: $(NAME)

# Compila o binário de teste
$(NAME): libs $(OBJS)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -o $@

# Compila as libs primeiro
libs: $(LIBFT_A) $(PRINTF_A)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_A):
	$(MAKE) -C $(PRINTF_DIR)

# Regra genérica para .o (cria pasta obj/… se precisar)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Limpezas
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

# Executar o binário de teste
run: $(NAME)
	./$(NAME)
