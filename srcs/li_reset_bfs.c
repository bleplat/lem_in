/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_reset_bfs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:03:07 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/01 16:28:24 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

static void	li_reset_rooms_status(t_board board)
{
	int i;

	i = -1;
	while (++i < board.rooms_count)
	{
		if (board.rooms[i].status == 1 ||
		board.rooms[i].status == 5 ||
		board.rooms[i].status == 6)
			board.rooms[i].status = 0;
	}
}

static void	li_reset_matrice(int **matrice, t_board board)
{
	int j;
	int i;

	i = -1;
	while (++i < board.rooms_count)
	{
		j = -1;
		while (++j < board.rooms_count)
		{
			if (matrice[i][j] == 2 ||
			matrice[i][j] == 3 ||
			matrice[i][j] == 6 ||
			matrice[i][j] == 7)
				matrice[i][j] = 1;
		}
	}
}

void	li_reset_bfs(t_board board, int **matrice)
{
	li_reset_rooms_status(board);
	li_reset_matrice(matrice, board);
}