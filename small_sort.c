/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 05:57:26 by tmerli            #+#    #+#             */
/*   Updated: 2018/02/26 15:13:35 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	next_two(t_stack *stack, int *tab)
{
	int		next_two;
	t_stack	*tmp;

	tmp = stack;
	next_two = stack->nb;
	stack = stack->next;
	while (stack)
	{
		if (stack->nb < next_two)
			next_two = stack->nb;
		stack = stack->next;
	}
	tab[0] = next_two;
	next_two = (tmp->nb > tab[0]) ? tmp->nb : tmp->next->nb;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->nb < next_two && tmp->nb > tab[0])
			next_two = tmp->nb;
		tmp = tmp->next;
	}
	tab[1] = next_two;
}

void	setup(t_stack **a, t_stack **b, int *next, t_move *moves)
{
	if (*a && a[0]->next)
		next_two(*a, next);
	if (stack_size(*a) == 3)
	{
		if (a[0]->nb == biggest(*a))
			do_move("ra", a, b, &moves);
		else if (last(*a) == smallest(*a))
			do_move("rra", a, b, &moves);
		if (a[0]->nb > a[0]->next->nb)
			do_move("sa", a, b, &moves);
	}
}

void	push_back(t_stack **a, t_stack **b, t_move *moves)
{
	if (*a && a[0]->next && a[0]->nb > a[0]->next->nb)
		do_move("sa", a, b, &moves);
	while (*b)
	{
		do_move("pa", a, b, &moves);
		if (a[0]->nb > a[0]->next->nb)
			do_move("sa", a, b, &moves);
	}
}

void	small_sort(t_stack **a, t_stack **b, t_move *moves)
{
	int next[2];

	setup(a, b, next, moves);
	while (*a && a[0]->next && a[0]->next->next && !sorted(*a))
	{
		if (a[0]->nb == next[0] || a[0]->nb == next[1])
		{
			do_move("pb", a, b, &moves);
			if (b[0]->nb == next[0] && a[0]->next)
				next_two(*a, next);
			if (b[0]->next && b[0]->next->nb > b[0]->nb)
				do_move("sb", a, b, &moves);
		}
		else
			do_move("ra", a, b, &moves);
	}
	push_back(a, b, moves);
}
