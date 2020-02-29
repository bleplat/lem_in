/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:12:04 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/29 20:01:42 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

/*
** Parse a single line representing a room.
*/

int				li_parse_room(t_li_board *board, t_array *rooms_a, char *line)
{
	t_li_room		*new_room;
	char			*next;

	if (!(next = ft_strchr(line, ' ')))
		return (LI_ERROR_ROOMS_SYNTAX);
	if (!(new_room = ft_array_newitem(rooms_a)))
		return (-1);
	*next = '\0';
	if (li_room_find(board->rooms, board->rooms_count, line) != NULL)
		return (li_room_popclean0(rooms_a) + LI_ERROR_ROOMS_DUPLICATE);
	if (!(new_room->name = ft_strdup(line)))
		return (li_room_popclean0(rooms_a) + -1);
	*next = ' ';
	line = next + 1;
	if (ft_atoi32checkc(&new_room->x, line, ' ') < 0)
		return (li_room_popclean0(rooms_a) + LI_ERROR_ROOMS_BAD_X);
	line = ft_strchr(line, ' ') + 1;
	if (ft_atoi32checkc(&new_room->y, line, '\n') < 0)
		return (li_room_popclean0(rooms_a) + LI_ERROR_ROOMS_BAD_Y);
	return (0);
} // TODO: clean rooms properly


/*
** Parse rooms from input until it's no longer possible.
** Output to rooms_a.
*/

//TODO: delete
int				parse_each_rooms(t_li_board *board, t_array *rooms_a)
{
	int			rst;
	char		*line;
	// TODO: read ##start and ##end

	while ((rst = ft_readtonl(0, &line, LI_MAXLINELEN) > 0))
	{
		if (li_board_add_output(board, line) < 0)
			return (ft_free0(line) + -1);
		if (li_parsing_should_line_be_ignored(line))
			continue ;
		if (!ft_strcmp(line, "##start\n") || !ft_strcmp(line, "##end\n"))
			continue ;
		if (li_parse_room(board, rooms_a, line) < 0)
			return (ft_free0(*(char**)ft_array_pop(board->output_a)) + -1);
	}
	if (rst == 0)
		return (LI_ERROR_NOTHING_TO_READ);
	return (rst);
}

/*
** Parse rooms from input until it's no longer possible.
** Output to board.
*/

//TODO: delete
int				li_parse_rooms(t_li_board *board)
{
	int			rst;
	t_array		*rooms_a;

	rooms_a = ft_array_new(sizeof(t_li_room), 32);
	if (!rooms_a)
		return (-1);
	rst = parse_each_rooms(board, rooms_a);
	board->rooms = rooms_a->items;
	board->rooms_count = rooms_a->item_count;
	ft_free0(rooms_a);
	return (rst);
}
