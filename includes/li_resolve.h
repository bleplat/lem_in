/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_resolve.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:14:55 by jthierce          #+#    #+#             */
/*   Updated: 2020/02/29 18:00:17 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_RESOLVE_H
# define LI_RESOLVE_H
#include "li_board.h"
#include "li_room.h"
#include "li_calc_step.h"

int		li_resolve(t_board board);
int		**li_create_matrice(int size_room);
void 	li_free_matrice(int **matrice, int size);
int		li_ini_matrice_link(t_board board, int **matrice);
int		li_free_link(t_board board);
int		li_memrealloc(void **mem, size_t previous_size, size_t new_size);
void	li_insertion_sort(int *str, size_t size);

#endif