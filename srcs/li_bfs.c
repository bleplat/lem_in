/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:03:31 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/28 15:22:07 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_board.h"

static void	li_reset_bfs(t_board board)
{
}

static void	li_create_path(t_board t_board, int **matrice)
{
}

static int	li_first_bfs(t_board board, int **matrice, int *queu, int *j)
{
	int i;

	i = -1;
	while (++i < board.rooms[0].count_link)
	{
		if (board.rooms[0].link[i] == 1)
			return (1);
		if (board.rooms[board.rooms[0].link[i]].status == 0)
		{
			matrice[0][board.rooms[0].link[i]] = 2;
			matrice[board.rooms[0].link[i]][0] = 2;
			queu[*(++j)] = board.rooms[0].link[i];
			board.rooms[board.rooms[0].link[i]].status = 1;
			board.rooms[board.rooms[0].link[i]].prev = &board.rooms[0];
		}
	}
	return (0);
}

int		li_bfs(t_board board, int **matrice)
{
	int	*queu;
	int i;
	int j;


	i = -1;
	j = -1;
	if (!(queu = (int *)malloc(sizeof(int) * board.rooms_count)))
		return (-1);
	ft_bzero(queu, board.rooms_count);
	if (li_first_bfs(board, matrice, queu, &j))
	{
		free(queu);
		return (2);
	}
	while  (board.rooms[1].status == 1 && queu[++i] != 0)
		j += li_bfs_body(board, matrice, queu + i, j - i);
	if (queu[i] == 0 && board.rooms[1].status == 0)
		return (-2);
	else if (queu[i] != 0)
		li_create_path(board, matrice);
	return (0);
}
