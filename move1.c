/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 02:53:55 by tmerli            #+#    #+#             */
/*   Updated: 2018/02/15 05:01:22 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	swap(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tmp2;

	if (*stack && stack[0]->next)
	{
		tmp = stack[0]->next->next;
		stack[0]->next->next = *stack;
		tmp2 = stack[0]->next;
		stack[0]->next = tmp;
		*stack = tmp2;
	}
}

void	s_swap(t_stack **stacka, t_stack **stackb)
{
	swap(stacka);
	swap(stackb);
}

void	push(t_stack **from, t_stack **to)
{
	t_stack *tmp;

	if (*from)
	{
		tmp = from[0]->next;
		from[0]->next = *to;
		*to = *from;
		*from = tmp;
	}
}

void	reverse_rotate(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	if (*stack && stack[0]->next)
	{
		while (stack[0]->next && stack[0]->next->next)
			*stack = stack[0]->next;
		stack[0]->next->next = tmp;
		tmp = stack[0]->next;
		stack[0]->next = NULL;
		*stack = tmp;
	}
}

void	r_reverse_rotate(t_stack **stacka, t_stack **stackb)
{
	reverse_rotate(stacka);
	reverse_rotate(stackb);
}
