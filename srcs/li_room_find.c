/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_room_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:15:36 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/01 18:57:22 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li_room.h"

/*
** Find a room in an array of rooms, searching for 'count' items.
** Return the address of the room.
** Return NULL if the room is not found.
*/

t_li_room		*li_room_find(t_room *rooms, int count, const char *name)
{
	int		i_room;

	i_room = count - 1;
	while (i_room >= 0)
	{
		if (rooms[i_room].name)
			if (ft_strcmp(rooms[i_room].name, name) == 0)
				return (rooms + i_room);
		i_room--;
	}
	return (NULL);
}
