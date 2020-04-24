/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print_singleround_result.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:45:14 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/12 20:17:35 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li.h"

/*
** Display the result when start and end are connected.
*/

int				li_print_singleround_result(t_li_board *brd)
{
	int		i_mouse;

	i_mouse = 1;
	while (i_mouse <= brd->ants_count)
	{
		if (i_mouse != 1)
			ft_putchar(' ');
		ft_putstr("L");
		ft_putnbr(i_mouse);
		ft_putstr("-");
		ft_putstr(brd->rooms[1].name);
		i_mouse++;
	}
	ft_putchar('\n');
	return (0);
}
