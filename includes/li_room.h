/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_room.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 22:23:36 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/27 14:30:22 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_ROOM_H
# define LI_ROOM_H

typedef struct	s_rooms
{
	char			*name;
	int				index;
	int				*link;
	struct s_rooms	*prev;
	int				ants_in_path; //peut etre inutile a voir plus tard
	int				status;
	struct s_rooms	*next;
}				t_rooms;

#endif