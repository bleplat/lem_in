/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_create_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:00:00 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/04 15:16:19 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

static void	li_return_old_version(t_board board, int **matrice)
{
	int i;
	int j;

	i = -1;
	while (++i < board.rooms_count)
	{
		if (board.rooms[i].status == 5 || board.rooms[i].status == 6)
		{
			j = -1;
			board.rooms[i].status = 2;
			while (++j < board.rooms[i].count_link)
			{
				if (board.rooms[board.rooms[i].link[j]].status == 6 &&
				matrice[board.rooms[i].index][board.rooms[i].link[j]] == 4)
					board.rooms[board.rooms[i].link[++j]].status = 2;
			}
		}
	}
	i = -1;
	while (++i < board.rooms_count)
	{
		j = -1;
		while (++j < board.rooms_count)
		{
			if (matrice[i][j] == 6)
				matrice[i][j] = 4;
			if (matrice[i][j] == 7)
				matrice[i][j] = 5;
		}
	}
}

static void	li_valide_path_matrice(t_board board, int **matrice)
{
	t_room	*rooms;

	rooms = &(board.rooms[1]);
	while (rooms->prev != NULL)
	{
		if (rooms->index != 1)
			rooms->status = 2;
		else
			rooms->status = 3;
		matrice[rooms->index][rooms->prev->index] = 4;
		matrice[rooms->prev->index][rooms->index] = 5;
		rooms = rooms->prev;
	}
}

/*
** Call li_calc_step and depending of result return create new path or
** take old version
**
** Return Value:
**
** -1 = Malloc fail
** -2 = path no valid stop bfs
** 0 = all is fine
*/

int	li_create_path(t_board board, int **matrice)
{
	int result;

	if ((result = li_calc_step(board, 0)) == -1)
		return (-1);
	if (result == -2)
	{
		li_return_old_version(board, matrice);
		return (-2);
	}
	li_valide_path_matrice(board, matrice);
	return (0);
}
