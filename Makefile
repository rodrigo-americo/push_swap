# =======================
# Makefile - push_swap
# =======================

# Binário de teste
NAME        := push_swap
NAME_BONUS  := checker
# Compilador e flags
CC          := cc
CFLAGS      := -Wall -Wextra -Werror

# Includes
LIBFT_INC   := libft/include

INCS        := -I. -I$(LIBFT_INC)

# Pastas das libs
LIBFT_DIR   := libft

# Artefatos das libs (nomes padrão da 42)
LIBFT_A     := $(LIBFT_DIR)/libft.a

# Fontes do teste

OBJ_DIR     := obj

SRCS := ft_movep.c ft_move_in.c ft_generic.c ft_parsing.c ft_utils.c ft_atoi_safe.c ft_sort_radix.c \
		ft_intvec.c ft_stack.c ft_move_s.c main.c ft_stack_utils.c ft_log.c ft_order_basi.c \
		ft_move_rr.c ft_build.c ft_move_r.c ft_checks.c ft_idx.c ft_node.c ft_duplicate.c ft_turk_sort.c \
		ft_utils_turk.c ft_find_position.c
SRCS_BONUS := ft_atoi_safe_bonus.c ft_checker_bonus.c ft_duplicate_bonus.c ft_intvec_bonus.c ft_move_r_bonus.c \
			  ft_move_s_bonus.c ft_parsing_bonus.c  ft_utils_bonus.c ft_build_bonus.c ft_checks_bonus.c ft_gnl_bonus.c \
			  ft_movep_bonus.c ft_move_rr_bonus.c ft_node_bonus.c ft_stack_bonus.c ft_stack_utils_bonus.c ft_log_bonus.c
OBJS        := $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
OBJS_BONUS	:= $(addprefix $(OBJ_DIR)/,$(SRCS_BONUS:.c=.o))
# =======================
# Regras principais
# =======================

.PHONY: all clean fclean re run libs

all: $(NAME)

# Compila o binário de teste
$(NAME): libs $(OBJS)
	$(CC) $(CFLAGS) $(INCS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): libs $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(INCS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft -o $(NAME_BONUS)

# Compila as libs primeiro
libs: $(LIBFT_A)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

# Regra genérica para .o (cria pasta obj/… se precisar)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

# Limpezas
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
