/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:32:32 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/29 20:13:09 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

/*
** Clean a room.
** As room contains malloced pointers, it is necessary to clean them right.
*/

int							li_room_clean0(t_room *room)
{
	ft_free0((void*)room->name);
	room->name = NULL;
	room->x = 0;
	room->y = 0;
	return (0);
}

/*
** Pop the last room in ana array and clean it.
*/

int								li_room_popclean0(t_array *rooms_a)
{
	t_li_room		*room;

	room = (t_li_room*)ft_array_pop(rooms_a);
	if (room)
		li_room_clean0(room);
	return (0);
}

/*
** Dump a room to screen.
*/

void						li_room_dump(t_li_room *room)
{
	int		x;
	int		y;

	x = room->x;
	y = room->y;
	ft_printf("{orange}room %d: %s (%d; %d){}\n", room->index, room->name, x, y);
}
