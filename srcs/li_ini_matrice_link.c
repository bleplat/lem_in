/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_ini_matrice_link.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 14:49:41 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/27 19:00:44 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "li_room.h"
#include "li_board.h"

int			li_free_link(t_board board)
{
	int i;

	i = -1;
	while (++i < board.rooms_count)
	{
		if (board.rooms[i].index != NULL)
			free(board.rooms[i].index);
	}
	return (-1);
}

static int	li_memrealloc(void **mem, size_t previous_size, size_t new_size)
{
	void		*new_mem;
	size_t		cp_len;

	if (previous_size == new_size)
		return (0);
	if (mem == NULL)
		return (1);
	new_mem = ft_memalloc(new_size);
	if (new_mem == NULL)
		return (1);
	if (*mem != NULL)
	{
		cp_len = (previous_size < new_size) ? (previous_size) : new_size;
		ft_memcpy(new_mem, *mem, cp_len);
		ft_memdel(&(*mem));
	}
	*mem = new_mem;
	return (0);
}


static int	li_find_link(int index, int **matrice, t_board board)
{
	t_room *room;
	int i;
	int	buff;

	i = -1;
	while (++i < board.links_count)
	{
		if (board.links[i].i_room_a == index)
		{
			room = &board.rooms[index];
			matrice[index][board.links[i].i_room_b] = 1;
			matrice[board.links[i].i_room_b][index] = 1;
			if (li_memrealloc(&(room->link), sizeof(int) * room->count_link,
			sizeof(int) * room->count_link + 1))
				return(li_free_link(board));
			room->link[room->count_link] = board.links[i].i_room_b;
			room->count_link++;
			room = board.links[i].p_room_b;
			if (li_memrealloc(&(room->link), sizeof(int) * room->count_link,
			sizeof(int) * room->count_link + 1))
				return(li_free_link(board));
			room->link[room->count_link] = index;
			room->count_link++;
		}
	}
	return (0);
}

int			li_ini_matrice_link(t_board board, int **matrice)
{
	int		i;

	i = -1;
	while (++i < board.rooms_count)
	{
		if (i == 1)
			i++;
		if (li_find_link(i, matrice, board) == -1)
			return (-1);
	}
	return (0);
}