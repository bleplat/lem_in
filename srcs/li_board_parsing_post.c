/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_board_parsing_post.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:35:38 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/03 16:46:36 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li.h"

void						move_start_first(t_li_board *brd)
{
	t_li_room		swp;

	ft_memcpy(&swp, &brd->rooms[brd->i_room_start], sizeof(t_room));
	ft_memcpy(&brd->rooms[brd->i_room_start], &brd->rooms[0], sizeof(t_room));
	ft_memcpy(&brd->rooms[0], &swp, sizeof(t_room));
	brd->rooms[0].index = 0;
	brd->rooms[brd->i_room_start].index = brd->i_room_start;
	brd->i_room_start = 0;
}

void						move_end_first(t_li_board *brd)
{
	t_li_room		swp;

	ft_memcpy(&swp, &brd->rooms[brd->i_room_end], sizeof(t_room));
	ft_memcpy(&brd->rooms[brd->i_room_end], &brd->rooms[1], sizeof(t_room));
	ft_memcpy(&brd->rooms[1], &swp, sizeof(t_room));
	brd->rooms[1].index = 1;
	brd->rooms[brd->i_room_end].index = brd->i_room_end;
	brd->i_room_end = 1;
}

void						remove_double_links(t_li_board *brd)
{
	(void)brd;
}

/*
** Perform changes on the board's parsed data to make it compliant with what
** the resolve function expet as an input.
*/

void						li_board_parsing_post(t_li_board *board)
{
	move_start_first(board);
	move_end_first(board);
	remove_double_links(board);
}
