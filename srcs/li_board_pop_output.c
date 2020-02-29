/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_board_pop_output.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:42:37 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/29 17:06:13 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_board.h"

/*
** Remove AND FREE the last input added to the board's list.
** Return 0.
*/

int							li_board_pop_output0(t_li_board *b)
{
	char		**str_p;

	str_p = (char**)ft_array_pop(b->output_a);
	if (str_p)
		ft_free0(*str_p);
	return (0);
}
