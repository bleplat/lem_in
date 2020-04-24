/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_begin_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:43:42 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/12 20:18:49 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

/*
** Check if an int in 'choices' from indices a to b is equal to b.
** This is used to know when to stop sending ants (1 ant in a room per turn).
*/

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

void			reset_first_rooms(t_array *pathes_a)
{
	int		i_path;
	t_array	*path;
	t_room	*first;

	i_path = 0;
	while (i_path < pathes_a->item_count)
	{
		path = *(void**)ft_array_at(pathes_a, i_path);
		first = *(t_room**)ft_array_at(path, path->item_count - 2);
		first->i_ant = -1;
		i_path++;
	}
}

void			set_ants_as_gone(int a, int b, int *choices)
{
	b--;
	while (b >= a)
	{
		choices[b] = -1;
		b--;
	}
}

/*
** Send ants at the begin of the pathes.
** This is requiered to put ants on their path.
*/

int				li_begin_ants(t_board *brd, t_array *pathes_a, int *choices,
							int *is_first_ant)
{
	int		rst;
	int		a;
	int		b;
	t_array	*path;
	t_room	*first;

	rst = 0;
	reset_first_rooms(pathes_a);
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
	set_ants_as_gone(a, b, choices);
	return (rst);
}
