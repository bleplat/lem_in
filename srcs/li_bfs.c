/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:03:31 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/27 20:07:16 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_board.h"

static void	li_reset_bfs(t_board board)
{
}

static int	li_first_bfs(t_board board, int **matrice, int *queu, int *j)
{
	int i;
	int j;

	i = -1;
	while (++i < board.rooms[0].count_link)
	{
		if (matrice[0][board.rooms[0].link[i]] == 1)
		{
			matrice[0][board.rooms[0].link[i]] = 2;
			matrice[board.rooms[0].link[i]][0] = 2;
			queu[*(++j)] = board.rooms[0].link[i];
		}
	}
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
	while (++i < board.rooms[0].count_link)
	{
		if (matrice[0][board.rooms[0].link[i]] == 1)
		{
			matrice[0][board.rooms[0].link[i]] = 2;
			matrice[board.rooms[0].link[i]][0] = 2;
			queu[++j] = board.rooms[0].link[i];
		}
	}
	i = -1;
	while (queu[++i])
	{

	}
}