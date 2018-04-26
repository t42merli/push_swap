/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 17:33:27 by tmerli            #+#    #+#             */
/*   Updated: 2018/02/15 05:07:03 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			move_stack(char *move, t_stack **stacka, t_stack **stackb)
{
	if (!ft_strcmp(move, "sa"))
		swap(stacka);
	else if (!ft_strcmp(move, "sb"))
		swap(stackb);
	else if (!ft_strcmp(move, "ss"))
		s_swap(stacka, stackb);
	else if (!ft_strcmp(move, "pa"))
		push(stackb, stacka);
	else if (!ft_strcmp(move, "pb"))
		push(stacka, stackb);
	else if (!ft_strcmp(move, "ra"))
		rotate(stacka);
	else if (!ft_strcmp(move, "rb"))
		rotate(stackb);
	else if (!ft_strcmp(move, "rr"))
		r_rotate(stacka, stackb);
	else if (!ft_strcmp(move, "rra"))
		reverse_rotate(stacka);
	else if (!ft_strcmp(move, "rrb"))
		reverse_rotate(stackb);
	else if (!ft_strcmp(move, "rrr"))
		r_reverse_rotate(stacka, stackb);
	else
		return (0);
	return (1);
}

int			last(t_stack *a)
{
	int last;

	last = 0;
	while (a)
	{
		last = a->nb;
		a = a->next;
	}
	return (last);
}

t_stack		*new_stack(int nb)
{
	t_stack *stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	stack->nb = nb;
	stack->pivot = 0;
	stack->next = NULL;
	return (stack);
}

void		free_stack(t_stack *stack)
{
	t_stack *tmp;

	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void		print_stack(t_stack *stack)
{
	ft_putendl("__");
	while (stack)
	{
		ft_putnbr(stack->nb);
		ft_putchar('\n');
		stack = stack->next;
	}
}
