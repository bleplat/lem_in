/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 13:54:10 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/01 19:32:01 by jthierce         ###   ########.fr       */
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

static void	li_print_matrice(t_board board, int **matrice)
{
	int i;

	i = -1;
	ft_printf("          ");
	while (++i < board.rooms_count)
		ft_printf("%-2d ", i);
	ft_putchar('\n');
	i = -1;
	while (++i < board.rooms_count)
	{
		ft_printf("{yellow}matrice = {green}");
		ft_putints(matrice[i], board.rooms_count, "  ");
		ft_printf("   {blue}%d\n", i);
	}
}

int		li_resolve(t_board board)
{
	int		**matrice;
	int		result;

	ft_printf("{}{red}");
	if ((matrice = li_create_matrice(board.rooms_count)) == NULL)
		return (-1);
	if (li_ini_matrice_link(board, matrice) == -1)
	{
		li_free_matrice(matrice, board.rooms_count);
		return (-1);
	}
	li_print_matrice(board, matrice);
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
	return (result);
}