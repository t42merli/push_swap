/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 04:26:01 by tmerli            #+#    #+#             */
/*   Updated: 2018/02/15 04:58:15 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		skip_move(t_move **moves)
{
	t_move *tmp;

	tmp = *moves;
	*moves = moves[0]->next;
	free(tmp);
	tmp = *moves;
	*moves = moves[0]->next;
	free(tmp);
	return (1);
}

int		check_rrr(t_move **moves)
{
	int test;

	test = 0;
	if ((!strcmp(moves[0]->move, "rrb") &&
				!strcmp(moves[0]->next->move, "rra"))
			|| (!strcmp(moves[0]->move, "rra") &&
				!strcmp(moves[0]->next->move, "rrb")))
	{
		ft_putendl("rrr");
		test = skip_move(moves);
	}
	return (test);
}

int		check_doubles(t_move **moves)
{
	int test;

	test = 0;
	if ((!strcmp(moves[0]->move, "sb") &&
				!strcmp(moves[0]->next->move, "sa")) ||
			(!strcmp(moves[0]->move, "sa") &&
			!strcmp(moves[0]->next->move, "sb")))
	{
		ft_putendl("ss");
		test = skip_move(moves);
	}
	else if ((!strcmp(moves[0]->move, "rb") &&
				!strcmp(moves[0]->next->move, "ra")) ||
			(!strcmp(moves[0]->move, "ra") &&
			!strcmp(moves[0]->next->move, "rb")))
	{
		ft_putendl("rr");
		test = skip_move(moves);
	}
	else if (check_rrr(moves))
		test = 1;
	return (test);
}

int		check_useless(t_move **moves)
{
	int test;

	test = 0;
	if ((!strcmp(moves[0]->move, "pa") &&
				!strcmp(moves[0]->next->move, "pb")) ||
			(!strcmp(moves[0]->move, "pb") &&
			!strcmp(moves[0]->next->move, "pa")) ||
			(!strcmp(moves[0]->move, "ra") &&
			!strcmp(moves[0]->next->move, "rra")) ||
			(!strcmp(moves[0]->move, "rra") &&
			!strcmp(moves[0]->next->move, "ra")) ||
			(!strcmp(moves[0]->move, "rb") &&
			!strcmp(moves[0]->next->move, "rrb")) ||
			(!strcmp(moves[0]->move, "rrb") &&
			!strcmp(moves[0]->next->move, "rb")))
		test = skip_move(moves);
	return (test);
}

void	check_put(t_move *moves)
{
	t_move	*tmp;
	int		test;

	tmp = moves;
	moves = moves->next;
	free(tmp);
	while (moves && moves->next)
	{
		test = 0;
		if (check_doubles(&moves) || check_useless(&moves))
			test = 1;
		if (!test)
		{
			ft_putendl(moves->move);
			tmp = moves;
			moves = moves->next;
			free(tmp);
		}
	}
	if (moves)
	{
		ft_putendl(moves->move);
		free(moves);
	}
}
