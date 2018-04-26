/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 12:32:02 by tmerli            #+#    #+#             */
/*   Updated: 2018/02/15 05:10:03 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		smallest(t_stack *stack)
{
	int smallest;

	smallest = 0;
	if (stack)
	{
		smallest = stack->nb;
		stack = stack->next;
		while (stack && !stack->pivot)
		{
			if (stack->nb < smallest)
				smallest = stack->nb;
			stack = stack->next;
		}
	}
	return (smallest);
}

int		biggest(t_stack *stack)
{
	int biggest;

	biggest = 0;
	if (stack)
	{
		biggest = stack->nb;
		stack = stack->next;
		while (stack && !stack->pivot)
		{
			if (stack->nb > biggest)
				biggest = stack->nb;
			stack = stack->next;
		}
	}
	return (biggest);
}

int		sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		reverse_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->nb < stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		stack_size(t_stack *stack)
{
	int i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
