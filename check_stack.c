/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 05:31:59 by tmerli            #+#    #+#             */
/*   Updated: 2018/01/19 23:35:30 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_double(int n, t_stack *stack)
{
	while (stack->next)
	{
		if (stack->nb == n)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		check_num(int n, char *s, t_stack *stack)
{
	int		i;
	int		end;
	long	tmp;

	tmp = n;
	end = 0;
	if (n < 0)
	{
		if (s[0] != '-')
			return (0);
		tmp = -tmp;
		end++;
	}
	i = ft_strlen(s) - 1;
	while (i >= end)
	{
		if (s[i] != tmp % 10 + 48)
			return (0);
		tmp = tmp / 10;
		i--;
	}
	return (check_double(n, stack));
}

int		checksort(t_stack *stacka, t_stack *stackb)
{
	int tmp;

	if (stackb)
		return (0);
	tmp = stacka->nb;
	stacka = stacka->next;
	while (stacka)
	{
		if (tmp >= stacka->nb)
			return (0);
		tmp = stacka->nb;
		stacka = stacka->next;
	}
	return (1);
}
