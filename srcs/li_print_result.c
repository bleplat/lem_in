/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:43:42 by bleplat           #+#    #+#             */
/*   Updated: 2020/03/12 20:18:49 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "li.h"

/*
** Every ant choose a path it will take.
*/

void			li_print_result_2(t_board *board, t_array *pathes_a)
{
	int		*choices;

	if (!(choices = li_ant_choices_create(board, pathes_a)))
		return ;
	/* // TODO: function displaying choices
	for (int n = 0; n < board->ants_count; n++)
		ft_printf("%d, ", choices[n]);
	ft_printf("\n");
	*/
	li_print_result_from_choices(board, pathes_a, choices);
	ft_free0(choices);
}

/*
** proceed the final output of the ants moves.
*/

void			li_print_result(t_li_board *board)
{
	//li_board_dump(board);
	t_array			*pathes_a;
	ft_putchar('\n');

	if (board->resolve_result == 2)
	{
		li_print_singleround_result(board);
		return ;
	}

	if (!(pathes_a = li_pathes_create(board)))
		return ;

/* // TODO: put that in a function
	for (int i_path = 0; i_path < pathes_a->item_count; i_path++)
	{
		ft_printf("voici un chemin:\n");
		t_array		*rooms_a;
		rooms_a = *(void**)ft_array_at(pathes_a, i_path);
		for (int k = 0; k < rooms_a->item_count; k++)
		{
			li_room_dump(*(void**)ft_array_at(rooms_a, k));
		}
		

	}
*/

	li_print_result_2(board, pathes_a);
	li_pathes_destroy(&pathes_a);
}
