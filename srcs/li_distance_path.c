/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_distance_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:19:54 by jthierce          #+#    #+#             */
/*   Updated: 2020/04/24 17:51:21 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

static void	li_loop_distance_path(t_board board, int *j, int i)
{
	t_room	*room;

	room = &(board.rooms[board.rooms[1].link[i]]);
	while (room->index != 0)
	{
		(*j)++;
		room = room->prev;
	}
}

/*
** Calcul la distance de tout les chemins
*/

void		li_distance_path(t_board board, int *distance, int size)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (k < size && i < board.rooms[1].count_link)
	{
		j = 1;
		if ((board.rooms[board.rooms[1].link[i]].status == 1 ||
		board.rooms[board.rooms[1].link[i]].status == 2 ||
		board.rooms[board.rooms[1].link[i]].status == 5)
		&& board.rooms[board.rooms[1].link[i]].prev != NULL)
		{
			li_loop_distance_path(board, &j, i);
			distance[k] = j;
			k++;
		}
		i++;
	}
	li_insertion_sort(distance, size);
}
