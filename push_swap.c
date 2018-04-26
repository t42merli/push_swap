/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 05:57:26 by tmerli            #+#    #+#             */
/*   Updated: 2018/02/28 03:04:48 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_sort_b(t_stack **a, t_stack **b, t_move *moves)
{
	int re;

	re = 0;
	if (reverse_sorted(*b))
	{
		sorted_b(a, b, moves);
		return ;
	}
	if (to_next_pivot(*b) < 4)
		close_pivot(a, b, &moves);
	else
	{
		sort_pivotb(a, b, &moves, &re);
		if (any_pivot(*b))
		{
			while (re > 0)
			{
				do_move("rrb", a, b, &moves);
				re--;
			}
		}
		get_sort_a(a, b, moves);
	}
}

void	get_sort_a(t_stack **a, t_stack **b, t_move *moves)
{
	int re;

	re = 0;
	if (sorted(*a))
	{
		if (*b)
			get_sort_b(a, b, moves);
		return ;
	}
	else
	{
		sort_pivota(a, b, &moves, &re);
		if (any_pivot(*a))
		{
			while (re > 0)
			{
				do_move("rra", a, b, &moves);
				re--;
			}
		}
		get_sort_a(a, b, moves);
	}
}

int		main(int argc, char **argv)
{
	t_stack		*a;
	t_stack		*b;
	t_move		*moves;

	moves = NULL;
	add_move(&moves, "start:");
	a = NULL;
	b = NULL;
	if (argc >= 2)
	{
		if (!(a = get_stack(argc, argv)))
			return (0);
	}
	else
		return (0);
	if (stack_size(a) > 30)
		get_sort_a(&a, &b, moves);
	else
		small_sort(&a, &b, moves);
	check_put(moves);
	free_stack(a);
	free_stack(b);
	return (0);
}
