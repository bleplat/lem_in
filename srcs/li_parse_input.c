/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:35:04 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/04 20:02:49 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

/*
** Update board rooms ans links lists pointers and counts from arrays.
*/

static void	update_links(t_li_board *board, t_array *links_a)
{
	board->links_count = links_a->item_count;
	board->links = links_a->items;
}

static void	update_rooms(t_li_board *board, t_array *rooms_a)
{
	board->rooms_count = rooms_a->item_count;
	board->rooms = rooms_a->items;
}

/*
** Part f the parsing whw we keep reading lines
*/

int			parse_each_line(t_board *board, t_array *rooms_a, t_array *links_a)
{
	int		rst;
	int		rst_room;
	char	*line;

	rst_room = 0;
	while ((rst = ft_readtonl(0, &line, LI_MAXLINELEN)))
	{
		if (li_board_add_output(board, line) < 0)
			return (-1);
		if (li_parsing_should_line_be_ignored(line))
			continue ;
		if (rst_room == 0)
			if ((rst_room = li_parse_room(board, rooms_a, line)) < 0)
				return (li_board_pop_output0(board) + rst_room);
		if (rst_room > 0)
			if ((rst = li_parse_link(board, links_a, line)) != 0)
				return (li_board_pop_output0(board)
						+ ((links_a->item_count) ? rst : rst_room));
	}
	return (rst);
}

/*
** Parse the ant count, rooms and links, from stdin, to a board.
** Return a negative number on error.
** Return a positive number on non-critical error.
*/

int			li_parse_input(t_li_board *board)
{
	int			rst;
	t_array		*rooms_a;
	t_array		*links_a;

	if ((rst = li_parse_ants(board)) != 0)
		return (-ft_abs(rst));
	if (!(rooms_a = ft_array_new(sizeof(t_li_room), 32)))
		return (-1);
	if (!(links_a = ft_array_new(sizeof(t_li_link), 32)))
		return (ft_array_del0(&rooms_a) + -1);
	rst = parse_each_line(board, rooms_a, links_a);
	update_rooms(board, rooms_a);
	update_links(board, links_a);
	ft_free0(rooms_a);
	ft_free0(links_a);
	if (board->links_count <= 0)
		return (-ft_abs(rst ? rst : LI_ERROR_NO_LINKS));
	return (ft_abs(rst));
}
