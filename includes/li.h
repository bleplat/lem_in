/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:11:09 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/06 21:04:22 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_H
# define LI_H

# include "li_board.h"
# include "li_link.h"
# include "li_room.h"

# define LI_MAXLINELEN 32000

/*
** Parsing error codes.
** Negative numbers are critical and abort lem_in
** Positive Numbers are non-critical and represent an error but the data is
** proceceed anyway.
*/

# define LI_ERROR_NOTHING_TO_READ 126
# define LI_ERROR_ANTS_CNT -125
# define LI_ERROR_ROOMS_DUPLICATE -124
# define LI_ERROR_ROOMS_SYNTAX 123
# define LI_ERROR_ROOMS_BAD_X -122
# define LI_ERROR_ROOMS_BAD_Y -121
# define LI_ERROR_ROOMS_BAD_NAME -120
# define LI_ERROR_LINKS_SYNTAX 110
# define LI_ERROR_NO_START -108
# define LI_ERROR_NO_END -107
# define LI_ERROR_START_IS_END -106
# define LI_ERROR_NO_LINKS -105
# define LI_ERROR_ROOMS_START_CMD -103
# define LI_ERROR_ROOMS_END_CMD -102
# define LI_ERROR_LINKS_ROOM_DO_NOT_EXIST 101

# define LI_NEXTSTEP 16

# define LI_CMD_START "##start\n"
# define LI_CMD_END "##end\n"

int				li_parsing_should_line_be_ignored(char *line);

int				li_perror(int code, const char *message);
void			li_print_input(t_li_board *board);
void			li_print_result(t_li_board *board);

int				li_parse_ants(t_li_board *b);
int				li_parse_room(t_li_board *b, t_array *rooms_a, char *line);
int				li_parse_link(t_li_board *b, t_array *links_a, char *line);
int				li_parse_start_end(t_li_board *b, char *line);

int				li_resolve(t_board board);

#endif
