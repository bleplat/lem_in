/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_ants.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 16:38:32 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/04 19:09:17 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

int					li_parse_ants(t_li_board *board)
{
	int			rst;
	char		*line;

	while ((rst = ft_readtonl(0, &line, LI_MAXLINELEN) > 0))
	{
		if (li_board_add_output(board, line) < 0)
			return (ft_free0(line) + -1);
		if (li_parsing_should_line_be_ignored(line))
			continue ;
		if ((rst = ft_atoi32checkc(&board->ants_count, line, '\n')) < 0)
			return (li_board_pop_output0(board) + rst);
		if (board->ants_count <= 0)
			return (li_board_pop_output0(board) + LI_ERROR_ANTS_CNT);
		return (0);
	}
	if (rst == 0)
		return (-1);
	return (rst);
}
