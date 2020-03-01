/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:41:19 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/01 20:10:06 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

/*
** Dump a link to the screen.
*/

void						li_link_dump(t_li_link *link)
{
	t_li_room *ra;
	t_li_room *rb;

	ft_printf("{}");
	ra = link->p_room_a;
	rb = link->p_room_b;
	if (link->i_room_a != ra->index)
		ft_printf("/!\\{underline}{red} room index %d incorrect\n", ra->index);
	if (link->i_room_b != rb->index)
		ft_printf("/!\\{underline}{red} room index %d incorrect\n", rb->index);
	ft_printf("{lime}{bold}%8s (%d) <-> (%d) %-8s{}\n",
				ra->name, ra->index, rb->index, rb->name);
}
