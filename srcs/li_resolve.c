/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:54:10 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/27 19:02:17 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

int		li_resolve(t_board board)
{
	int		**matrice;

	if ((matrice = li_create_matrice(board.rooms_count)) == -1)
		return (-1);
	if (li_ini_matrice_link(board, matrice) == -1)
	{
		li_free_matrice(matrice, board.rooms_count);
		return (-1);
	}
}