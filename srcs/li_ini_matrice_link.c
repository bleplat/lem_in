/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_ini_matrice_link.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:49:41 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/03 18:30:49 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

int			li_free_link(t_board board)
{
	int i;

	i = -1;
	while (++i < board.rooms_count)
	{
		if (board.rooms[i].link != NULL)
			free(board.rooms[i].link);
	}
	return (-1);
}

static int	li_find_link(int index, int **matrice, t_board board)
{
	t_room *room;
	int i;

	i = -1;
	while (++i < board.links_count)
	{
		if (board.links[i].i_room_a == index)
		{
			room = &board.rooms[index];
			matrice[index][board.links[i].i_room_b] = 1;
			matrice[board.links[i].i_room_b][index] = 1;
			if (li_memrealloc((void **)&(room->link), sizeof(int) *
			room->count_link, sizeof(int) * (room->count_link + 1)))
				return(li_free_link(board));
			room->link[room->count_link] = board.links[i].i_room_b;
			room->count_link++;
			room = board.links[i].p_room_b;
			if (li_memrealloc((void **)&(room->link), sizeof(int) *
			room->count_link, sizeof(int) * (room->count_link + 1)))
				return(li_free_link(board));
			room->link[room->count_link] = index;
			room->count_link++;
		}
	}
	return (0);
}

int			li_ini_matrice_link(t_board board, int **matrice)
{
	int		i;

	i = -1;
	while (++i < board.rooms_count)
	{
		if (li_find_link(i, matrice, board) == -1)
			return (-1);
	}
	return (0);
}