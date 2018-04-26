/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:57:24 by tmerli            #+#    #+#             */
/*   Updated: 2018/02/28 00:50:40 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sort(t_stack *stacka, int size)
{
	t_stack		*stackb;
	char		*line;
	int			error;

	error = 0;
	stackb = NULL;
	while (get_next_line(0, &line))
	{
		if (!(move_stack(line, &stacka, &stackb)))
		{
			ft_putendl("Error");
			error = 1;
			break ;
		}
		free(line);
	}
	free(line);
	if (!error && checksort(stacka, stackb))
		ft_putendl("OK");
	else if (!error)
		ft_putendl("KO");
	free_stack(stacka);
	free_stack(stackb);
}

int		main(int argc, char *argv[])
{
	t_stack *stack;

	stack = NULL;
	if (argc >= 2)
	{
		if (!(stack = get_stack(argc, argv)))
			return (0);
	}
	else
		return (0);
	do_sort(stack, argc);
	return (0);
}
