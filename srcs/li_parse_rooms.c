/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:12:04 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/28 15:19:41 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				parse_room(t_li_board *board, t_array *rooms_a, char *line)
{

}

/*
** Parse rooms from input until it's no longer possible.
*/

int				parse_rooms(t_li_board *board)
{
	t_array		*rooms_a;
	int			rst;
	char		*line;
	// TODO: read ##start and ##end

	rooms_a = ft_array_new(sizeof(t_li_room), 32);
	if (!rooms_a)
		return (-1);
	while ((rst = ft_readtonl(&line, LI_MAXLINELEN) > 0))
	{
		if (li_board_add_output(board, line) < 0)
			return (ft_free0(line) + -1);
		if (li_parsing_should_line_be_ignored(line))
			continue ;
		if (parse_roon(line) < 0)
			return (ft_free0(*(char**)ft_array_pop(board->output_a)) + -1);
	}
	if (rst < 0)
		return (rst);
	ft_free0(line);
	board->rooms = rooms_a->items;
	board->rooms_count = rooms_a->item_count;
	ft_free0(rooms_a);
	return (0);
}
