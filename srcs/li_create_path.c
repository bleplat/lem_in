/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_create_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 15:00:00 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/06 19:08:01 by jthierce         ###   ########.fr       */
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
			ft_printf("{}+++++++++++++++++++%d et %d\n", board.rooms[i].index, board.rooms[i].status);
			while (board.rooms[i].status == 5 && ++j < board.rooms[i].count_link)
			{
				ft_printf("~~~~~~~~~~~~~~~~%d\n", board.rooms[board.rooms[i].link[j]].index);
				if (matrice[board.rooms[i].index][board.rooms[board.rooms[i].link[j]].index] == 6)
					{
						board.rooms[i].prev = &(board.rooms[board.rooms[i].link[j]]);
						ft_printf("on s'est inflitré\n");
					}
			}
			board.rooms[i].status = 2;
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
	int		i;

	i = -1;
	while (++i < board.rooms[1].count_link)
	{
		if (board.rooms[board.rooms[1].link[i]].status == 2 ||
		board.rooms[board.rooms[1].link[i]].status == 5)
		{
			rooms = &(board.rooms[board.rooms[1].link[i]]);
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
	}
	rooms = &(board.rooms[1]);
	ft_printf("{}jai plus didee de couleur\n");
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
		ft_printf("{}li_calc a renvoyé -2\n");
		li_return_old_version(board, matrice);
		return (-2);
	}
	ft_printf("{}On entre dans li_valide_path_matrice\n");
	li_valide_path_matrice(board, matrice);
	ft_printf("{yellow}YES YOUR GRACE\n");
	return (0);
}
