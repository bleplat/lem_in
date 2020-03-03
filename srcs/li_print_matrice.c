/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print_matrice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:41:38 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/03 16:42:15 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

void	li_print_matrice(t_board board, int **matrice)
{
	int i;

	i = -1;
	ft_printf("{red}          ");
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
