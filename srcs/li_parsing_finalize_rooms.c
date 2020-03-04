/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_board_parsing_post.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:35:38 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/04 17:11:11 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li.h"

static void				move_start_first(t_li_board *brd)
{
	t_li_room		swp;

	ft_memcpy(&swp, &brd->rooms[brd->i_room_start], sizeof(t_room));
	ft_memcpy(&brd->rooms[brd->i_room_start], &brd->rooms[0], sizeof(t_room));
	ft_memcpy(&brd->rooms[0], &swp, sizeof(t_room));
	brd->rooms[0].index = 0;
	brd->rooms[brd->i_room_start].index = brd->i_room_start;
	brd->i_room_start = 0;
}

static void				move_end_first(t_li_board *brd)
{
	t_li_room		swp;

	ft_memcpy(&swp, &brd->rooms[brd->i_room_end], sizeof(t_room));
	ft_memcpy(&brd->rooms[brd->i_room_end], &brd->rooms[1], sizeof(t_room));
	ft_memcpy(&brd->rooms[1], &swp, sizeof(t_room));
	brd->rooms[1].index = 1;
	brd->rooms[brd->i_room_end].index = brd->i_room_end;
	brd->i_room_end = 1;
}

/*
** Perform changes on the board's parsed data to make it compliant with what
** the resolve function expet as an input.
** Return 0 if everything went right.
** Return an error if the data is not correct.
*/

int						li_parsing_finalize_rooms(t_li_board *board)
{
	if (board->i_room_start < 0 || board->i_room_start >= board->rooms_count)
		return (LI_ERROR_NO_START);
	if (board->i_room_end < 0 || board->i_room_end >= board->rooms_count)
		return (LI_ERROR_NO_END);
	if (board->i_room_start == board->i_room_end)
		return (LI_ERROR_START_IS_END);
	move_start_first(board);
	move_end_first(board);
	return (0);
}
