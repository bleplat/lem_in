/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:26:29 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/04 19:12:26 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "li_board.h"
#include "li_room.h"
#include "li_link.h"

/*
** Return a t_li_board struct initialized zith default values.
** The structure needs to be cleaned by the destroy function.
*/

t_li_board				*li_board_create(void)
{
	t_li_board		*to_return;

	if (!(to_return = malloc(sizeof(t_li_board))))
		return (NULL);
	to_return->options = 0;
	to_return->ants_count = -888;
	to_return->rooms = NULL;
	to_return->rooms_count = -777;
	to_return->i_room_start = -666;
	to_return->i_room_end = -555;
	to_return->links = NULL;
	to_return->links_count = -444;
	if (!(to_return->output_a = ft_array_new(sizeof(const char*), 32)))
		return (ft_freen(to_return));
	return (to_return);
}

/*
** Clean all rooms in a list.
*/

void					clean_rooms_in_list(t_li_room *rooms, int cnt)
{
	int i;

	i = 0;
	while (i < cnt)
	{
		li_room_clean0(&rooms[i]);
		i++;
	}
}

/*
** Clean a t_li_board struct.
*/

void					li_board_destroy(t_li_board **board)
{
	int		i;

	if (!(*board))
		return ;
	if ((*board)->rooms)
	{
		clean_rooms_in_list((*board)->rooms, (*board)->rooms_count);
		ft_free0((*board)->rooms);
	}
	if ((*board)->links)
		ft_free0((*board)->links);
	if ((*board)->output_a)
	{
		i = 0;
		while (i < (*board)->output_a->item_count)
		{
			free(*(char**)(ft_array_at((*board)->output_a, i)));
			i++;
		}
		ft_array_del(&((*board)->output_a));
	}
	free(*board);
	*board = NULL;
}

/*
** Dump the board to screen.
*/

void					li_board_dump(t_li_board *board)
{
	int		i;

	ft_printf("\n  {bold}{underline}{light white}BOARD DUMP: {}\n\n");
	ft_printf("  {blue}board->options == %d\n{}", board->options);
	ft_printf("  {light cyan}board->ants_count == %d\n", board->ants_count);
	ft_printf("  {dim}{orange}board->rooms_count == %d\n", board->rooms_count);
	i = 0;
	while (i < board->rooms_count)
	{
		li_room_dump(&board->rooms[i]);
		i++;
	}
	ft_printf("  {maroon}board->i_room_start == %d\n", board->i_room_start);
	ft_printf("  {maroon}board->i_room_end == %d\n", board->i_room_end);
	ft_printf("  {green}board->links_count == %d\n", board->links_count);
	i = 0;
	while (i < board->links_count)
	{
		li_link_dump(&board->links[i]);
		i++;
	}
	ft_printf("  {}\n");
}
