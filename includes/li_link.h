/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_link.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:57:37 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/27 19:13:49 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINK_H
# define FT_LINK_H

# include "li_room.h"

/*
** t_li_link
**
** Represent a link between two rooms (here called 'a' and 'b').
*/

typedef struct s_li_link	t_li_link;
typedef t_li_link			t_link;
struct						s_li_link
{
	int			i_room_a;
	int			i_room_b;
	t_li_room	*p_room_a;
	t_li_room	*p_room_b;
};

int							li_link_make(t_li_link *out,
											t_board *brd, char *r1, char *r2);


#endif
