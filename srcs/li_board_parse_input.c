/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_board_parse_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:35:04 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/28 13:42:19 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li_board.h"
#include "li_link.h"
#include "li_room.h"

//li_parsing_should-line_be_ignored

int				parse_rooms(t_li_board *board)
{
	t_array		*rooms_a;

	rooms_a = ft_array_new(sizeof(t_li_room), 32);
	if (!rooms_a)
		return (-1);



	board->rooms = rooms_a->items;
	board->rooms_count = rooms_a->item_count;
	ft_free0(rooms_a);
	return (0);
}

int				parse_links(t_li_board *board)
{
	t_array		*links_a;

	links_a = ft_array_new(sizeof(t_li_link), 32);
	if (!links_a)
		return (-1);


	board->links = links_a->items;
	board->links_count = links_a->item_count;
	ft_free0(links_a);
	return (0);

}

/*
** Parse the ant count, rooms and links, from stdin, to a board.
** Return a negative number on error.
*/

int				li_board_parse_input(t_li_board *board)
{
	(void)board;
	//t_array		links_a;
	//
	// (ignore comments in all)
	// -> line by line
	//    -> mouse
	// -> line by line (int start/end)
	//    -> rooms
	// -> line by line
	//    -> links
	return (-1);
}
