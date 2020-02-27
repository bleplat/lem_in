/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:26:29 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/27 19:32:51 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_board.h"
#include "li_room.h"
#include "li_link.h"

/*
** Return a t_li_board struct initialized zith default values.
** The structure needs to be cleaned by the destroy function.
*/

t_li_board					li_board_create(void)
{
	t_li_board		to_return;

	to_return.options = 0;
	to_return.rooms = NULL;
	to_return.rooms_count = 0;
	to_return.links = NULL;
	to_return.links_count = 0;
	return (to_return);
}

/*
** Clean a t_li_board struct.
*/

void						li_board_destroy(t_li_board *board)
{
	if (board->rooms)
		ft_free0(board->rooms);
	if (board->links)
		ft_free0(board->links);
	*board = li_board_create();
}
