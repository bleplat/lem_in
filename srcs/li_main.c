/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:45:14 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/03 16:46:14 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li.h"

/*
** Main, resolve lem_in.
** Return a negative int on error.
*/

int		main_resolve(t_li_board *board)
{
	(void)board;
	// TODO: Resolve lem_in.
	return (0);
}

/*
** Main, parse input then resolve.
** Return a negative int on error.
*/

int		main_parse_resolve(t_li_board *board)
{
	int		rst;

	if ((rst = li_board_parse_input(board)) < 0)
		return (rst);
	li_board_parsing_post(board);
	if ((rst = main_resolve(board)) < 0)
		return (rst);
	return (0);
}

/*
** Main, create the empty base board.
*/

int		main(int argc, char **argv)
{
	int			rst;
	t_li_board	*board;

	(void)argc;
	(void)argv;
	if (!(board = li_board_create()))
		return (ft_abs(li_perror(-1, NULL)));
	if ((rst = main_parse_resolve(board)) < 0)
	{
		li_board_dump(board);
		li_board_destroy(&board);
		return (ft_abs(li_perror(rst, NULL)));
	}
	li_print_input(board);
	li_print_result(board);
	li_board_destroy(&board);
	return (0);
}
