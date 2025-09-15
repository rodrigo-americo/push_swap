/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgregori <rgregori@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:24:26 by rgregori          #+#    #+#             */
/*   Updated: 2025/09/15 11:16:06 by rgregori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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
	int				idx;   /* índice normalizado (0..n-1) */
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

/* ============================== */
/*        CRIAÇÃO/DESTRUIÇÃO      */
/* ============================== */

t_stack	*ps_stack_new(char name);
void	ps_stack_clear(t_stack **s);
t_node	*ps_node_new(int val);
void	ps_stack_push_top(t_stack *s, t_node *n);
t_node	*ps_stack_pop_top(t_stack *s);

/* ============================== */
/*            PARSING             */
/* ============================== */

int		ft_parse_args(int ac, char **av);
t_bool	ft_is_number(const char *s);
t_bool	ft_atoi_safe(const char *s, int *out);
t_bool	ft_has_duplicates(const t_stack *a);

/* ============================== */
/*             CHECKS             */
/* ============================== */

int		ps_is_sorted(const t_stack *s);               /* 1/0 crescente por idx */
int		ps_min_idx(const t_stack *s);                 /* menor idx presente */
int		ps_max_idx(const t_stack *s);                 /* maior idx presente */
int		ps_pos_of_idx(const t_stack *s, int idx);     /* posição (0 topo) ou -1 */

/* ============================== */
/*       NORMALIZAÇÃO/ÍNDICES     */
/* ============================== */

void	ps_normalize_indices(t_stack *a);
/* mapeia valores -> índices 0..n-1 (estável e sem negativos) */

int		ps_get_max_bits(const t_stack *a);
/* nº de bits necessário para representar o maior idx */

/* ============================== */
/*        OPERAÇÕES BÁSICAS       */
/*  Cada op recebe flag 'log':    */
/*  1 -> imprime ("sa\n" etc.)    */
/*  0 -> não imprime (checker)    */
/* ============================== */

void	ps_sa(t_stack *a, int log);
void	ps_sb(t_stack *b, int log);
void	ps_ss(t_stack *a, t_stack *b, int log);

void	ps_pa(t_stack *a, t_stack *b, int log);
void	ps_pb(t_stack *a, t_stack *b, int log);

void	ps_ra(t_stack *a, int log);
void	ps_rb(t_stack *b, int log);
void	ps_rr(t_stack *a, t_stack *b, int log);

void	ps_rra(t_stack *a, int log);
void	ps_rrb(t_stack *b, int log);
void	ps_rrr(t_stack *a, t_stack *b, int log);

/* ============================== */
/*     MOVIMENTAÇÃO INTELIGENTE   */
/* ============================== */

void	ps_rotate_to_top(t_stack *s, int pos, int log);
/* roda pela menor distância até a posição 'pos' chegar ao topo */

void	ps_move_idx_to_top(t_stack *s, int target_idx, int log);
/* encontra pos do idx e chama rotate_to_top */

int		ps_cheapest_pos_to_push(const t_stack *s, int limit_low, int limit_high);
/* para chunking: retorna pos do elemento cujo idx está no intervalo dado,
   escolhendo o que exige menos rotações; -1 se não há */

/* ============================== */
/*        ESTRATÉGIAS/ALGO        */
/* ============================== */

void	ps_sort_3(t_stack *a);
void	ps_sort_5(t_stack *a, t_stack *b);

void	ps_sort_radix(t_stack *a, t_stack *b);
/* radix por bits sobre 'idx' normalizado */

void	ps_sort_chunks(t_stack *a, t_stack *b, int chunks);
/* divide em 'chunks' por faixa de idx e ordena */

/* ============================== */
/*             LOG/ERR            */
/* ============================== */

void	ps_error_and_exit(void);
/* escreve "Error\n" em stderr e finaliza */

void	ps_print_stack(const t_stack *s);
/* utilitário opcional para debug na defesa (sem uso no avaliador) */

/* ============================== */
/*             BÔNUS              */
/*           (CHECKER)            */
/* ============================== */

int		ps_exec_op(const char *op, t_stack *a, t_stack *b);
/* executa uma string de instrução: "sa","pb","rra",...; retorna 1 ok / 0 erro */

int		ps_checker_run(int ac, char **av);
/* fluxo principal do checker: parse, ler stdin, executar, imprimir "OK"/"KO" */

#endif
