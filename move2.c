/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 07:22:40 by tmerli            #+#    #+#             */
/*   Updated: 2018/02/15 05:01:40 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack *tmp;

	if (*stack && stack[0]->next)
	{
		tmp = *stack;
		while (stack[0]->next)
			*stack = stack[0]->next;
		stack[0]->next = tmp;
		*stack = tmp->next;
		tmp->next = NULL;
	}
}

void	r_rotate(t_stack **stacka, t_stack **stackb)
{
	rotate(stacka);
	rotate(stackb);
}
