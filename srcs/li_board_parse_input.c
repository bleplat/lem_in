/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_board_parse_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:35:04 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/03 17:18:44 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

/*
** Update board rooms ans links lists pointers and counts from arrays.
*/

void	update_lists(t_li_board *board, t_array *rooms_a, t_array *links_a)
{
	board->rooms_count = rooms_a->item_count;
	board->rooms = rooms_a->items;
	board->links_count = links_a->item_count;
	board->links = links_a->items;
}

/*
** Set index of room start and room end, unless they are already set.
** Return 1 if this was a valid command.
** Return 0 if this was a valid command.
** Return -1 if this was a valid command.
** Return
*/

// TODO: check when start and end are lasts
// TODO: use counts directly to not use unstable ints from board ?
int		check_start_end(t_li_board *board, char *line)
{
	if (ft_strcmp(line, "##start\n") == 0)
	{
		if (board->i_room_start >= 0)
			return (LI_ERROR_ROOMS_CMD);
		board->i_room_start = board->rooms_count;
		return (1);
	}
	if (ft_strcmp(line, "##end\n") == 0)
	{
		if (board->i_room_end >= 0)
			return (LI_ERROR_ROOMS_CMD);
		board->i_room_end = board->rooms_count;
		return (1);
	}
	return (0);
}

int		parse_each_line(t_li_board *board, t_array *rooms_a, t_array *links_a)
{
	int		rst;
	int		rst1;
	int		step;
	char	*line;

	// todo: handle start/end via index, then flatten
	step = 0;
	while ((rst = ft_readtonl(0, &line, LI_MAXLINELEN)))
	{
		if (li_board_add_output(board, line) < 0)
			return (-1);
		if (li_parsing_should_line_be_ignored(line))
			continue ;
		if (step == 0)
		{
			if ((rst = check_start_end(board, line)) < 0)
				return (li_board_pop_output0(board) + rst);
			if (rst != 1)
			{
			if ((rst1 = li_parse_room(board, rooms_a, line)) != 0)
				step++;
			}
			else rst = 0;
		}
		update_lists(board, rooms_a, links_a);
		
		if (rst1 < 0)
			return (li_board_pop_output0(board) + rst1);
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

	if ((rst = li_parse_ants(board)) < 0)
	{
		return (rst);
	}
	if (!(rooms_a = ft_array_new(sizeof(t_li_room), 32)))
		return (-1);
	if (!(links_a = ft_array_new(sizeof(t_li_link), 32)))
		return (ft_array_del0(&rooms_a) + -1);
	update_lists(board, rooms_a, links_a);
	rst = parse_each_line(board, rooms_a, links_a);
	update_lists(board, rooms_a, links_a);
	ft_free0(rooms_a);
	ft_free0(links_a);
	if (board->links_count <= 0)
		return (-ft_abs(rst ? rst : LI_ERROR_NO_LINKS));
	if (board->i_room_start < 0 || board->i_room_start >= board->rooms_count)
		return (LI_ERROR_NO_START);
	if (board->i_room_end < 0 || board->i_room_end >= board->rooms_count)
		return (LI_ERROR_NO_END);
	if (board->i_room_start == board->i_room_end)
		return (LI_ERROR_START_IS_END);
	// perform other tests here
	// TODO: check that while reading ?!
	return (rst);
}
// TODO: reorder start and end
