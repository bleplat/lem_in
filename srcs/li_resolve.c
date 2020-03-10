/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:54:10 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/06 22:45:56 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

void	li_print_path(t_board board)
{
	t_room *rooms;
	int i;

	i = -1;
	while (++i < board.rooms[1].count_link)
	{
		if (board.rooms[board.rooms[1].link[i]].status == 2)
		{
			rooms = &(board.rooms[board.rooms[1].link[i]]);
			ft_printf("{}|%d|\n", board.rooms[1].link[i]);
			ft_printf("\n{pink}Path :\n%d\n", board.rooms[1].index);
			while (rooms != NULL)
			{
				ft_printf("%d\n", rooms->index);
				rooms = rooms->prev;
			}
		}
	}
	ft_printf("{}");
}

/*
** Return Value:
**
** -1 = malloc fail
** -2 = pas de chemin trouvé
** 1 = Bfs is okay min 1 path is find
** 2 = end is link with start so we can print in one line
*/

int		li_resolve(t_board board)
{
	int		result;
	int		**matrice;

	if ((matrice = li_create_matrice(board.rooms_count)) == NULL)
		return (-1);
	if (li_ini_matrice_link(board, matrice) == -1)
	{
		li_free_matrice(matrice, board.rooms_count);
		return (-1);
	}
	if ((result = li_bfs(board, matrice)) == -1)
	{
		li_free_matrice(matrice, board.rooms_count);
		return (-1);
	}
	if (result == 1)
		li_calc_step(board, 1);
	li_print_matrice(board, matrice);
	if (result != -2)
	{
		ft_printf("ALLO C TOI?\n");
		ft_printf("{}----------------------{blue}\n");
		li_print_path(board);
	}
	li_free_matrice(matrice, board.rooms_count);
	return (result);
}