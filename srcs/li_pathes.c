/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_pathes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:43:42 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/05 20:48:54 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

/*
** Destroy an array of pathes (wich are arrays of rooms).
** Also destroy each individual path.
*/

void		li_pathes_destroy(t_array **pathes_a)
{
	int		i_path;

	i_path = 0;
	while (i_path < (*pathes_a)->item_count)
	{
		ft_array_del(ft_array_at(*pathes_a, i_path));
		i_path++;
	}
	ft_array_del(pathes_a);
}

/*
** Create single path for a room connected to end.
*/

t_array		*create_path_from_end(t_li_board *brd, t_li_room *room)
{
	t_array		*rooms_a;
	t_room		**new_item;

	if (!(rooms_a = ft_array_new(sizeof(t_room*), 12)))
		return (NULL);
	if (!(new_item = ft_array_newitem(rooms_a)))
		return (NULL);
	*new_item = &brd->rooms[1];
	while (room != NULL)
	{
		if (!(new_item = ft_array_newitem(rooms_a)))
			return (NULL);
		*new_item = room;
		room = room->prev;
	}
	return (rooms_a);
}

/*
** Add pathes 1 by 1
*/

int			push_pathes(t_li_board *board, t_array *pathes_a)
{
	int		i_room;
	t_room	*end_room;
	t_room	*room;
	t_array	**new_path;

	end_room = &board->rooms[1];
	i_room = 0;
	while (i_room < end_room->count_link)
	{
		room = &board->rooms[end_room->link[i_room]];
		if (room->status == LI_STATUS_IN_PATH)
		{
			if (!(new_path = ft_array_newitem(pathes_a)))
				return (-1);
			if (!((*new_path) = create_path_from_end(board, room)))
				return (-1);
		}
		i_room++;
	}
	return (0);
}

/*
** Fill the path array
** return a p(rooms_a)_a
** (an array of pointers to arrays of rooms)
** (an array of room is a path)
*/

t_array		*li_pathes_create(t_li_board *board)
{
	t_array	*to_return;

	if (!(to_return = ft_array_new(sizeof(t_array*), 8)))
		return (NULL);
	if (push_pathes(board, to_return) < 0)
	{
		li_pathes_destroy(&to_return);
		return (NULL);
	}
	return (to_return);
}
