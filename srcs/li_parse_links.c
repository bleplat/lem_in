/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_parse_links.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 15:20:19 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/29 20:27:56 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

/*
** Parse a single link from a line.
*/

int				li_parse_link(t_li_board *board, t_array *links_a, char *line)
{
	t_li_link	*new_link;
	char		*stick;
	char		*nl;

	if (!(stick = ft_strchr(line, '-')))
		return (LI_ERROR_LINKS_SYNTAX);
	if (!(nl = ft_strchr(stick, '\n')))
		return (LI_ERROR_LINKS_SYNTAX);
	*stick = '\0';
	*nl = '\0';
	if (!(new_link = ft_array_newitem(links_a)))
		return (-1);
	if (li_make_link(new_link, board, line, stick + 1) < 0)
		return (ft_array_pop0(links_a));
	*stick = '-';
	*nl = '\n';
	return (0);
}

/*
** Parse links from input until it's no longer possible.
** Output to links_a.
*/

//TODO: delete
int				parse_each_links(t_li_board *board, t_array *links_a)
{
	int			rst;
	char		*line;

	while ((rst = ft_readtonl(0, &line, LI_MAXLINELEN) > 0))
	{
		if (li_board_add_output(board, line) < 0)
			return (ft_free0(line) + -1);
		if (li_parsing_should_line_be_ignored(line))
			continue ;
		if ((rst = li_parse_link(board, links_a, line)) != 0)
			return (ft_free0(*(char**)ft_array_pop(board->output_a)) + rst);
	}
	return (rst);
}

/*
** Parse links from input until it's no longer possible.
** Output to board.
*/

//TODO: delete
int				li_parse_links(t_li_board *board)
{
	int			rst;
	t_array		*links_a;

	links_a = ft_array_new(sizeof(t_li_link), 32);
	if (!links_a)
		return (-1);
	rst = parse_each_links(board, links_a);
	board->links = links_a->items;
	board->links_count = links_a->item_count;
	ft_free0(links_a);
	return (rst);
}
// TODO: check why input have to be closed twice zhen invalid mouse count
