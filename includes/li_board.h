/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_board.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:11:57 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/27 17:10:09 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_BOARD_H
# define LI_BOARD_H

# include "li_room.h"
# include "li_link.h"

/*
** t_li_board
**
** Used to store and pass data wich is used by the entire program.
** This represent input after they have been parsed.
*/

typedef struct s_li_board		t_li_board;
typedef t_li_board				t_board;
struct							s_li_board
{
	int				options;
	t_li_room		*rooms;
	int				rooms_count;
	t_li_link		*links;
	int				links_count;
};

#endif
