/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_room.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 22:23:36 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/27 19:17:12 by bleplat          ###   ########.fr       */
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
	int			status;//Initialiser a 0
};

t_li_room						*li_room_find(t_room *rooms, int cnt, char *n);

#endif
