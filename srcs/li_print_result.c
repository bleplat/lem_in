/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:43:42 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/10 01:08:55 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

int			print_move(int i_ant, t_room *dst)
{
	if (i_ant < 0)
		return (0);
	ft_putchar('L');
	ft_putnbr(i_ant);
	ft_putchar('-');
	ft_putstr(dst->name);
	ft_putchar(' ');
	return (1);
}

int				move_ants_on_path(t_array *rooms_a)
{
	int		rst;
	t_room	*room_e;
	t_room	*room_s;
	int		i_room_s;

	rst = 0;
	room_e = ft_array_at(rooms_a, 0);
	i_room_s = 1;
	while (i_room_s < rooms_a->item_count - 2)
	{
		room_s = ft_array_at(rooms_a, i_room_s);
		room_e->i_ant = room_s->i_ant;
		rst |= print_move(room_e->i_ant, room_e);
		room_e = room_s;
	}
	return (rst);
}
int				move_ants_on_pathes(t_array *pathes_a)
{
	int			rst;
	int			i_path;
	t_array		*path;

	rst = 0;
	i_path = 0;
	while (i_path < pathes_a->item_count)
	{
		path = *(void**)ft_array_at(pathes_a, i_path);
		rst |= move_ants_on_path(path);
		i_path++;
	}
	return (rst);
}


int				not_done(int a, int b, int *choices)
{
	while (a < b)
	{
		if (choices[a] == choices[b])
			return (1);
		a++;
	}
	return (0);
}
int				begin_ants(t_board *brd, t_array *pathes_a, int *choices)
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
		first = ft_array_at(path, path->item_count - 2);
		first->i_ant = -1;
		a++;
	}
	//
	a = 0;
	while (a < brd->ants_count && choices[a] < 0)
		a++;
	b = a;
	while (b < brd->ants_count && not_done(a, b, choices))
	{
		path = *(void**)ft_array_at(pathes_a, choices[b]);
		first = ft_array_at(path, path->item_count - 2);
		first->i_ant = b;
		rst |= print_move(b, first);
		b++;
	}
	b--;
	while (b >= a)
	{
		b--;
		choices[b] = -1;
	}
	return (rst);
}

/*
** At this stage we count the lines on the zebra.
*/

void			zebra(t_board *board, t_array *pathes_a, int *choices)
{
	int		running_ants;
	int		keep_running;

	running_ants = 0;
	keep_running = 3443;
	while (keep_running)
	{
		keep_running = 0;
		keep_running |= move_ants_on_pathes(pathes_a);
		keep_running |= begin_ants(board, pathes_a, choices);
		ft_putchar('\n');
	}
}

/*
** That's a big animal.
*/

void			elephant(t_board *board, t_array *pathes_a)
{
	int		*choices;

	if (!(choices = li_ant_choices_create(board, pathes_a)))
		return ;
	zebra(board, pathes_a, choices);
	ft_free0(choices);
}

/*
** proceed the final output of the ants moves.
*/

void			li_print_result(t_li_board *board)
{
	(void)board;
	t_array			*pathes_a;

	if (!(pathes_a = li_pathes_create(board)))
		return ;
	elephant(board, pathes_a);
	li_pathes_destroy(&pathes_a);
}
