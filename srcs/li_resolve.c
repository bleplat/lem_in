/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:54:10 by jthierce          #+#    #+#             */
/*   Updated: 2020/04/24 15:31:44 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

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
	if (result == 1 || result == -1)
		li_calc_step(board, 1);
	li_free_matrice(matrice, board.rooms_count);
	return (result);
}
