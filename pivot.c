/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 05:12:48 by tmerli            #+#    #+#             */
/*   Updated: 2018/02/15 05:15:50 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		best_pivot(t_stack *stack, int biggest, int smallest)
{
	int median;
	int sub;
	int pivot;

	pivot = 0;
	median = (biggest + smallest) / 2;
	if (stack)
	{
		sub = ft_abs(median - stack->nb);
		pivot = stack->nb;
		stack = stack->next;
	}
	while (stack && !stack->pivot)
	{
		if (ft_abs(median - stack->nb) < sub)
		{
			sub = ft_abs(median - stack->nb);
			pivot = stack->nb;
		}
		stack = stack->next;
	}
	return (pivot);
}

int		to_next_pivot(t_stack *stack)
{
	int i;

	i = 0;
	while (stack && !stack->pivot)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int		any_pivot(t_stack *a)
{
	while (a)
	{
		if (a->pivot == 1)
			return (1);
		a = a->next;
	}
	return (0);
}
