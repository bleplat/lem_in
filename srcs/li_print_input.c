/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:33:19 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/28 14:37:17 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li.h"

/*
** Print the content of board->output_a wich is supposed to have aquiered data
** from the input, but have to be reprinted as output before showing
** the results.
*/

void						li_print_input(t_li_board *board)
{
	int		i;

	i = 0;
	while (i < board->output_a->item_count)
	{
		ft_putstr((char*)*ft_array_at(board->output_a, i));
	}
}
