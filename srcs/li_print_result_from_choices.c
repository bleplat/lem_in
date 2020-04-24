/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:43:42 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/12 20:18:49 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

int				move_ants_on_path(t_array *rooms_a,
							int *is_first_ant)
{
	int		rst;
	t_room	*room_e;
	t_room	*room_s;
	int		i_room_s;

	rst = 0;
	room_e = *(t_room**)ft_array_at(rooms_a, 0);
	i_room_s = 1;
	while (i_room_s <= rooms_a->item_count - 2)
	{
		room_s = *(t_room**)ft_array_at(rooms_a, i_room_s);
		room_e->i_ant = room_s->i_ant;
		rst |= li_print_move(room_e->i_ant, room_e, is_first_ant);
		room_e = room_s;
		i_room_s++;
	}
	return (rst);
}

int				move_ants_on_pathes(t_array *pathes_a,
							int *is_first_ant)
{
	int			rst;
	int			i_path;
	t_array		*path;

	rst = 0;
	i_path = 0;
	while (i_path < pathes_a->item_count)
	{
		path = *(void**)ft_array_at(pathes_a, i_path);
		rst |= move_ants_on_path(path, is_first_ant);
		i_path++;
	}
	return (rst);
}

int				not_done(int a, int b, int *choices)
{
	while (a < b)
	{
		if (choices[a] == choices[b])
			return (0);
		a++;
	}
	return (1);
}

int				begin_ants(t_board *brd, t_array *pathes_a, int *choices,
							int *is_first_ant)
{
	int		rst;
	int		a;
	int		b;
	t_array	*path;
	t_room	*first;

	rst = 0;
	// todo: set all first room in pathes at 0;
	a = 0;
	while (a < pathes_a->item_count)
	{
		path = *(void**)ft_array_at(pathes_a, a);
		first = *(t_room**)ft_array_at(path, path->item_count - 2);
		first->i_ant = -1;
		a++;
	}
	a = 0;
	while (a < brd->ants_count && choices[a] < 0)
		a++;
	b = a;
	while (b < brd->ants_count && not_done(a, b, choices))
	{
		path = *(void**)ft_array_at(pathes_a, choices[b]);
		first = *(t_room**)ft_array_at(path, path->item_count - 2);
		first->i_ant = b;
		rst |= li_print_move(b, first, is_first_ant);
		b++;
	}
	b--;
	while (b >= a)
	{
		choices[b] = -1;
		b--;
	}
	return (rst);
}

/*
** Finaly moving ants according to their choice.
*/

void			li_print_result_from_choices(t_board *board, t_array *pathes_a,
												int *choices)
{
	int		keep_running;
	int		is_first_ant;

	keep_running = 3443;
	while (keep_running)
	{
		if (keep_running != 3443)
			ft_putchar('\n');
		keep_running = 0;
		is_first_ant = 1;
		keep_running |= move_ants_on_pathes(pathes_a, &is_first_ant);
		keep_running |= begin_ants(board, pathes_a, choices, &is_first_ant);
	}
}
