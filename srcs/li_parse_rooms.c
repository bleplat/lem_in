/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:12:04 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/29 16:14:16 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

/*
** Parse a single line representing a room.
*/

int				parse_room(t_li_board *board, t_array *rooms_a, char *line)
{
	t_li_room		*new_room;
	char			*next;

	if (!(new_room = ft_array_newitem(rooms_a)))
		return (-1);
	if (!(next = ft_strchr(line, ' ')))
		return (ft_array_pop0(rooms_a) + LI_ERROR_ROOMS_SYNTAX);
	*next = '\0';
	if (!(new_room->name = ft_strdup(line)))
		return (li_room_popclean0(rooms_a) + -1);
	if (li_room_find(board->rooms, board->rooms_count, new_room->name) != NULL)
		return (li_room_popclean0(rooms_a) + LI_ERROR_ROOMS_DUPLICATE);
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
*/

int				parse_rooms(t_li_board *board)
{
	t_array		*rooms_a;
	int			rst;
	char		*line;
	// TODO: read ##start and ##end

	rooms_a = ft_array_new(sizeof(t_li_room), 32);
	if (!rooms_a)
		return (-1);
	while ((rst = ft_readtonl(&line, LI_MAXLINELEN) > 0))
	{
		if (li_board_add_output(board, line) < 0)
			return (ft_free0(line) + -1);
		if (li_parsing_should_line_be_ignored(line))
			continue ;
		if (parse_room(line) < 0)
			return (ft_free0(*(char**)ft_array_pop(board->output_a)) + -1);
	}
	if (rst < 0)
		return (rst);
	ft_free0(line);
	board->rooms = rooms_a->items;
	board->rooms_count = rooms_a->item_count;
	ft_free0(rooms_a);
	return (0);
}
