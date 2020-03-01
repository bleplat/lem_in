/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:03:31 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/01 18:14:14 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

static int li_search_other_path(t_board board, int **matrice, int *queu, int *j)
{
	int i;

	i = -1;
	while  (board.rooms[1].status == 1 && queu[++i] != 0)     //doute de la condition
		*j += li_bfs_body(board, matrice, queu + i, *j - i);
	if (queu[i] == 0 && board.rooms[1].status == 0)
	{
		free(queu);
		return (-2);
	}
	else if (queu[i] == 0) //doute de la condition
		return (1);
	if ((i = li_create_path(board, matrice)) == -1)
		return (-1);
	if (i == -2)
		return (1);
	return (0);
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

/*
** The head of bfs
**
** Return Value:
**
** -1 = malloc fail
** -2 = pas de chemin trouvé
** 1 = Bfs is okay min 1 path is find
** 2 = end is link with start so we can print in one line
*/

int		li_bfs(t_board board, int **matrice)
{
	int	*queu;
	int i;
	int j;


	i = -1;
	j = -1;
	if (!(queu = (int *)malloc(sizeof(int) * board.rooms_count)))
		return (-1);
	while (i != 1)
	{
		ft_bzero(queu, board.rooms_count);
		if (li_first_bfs(board, matrice, queu, &j))
		{
			free(queu);
			return (2);
		}
		i = li_search_other_path(board, matrice, queu, &j);
		if (i == -1 || i == -2)
		{
			free(queu);
			return (i);
		}
	}
	free(queu);
	return (0);
}
