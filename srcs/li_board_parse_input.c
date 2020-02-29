/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_board_parse_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:35:04 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/29 20:28:46 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

void	update_lists(t_li_board *board, t_array *rooms_a, t_array *links_a)
{
	board->rooms_count = rooms_a->item_count;
	board->rooms = rooms_a->items;
	board->links_count = links_a->item_count;
	board->links = links_a->items;
}

int		parse_each_line(t_li_board *board, t_array *rooms_a, t_array *links_a)
{
	int		rst;
	int		rst1;
	int		step;
	char	*line;

	// todo: handle start/end via index, then flatten
	if ((rst = li_parse_ants(board)) < 0)
		return (rst);
	step = 0;
	while ((rst = ft_readtonl(0, &line, LI_MAXLINELEN)))
	{
		if (li_board_add_output(board, line) < 0)
			return (-1);
		if (li_parsing_should_line_be_ignored(line))
			continue ;
		if (step == 0)
			if ((rst1 = li_parse_room(board, rooms_a, line)) != 0)
				step++;
		if (rst1 < 0)
			return (rst1);
		update_lists(board, rooms_a, links_a);
		if (step == 1)
			if ((rst = li_parse_link(board, links_a, line)) != 0)
				return (li_board_pop_output0(board)
						+ ((links_a->item_count) ? rst : rst1));
	}
	return (rst);
}

/*
** Parse the ant count, rooms and links, from stdin, to a board.
** Return a negative number on error.
** Return a positive number on non-critical error.
*/

int		li_board_parse_input(t_li_board *board)
{
	int			rst;
	t_array		*rooms_a;
	t_array		*links_a;

	if (!(rooms_a = ft_array_new(sizeof(t_li_room), 32)))
		return (-1);
	if (!(links_a = ft_array_new(sizeof(t_li_link), 32)))
		return (ft_array_del0(&rooms_a) + -1);
	rst = parse_each_line(board, rooms_a, links_a);
	board->rooms_count = rooms_a->item_count;
	board->rooms = rooms_a->items;
	ft_free0(rooms_a);
	board->links_count = links_a->item_count;
	board->links = links_a->items;
	ft_free0(links_a);
	if (board->links_count <= 0)
		return (-ft_abs(rst));
	// perform other tests here
	
	return (ft_abs(rst));
}
// TODO: verify room names (yet not verified)
// TODO: reorder start and end
