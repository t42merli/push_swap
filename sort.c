/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 05:16:45 by tmerli            #+#    #+#             */
/*   Updated: 2018/02/15 05:39:32 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_pivota(t_stack **a, t_stack **b, t_move **moves, int *re)
{
	int pivot;
	int pushed;

	pushed = 0;
	pivot = best_pivot(*a, biggest(*a), smallest(*a));
	while (!pushed || (*a && pivot > smallest(*a)))
	{
		if (a[0]->nb < pivot)
			do_move("pb", a, b, moves);
		else if (a[0]->nb == pivot)
		{
			a[0]->pivot = 1;
			do_move("pb", a, b, moves);
			do_move("rb", a, b, moves);
			pushed = 1;
		}
		else
		{
			*re = *re + 1;
			do_move("ra", a, b, moves);
		}
	}
	do_move("rrb", a, b, moves);
}

void	sort_pivotb(t_stack **a, t_stack **b, t_move **moves, int *re)
{
	int pivot;
	int pushed;

	pushed = 0;
	pivot = best_pivot(*b, biggest(*b), smallest(*b));
	while (!pushed || (*b && pivot < biggest(*b)))
	{
		if (b[0]->nb > pivot)
			do_move("pa", a, b, moves);
		else if (b[0]->nb == pivot)
		{
			pushed = 1;
			b[0]->pivot = 1;
			do_move("pa", a, b, moves);
			do_move("ra", a, b, moves);
		}
		else
		{
			*re = *re + 1;
			do_move("rb", a, b, moves);
		}
	}
	do_move("rra", a, b, moves);
}

void	close_pivot(t_stack **a, t_stack **b, t_move **moves)
{
	while (*b && !b[0]->pivot)
	{
		do_move("pa", a, b, moves);
		if (a[0]->next && a[0]->nb > a[0]->next->nb)
			do_move("sa", a, b, moves);
		if (*b && b[0]->next && b[0]->nb < b[0]->next->nb)
			do_move("sb", a, b, moves);
	}
	if (*b)
		do_move("pa", a, b, moves);
	get_sort_b(a, b, *moves);
}

void	sorted_b(t_stack **a, t_stack **b, t_move *moves)
{
	if (sorted(*a))
	{
		while (*b)
			do_move("pa", a, b, &moves);
	}
	else
		get_sort_a(a, b, moves);
}
