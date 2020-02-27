/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_room.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 22:23:36 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/27 16:55:56 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_ROOM_H
# define LI_ROOM_H
#include "libft.h"

typedef struct	s_rooms
{
	char			*name;
	int				index;
	t_array			*link;
	struct s_rooms	*prev;
	int				ants_in_path; //peut etre inutile a voir plus tard
	int				status;
	struct s_rooms	*next;
}				t_rooms;

#endif