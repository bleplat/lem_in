/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_bfs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:03:31 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/10 19:15:09 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_resolve.h"

/*static void li_print_status_room(t_board board)
{
	int i;

	i = -1;
	while (++i < board.rooms_count)
		ft_printf("{pink}Rooms %d status = %d\n{}", i, board.rooms[i].status);
}*/

static void	li_first_reset(t_board board)
{
	int i;

	i = -1;
	while (++i < board.rooms_count)
	{
		if (board.rooms[i].status == 7)
			board.rooms[i].status = 2;
		else if (board.rooms[i].status == 8)
			board.rooms[i].status = 2;
	}
}

static void	li_used_path(t_board board, int **matrice)
{
	t_room *rooms;

	rooms = &board.rooms[1];
	while (rooms != NULL)
	{
		//ft_printf("{blue}Rooms %d status = %d{}\n", rooms->index, rooms->status);
		if (rooms->status == 7)
		{
			rooms->prev = rooms->cp;
			rooms->status = 5;
		}
		if (rooms->status == 8)
		{
			rooms->status = 6;
			matrice[rooms->index][rooms->cp->index] = 7;
			matrice[rooms->cp->index][rooms->index] = 6;
		}
		rooms = rooms->cp;
	}
}

static int li_search_other_path(t_board board, int **matrice, int *queu, int *j)
{
	int i;

	i = -1;
	/*ft_printf("{}+++++++++++++++++++\n{red}end status = %d\n{}", board.rooms[1].status);
	li_print_matrice(board, matrice);*/
	while  (board.rooms[1].status != 1 && queu[++i] != 0)    //doute de la condition
		*j += li_bfs_body(board, matrice, queu + i, *j - i);
	/*li_print_matrice(board, matrice);
	ft_printf("{}--------------------\n");*/
	if (queu[i] == 0 && board.rooms[1].status == 0)
		return (-2);
	else if (queu[i] == 0) //doute de la condition
		return (1);
	li_used_path(board, matrice);
	li_first_reset(board);
	ft_printf("{blue}On entre dans li_create_path\n{}");
	if ((i = li_create_path(board, matrice)) == -1)
	{
		ft_printf("{green}GEANT VERT??\n");
		return (-1);
	}
	ft_printf("{blue}BLUE DABEDI DABEDA\n");
	if (i == -2)
		return (1);
	return (0);
}

static int	li_first_bfs(t_board board, int **matrice, int *queu, int *j)
{
	int i;

	i = -1;
	board.rooms[0].status = 1;
	while (++i < board.rooms[0].count_link)
	{
		if (board.rooms[0].link[i] == 1)
		{
			board.rooms[1].prev = &(board.rooms[0]);
			return (1);
		}
		if (board.rooms[board.rooms[0].link[i]].status == 0)
		{
			matrice[0][board.rooms[0].link[i]] = 2;
			matrice[board.rooms[0].link[i]][0] = 2;
			*j += 1;
			queu[*j] = board.rooms[0].link[i];
			board.rooms[board.rooms[0].link[i]].status = 1;
			board.rooms[board.rooms[0].link[i]].prev = &board.rooms[0];
		}
	}
	return (0);
}

/*
** The head of bfs
**
** Return Value:
**
** -1 = malloc fail
** -2 = pas de chemin trouvé
** 1 = Bfs is okay min 1 path is find
** 2 = end is link with start so we can print in one line
*/

int		li_bfs(t_board board, int **matrice)
{
	int	*queu;
	int i;
	int j;


	i = -1;
	if (!(queu = (int *)malloc(sizeof(int) * board.rooms_count)))
		return (-1);
	while (i != 1)
	{
		j = -1;
		while (++j < board.rooms_count)
			queu[j] = 0;
		j = -1;
		if (li_first_bfs(board, matrice, queu, &j))
		{
			free(queu);
			return (2);
		}
		i = li_search_other_path(board, matrice, queu, &j);
		if (i == -1 || i == -2)
		{
			free(queu);
			return (i);
		}
		//li_print_status_room(board);
		li_reset_bfs(board, matrice);
		li_print_path(board);
	}
	free(queu);
	return (0);
}
