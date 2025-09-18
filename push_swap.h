/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:24:26 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/18 11:38:17 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft.h"

# define LOG 1

/* ============================== */
/*            STRUCTS             */
/* ============================== */

typedef enum e_bool {
	false = 0,
	true = 1
}	t_bool;

typedef struct s_node
{
	int				val;
	int				idx;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bot;
	int		size;
	char	name;
}	t_stack;

typedef struct s_intvec
{
	int		*data;
	size_t	len;
	size_t	cap;
}	t_intvec;

typedef struct s_cheapest_ctx
{
	int	limit_low;
	int	limit_high;
	int	size;
	int	pos;
	int	best_cost;
	int	best_pos;
}	t_cheapest_ctx;

typedef struct s_move
{
	int	cost;
	int	pos_a;
	int	pos_b;
}	t_move;

/* ============================== */
/*        CRIAÇÃO/DESTRUIÇÃO      */
/* ============================== */

t_stack	*ft_stack_new(char name);
void	ft_stack_clear(t_stack **s);
t_stack	*ft_handle_stack(t_intvec *vals);
t_node	*ft_node_new(int val, int idx);
void	ft_stack_push_top(t_stack *s, t_node *n);
void	ft_stack_push_bot(t_stack *s, t_node *n);
t_node	*ft_stack_pop_top(t_stack *s);
t_node	*ft_stack_pop_bot(t_stack *s);

/* ============================== */
/*            PARSING             */
/* ============================== */

t_bool	ft_parse_args(int ac, char **av, t_intvec *vals);
t_bool	ft_is_number(const char *s);
t_bool	ft_atoi_safe(const char *s, int *out);
t_bool	ft_has_duplicates(const t_intvec *v);
int		*ft_copy_data(int *data, int len);

/* ============================== */
/*             CHECKS             */
/* ============================== */

t_bool	ft_is_sorted(const t_stack *s);
int		ft_min_idx(const t_stack *s);
int		ft_max_idx(const t_stack *s);
int		ft_pos_of_idx(const t_stack *s, int idx);
void	ft_sort_int_tab(int *tab, int size);

/* ============================== */
/*            intvec		      */
/* ============================== */

t_bool	ft_intvec_init(t_intvec *v, size_t initial_cap);
t_bool	ft_intvec_push(t_intvec *v, int value);
void	ft_intvec_free(t_intvec *v);

/* ============================== */
/*       	  Utils		    	  */
/* ============================== */
void	ft_free_split(char **s);
/* ============================== */
/*       NORMALIZAÇÃO/ÍNDICES     */
/* ============================== */

int		ft_normalize_indice(int *data, int len, int val);
int		ft_get_max_bits(const t_stack *a);
void	ft_sa(t_stack *a, int log);
void	ft_sb(t_stack *b, int log);
void	ft_ss(t_stack *a, t_stack *b, int log);
void	ft_pa(t_stack *a, t_stack *b, int log);
void	ft_pb(t_stack *a, t_stack *b, int log);
void	ft_ra(t_stack *a, int log);
void	ft_rb(t_stack *b, int log);
void	ft_rr(t_stack *a, t_stack *b, int log);
void	ft_rra(t_stack *a, int log);
void	ft_rrb(t_stack *b, int log);
void	ft_rrr(t_stack *a, t_stack *b, int log);
void	ft_rotate_up(t_stack *s, int log);
void	ft_reverse_rotate(t_stack *s, int log);
/* ============================== */
/*     MOVIMENTAÇÃO INTELIGENTE   */
/* ============================== */

void	ft_rotate_to_top(t_stack *s, int pos, int log);
void	ft_move_idx_to_top(t_stack *s, int target_idx, int log);
int		ft_cheapest_pos_to_push(const t_stack *s, int limit_low,
			int limit_high);
/* ============================== */
/*        ESTRATÉGIAS/ALGO        */
/* ============================== */

void	ft_sort_3(t_stack *a);
void	ft_sort_5(t_stack *a, t_stack *b);
void	ft_sort_radix(t_stack *a, t_stack *b);
void	turk_sort(t_stack *a, t_stack *b);
/* ============================== */
/*             LOG/ERR            */
/* ============================== */

int		ft_error(void);
void	ft_print_stack(const t_stack *s);
void	ft_align_min_on_top(t_stack *a);
int		ft_position_of_min(t_stack *a);
int		calculate_cost(int pos_a, int size_a, int pos_b, int size_b);
void	ft_execute_move(t_stack *a, t_stack *b, t_move *best);
int		ft_find_position_in_a(t_stack *a, int value);
#endif
