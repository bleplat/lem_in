/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_board.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:11:57 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/28 15:26:15 by bleplat          ###   ########.fr       */
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

typedef struct s_li_board	t_li_board;
typedef t_li_board			t_board;
struct						s_li_board
{
	int				options;
	t_array			*output_a;
	int				ants_count;
	t_li_room		*rooms;
	int				rooms_count;
	t_li_link		*links;
	int				links_count;
};

/*
** A t_li_board must be created and destroyed properly before use.
*/

t_li_board					*li_board_create(void);
int							li_board_parse_input(t_li_board *b);
void						li_board_destroy(t_li_board **b);

int							li_parse_ants(t_li_board *b);
int							li_parse_rooms(t_li_board *b);
int							li_parse_links(t_li_board *b);

char						*li_parsing_nextline(t_li_board *b);

/*
** Helpers
*/

int							li_board_add_output(t_li_board *b, const char *l);
int							li_make_link(t_li_link *out,
											t_board *brd, char *r1, char *r2);

#endif
