/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:20:19 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/28 15:21:53 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int				parse_link(t_li_board *board, t_array *links_a, char *line)
{

}

/*
** Parse links from input until it's no longer possible.
*/

int				parse_links(t_li_board *board)
{
	t_array		*links_a;
	int			rst;
	char		*line;

	links_a = ft_array_new(sizeof(t_li_link), 32);
	if (!links_a)
		return (-1);
	while ((rst = ft_readtonl(&line, LI_MAXLINELEN) > 0))
	{
		if (li_board_add_output(board, line) < 0)
			return (ft_free0(line) + -1);
		if (li_parsing_should_line_be_ignored(line))
			continue ;
		if (parse_link(line) < 0)
			return (ft_free0(*(char**)ft_array_pop(board->output_a)) + -1);
	}
	board->links = links_a->items;
	board->links_count = links_a->item_count;
	ft_free0(links_a);
	return (0);
}
