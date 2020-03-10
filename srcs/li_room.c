/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_room.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:32:32 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/06 20:12:34 by jthierce         ###   ########.fr       */
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
	if (room->link != NULL)
		ft_free0(room->link);
	room->name = NULL;
	room->x = 0;
	room->y = 0;
	return (0);
}

/*
** Pop the last room in ana array and clean it.
*/

int							li_room_popclean0(t_array *rooms_a)
{
	t_li_room		*room;

	room = (t_li_room*)ft_array_pop(rooms_a);
	if (room)
		li_room_clean0(room);
	return (0);
}

/*
** Tell if a room name is valid.
*/

int							li_room_is_name_valid(const char *name)
{
	if (name[0] == '#' || name[0] == 'L')
		return (0);
	if (!ft_isstrprint(name))
		return (0);
	if (ft_strchr(name, ' '))
		return (0);
	if (ft_strchr(name, '-'))
		return (0);
	if (ft_strchr(name, '\n'))
		return (0);
	return (1);
}

/*
** Dump a room to screen.
*/

void						li_room_dump(t_li_room *room)
{
	int		x;
	int		y;

	ft_printf("{}");
	x = room->x;
	y = room->y;
	ft_printf("  {bold}{orange}%6d: %-8s   (%d; %d){}\n",
				room->index, room->name, x, y);
}
