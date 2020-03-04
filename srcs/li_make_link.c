/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_make_link.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 18:57:24 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/03 22:22:36 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

/*
** Make a link between two rooms.
** Return 0 on success.
** Return a negative int on error.
*/

int			li_make_link(t_li_link *out, t_li_board *brd, char *r1, char *r2)
{
	if (out == NULL)
		return (-40);
	out->p_room_a = li_room_find(brd->rooms, brd->rooms_count, r1);
	out->p_room_b = li_room_find(brd->rooms, brd->rooms_count, r2);
	if (!out->p_room_a || !out->p_room_b)
		return (LI_ERROR_LINKS_ROOM_DO_NOT_EXIST);
	if (out->p_room_a > out->p_room_b)
		ft_swapptr((void**)&(out->p_room_a), (void**)&(out->p_room_b));
	out->i_room_a = out->p_room_a->index;
	out->i_room_b = out->p_room_b->index;
	return (0);
}
