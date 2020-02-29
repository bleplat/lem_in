/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_board_parse_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:35:04 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/29 16:19:12 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li_board.h"
#include "li_link.h"
#include "li_room.h"



/*
** Parse the ant count, rooms and links, from stdin, to a board.
** Return a negative number on error.
** Return a positive number on non-critical error.
*/

int				li_board_parse_input(t_li_board *board)
{
	int		rst;

	if ((rst = li_parse_ants(board)) != 0)
		return (rst);
	if ((rst = li_parse_rooms(board)) != 0)
		return (rst);
	if ((rst = li_parse_links(board)) != 0)
		return (rst);
	return (0);
}
