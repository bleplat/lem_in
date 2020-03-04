/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:54:10 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/04 15:19:01 by jthierce         ###   ########.fr       */
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
	int		**matrice;
	int		result;

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
	if (result != 2)
		ft_printf("{orange}%d\n", li_calc_step(board, 1));
	li_print_matrice(board, matrice);
	ft_printf("{}----------------------{blue}\n");
	return (result);
}