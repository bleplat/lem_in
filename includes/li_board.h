/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_board.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:11:57 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/27 18:36:39 by bleplat          ###   ########.fr       */
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
	int				ants_count;
	t_li_room		*rooms;
	int				rooms_count;
	t_li_link		*links;
	int				links_count;
};

/*
** A t_li_board must be created and destroyed properly before use.
*/

t_li_board						li_board_create(void);
void							li_board_destroy(t_li_board *b);
int								li_board_parse_input(t_li_board *b);

#endif
