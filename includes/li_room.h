/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_room.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 22:23:36 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/10 05:23:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_ROOM_H
# define LI_ROOM_H
#include "libft.h"

/*
** t_li_room
**
** Represent a room.
** The first members result from of the parsing of the input.
** The remainings are used to resolve lem_in.
*/

/*
** STATUS VALUE:
**
**0: Nothing
**1: in Queue
**2: In path
**5: Mandatory to use C path
**6: Used path C
**7: temporary status 5
**8: temporary status 6
*/

typedef struct s_li_room		t_li_room;
typedef t_li_room				t_room;
struct							s_li_room
{
	// Ce que je lis dans les fichiers
	int			index; // Si tu accede aux elements via leur index, alors ceci est deja inutile (si tu utilise rooms[5] alors tu sais deja que index == 5)
	const char	*name;
	int			x;
	int			y;
	// Ce qui est utile lors de la resolution de l'algo
	int			*link;//Mettre a NULL
	int			count_link;//Initialiser a 0
	t_room		*prev;//mettre a NULL
	t_room		*cp;
	int			status;//Initialiser a 0
};

void							li_room_dump(t_li_room *room);

int								li_room_is_name_valid(const char *str);

t_li_room						*li_room_find(t_room *rooms, int cnt,
												const char *n);

int								li_room_clean0(t_room *room);
int								li_room_popclean0(t_array *rooms);


#endif
