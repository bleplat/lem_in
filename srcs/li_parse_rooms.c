/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:12:04 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/01 18:26:43 by bleplat          ###   ########.fr       */
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

	(void)board; // rmove this and board ?
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
