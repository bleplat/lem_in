/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_room.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:12:04 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/06 19:31:39 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

static void		update_rooms(t_li_board *board, t_array *rooms_a)
{
	board->rooms_count = rooms_a->item_count;
	board->rooms = rooms_a->items;
}

static int		just_parse_room(t_array *rooms_a, char *line)
{
	t_li_room		*new_room;
	char			*next;

	if (!(next = ft_strchr(line, ' ')))
		return (LI_ERROR_ROOMS_SYNTAX);
	if (!(new_room = ft_array_newitem(rooms_a)))
		return (-1);
	new_room->index = rooms_a->item_count - 1;
	*next = '\0';
	if (li_room_find(rooms_a->items, rooms_a->item_count, line) != NULL)
		return (li_room_popclean0(rooms_a) + LI_ERROR_ROOMS_DUPLICATE);
	if (!li_room_is_name_valid(line))
		return (li_room_popclean0(rooms_a) + LI_ERROR_ROOMS_BAD_NAME);
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
}

/*
** Parse a single line representing a room (or a room command).
**
** Return 0 on success or when a line was a comment.
** Return a negative int on critical error (wich abort parsing).
** Return a positive int on other error (parsing should continue on links).
**
** Perform additional checks on non-critical error, and reorganize the rooms,
** wich may cause the return of critical errors.
*/

int				li_parse_room(t_li_board *board, t_array *rooms_a, char *line)
{
	int		rst;
	int		rst_final;

	update_rooms(board, rooms_a);
	if ((rst = li_parse_start_end(board, line)) < 0)
		return (rst);
	if (rst > 0)
		return (0);
	if ((rst = just_parse_room(rooms_a, line)) < 0)
		return (rst);
	update_rooms(board, rooms_a);
	if (rst > 0)
		if ((rst_final = li_parsing_finalize_rooms(board)) < 0)
			return (rst_final);
	return (rst);
}
