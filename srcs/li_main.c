/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 17:45:14 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/27 19:58:32 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_board.h"

/*
** Main, resolve lem_in and print
*/

int		main_resolve(t_li_board board)
{
	(void)board;
	// TODO: Resolve lem_in.
	// TODO: Print input.
	// TODO: Print results.
	return (-42);
}

/*
** Main, parsing options and inputs.
*/

int		main(int argc, char **argv)
{
	int			rst;
	t_li_board	board;

	(void)argc;
	(void)argv;
	board = li_board_create();
	if ((rst = li_board_parse_input(&board)) < 0)
	{
		li_board_destroy(&board);
		return (-rst);
	}
	if ((rst = main_resolve(board)) < 0)
	{
		li_board_destroy(&board);
		return (-rst);
	}
	li_board_destroy(&board);
	return (0);
}
