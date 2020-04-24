/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_reset_bfs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 16:03:07 by jthierce          #+#    #+#             */
/*   Updated: 2020/04/24 17:04:43 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

void		li_first_reset(t_board board)
{
	int i;

	i = -1;
	while (++i < board.rooms_count)
	{
		if (board.rooms[i].status == 7)
			board.rooms[i].status = 2;
		else if (board.rooms[i].status == 8)
			board.rooms[i].status = 2;
	}
}

static void	li_reset_rooms_status(t_board board, int **matrice)
{
	int i;
	int j;

	i = -1;
	while (++i < board.rooms_count)
	{
		j = -1;
		if (board.rooms[i].status == 7 ||
			board.rooms[i].status == 8)
			board.rooms[i].status = 2;
		else if (board.rooms[i].status == 1)
			board.rooms[i].status = 0;
		else if (board.rooms[i].status == 5 ||
		board.rooms[i].status == 6)
		{
			board.rooms[i].status = 0;
			while (++j < board.rooms[i].count_link)
			{
				if (matrice[i][board.rooms[i].link[j]] == 4 ||
				matrice[i][board.rooms[i].link[j]] == 6)
					board.rooms[i].prev = &board.rooms[board.rooms[i].link[j]];
			}
		}
	}
}

static void	li_reset_matrice(int **matrice, t_board board)
{
	int j;
	int i;

	i = -1;
	while (++i < board.rooms_count)
	{
		j = 0;
		while (++j < board.rooms_count)
		{
			if (matrice[i][j] != 0)
			{
				if (matrice[i][j] == 2 ||
				matrice[i][j] == 3)
					matrice[i][j] = 1;
				else if (matrice[i][j] == 6 || matrice[i][j] == 7)
					matrice[i][j] = 0;
			}
		}
	}
}

void		li_reset_bfs(t_board board, int **matrice)
{
	li_reset_rooms_status(board, matrice);
	li_reset_matrice(matrice, board);
}
