/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_link.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:57:37 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/27 17:09:42 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINK_H
# define FT_LINK_H

/*
** t_li_link
**
** Represent a link between two rooms (here called 'a' and 'b').
*/

typedef struct s_li_link				t_li_link;
typedef t_li_link						t_link;
struct									s_li_link
{
	int			i_room_a;
	int			i_room_b;
	t_li_room	*p_room_a;
	t_li_room	*p_room_b;
};

#endif
