/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 19:06:32 by tmerli            #+#    #+#             */
/*   Updated: 2018/02/26 14:57:02 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct	s_stack
{
	int				nb;
	struct s_stack	*next;
	int				pivot;
}				t_stack;

typedef struct	s_move
{
	char			*move;
	struct s_move	*next;
}				t_move;

void			sorted_b(t_stack **a, t_stack **b, t_move *moves);
void			close_pivot(t_stack **a, t_stack **b, t_move **moves);
void			sort_pivotb(t_stack **a, t_stack **b, t_move **moves, int *re);
void			sort_pivota(t_stack **a, t_stack **b, t_move **moves, int *re);
int				any_pivot(t_stack *a);
int				to_next_pivot(t_stack *stack);
int				best_pivot(t_stack *stack, int biggest, int smallest);
void			add_move(t_move **moves, char *move);
void			do_move(char *move, t_stack **a, t_stack **b, t_move **moves);
void			check_put(t_move *moves);
int				move_stack(char *move, t_stack **stacka, t_stack **stackb);
void			get_sort_b(t_stack **a, t_stack **b, t_move *moves);
void			small_sort(t_stack **a, t_stack **b, t_move *moves);
void			get_sort_a(t_stack **a, t_stack **b, t_move *moves);
t_stack			*get_stack(int argc, char **argv);
int				ft_free(void **ptr);
t_stack			*new_stack(int nb);
void			free_stack(t_stack *stack);
void			swap(t_stack **stack);
void			s_swap(t_stack **stacka, t_stack **stackb);
void			push(t_stack **from, t_stack **to);
int				check_num(int nb, char *argv, t_stack *stack);
void			rotate(t_stack **stack);
void			r_rotate(t_stack **stacka, t_stack **stackb);
void			r_reverse_rotate(t_stack **stacka, t_stack **stackb);
void			reverse_rotate(t_stack **stack);
void			print_stack(t_stack *stack);
int				checksort(t_stack *stacka, t_stack *stackb);
int				stack_size(t_stack *stack);
int				reverse_sorted(t_stack *stack);
int				sorted(t_stack *stack);
int				biggest(t_stack *stack);
int				smallest(t_stack *stack);
int				last(t_stack *a);

#endif
