/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_start_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:23:05 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/04 19:10:45 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li.h"

/*
** Set index of room start and room end, unless they are already set.
** Return 1 if this was a valid command.
** Return 0 if this wasnt a valid command.
** Return an error code if this was a valid command but it was unexpected.
*/

int		li_parse_start_end(t_li_board *board, char *line)
{
	if (ft_strcmp(line, "##start\n") == 0)
	{
		if (board->i_room_start >= 0)
			return (LI_ERROR_ROOMS_START_CMD);
		board->i_room_start = board->rooms_count;
		return (1);
	}
	if (ft_strcmp(line, "##end\n") == 0)
	{
		if (board->i_room_end >= 0)
			return (LI_ERROR_ROOMS_END_CMD);
		board->i_room_end = board->rooms_count;
		return (1);
	}
	return (0);
}
