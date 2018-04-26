/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmerli <tmerli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:17:08 by tmerli            #+#    #+#             */
/*   Updated: 2018/02/15 04:56:41 by tmerli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_move(t_move **moves, char *move)
{
	t_move *nmove;

	nmove = (t_move *)malloc(sizeof(t_move));
	nmove->move = move;
	nmove->next = NULL;
	if (*moves)
		moves[0]->next = nmove;
	*moves = nmove;
}

void	do_move(char *move, t_stack **a, t_stack **b, t_move **moves)
{
	add_move(moves, move);
	move_stack(move, a, b);
}
