/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_resolve.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 16:14:55 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/10 18:33:41 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_RESOLVE_H
# define LI_RESOLVE_H
#include <stdlib.h>

#include "libft.h"

#include "li_board.h"
#include "li_room.h"
#include "li_calc_step.h"

#define LI_STATUS_IN_PATH 2

#define LI_MATRICE_NO_LINK 0
#define LI_MATRICE_LINK 1
#define LI_MATRICE_X_TO_Y 4
#define LI_MATRICE_Y_TO_X 5

int		li_resolve(t_board board);
int		li_bfs(t_board board, int **matrice);
int		li_bfs_body(t_board board, int **matrice, int *queu, int j);
int		**li_create_matrice(int size_room);
void 	li_free_matrice(int **matrice, int size);
int		li_ini_matrice_link(t_board board, int **matrice);
int		li_free_link(t_board board);
int		li_memrealloc(void **mem, size_t previous_size, size_t new_size);
void	li_insertion_sort(int *str, size_t size);
int		li_calc_step(t_board board, int status);
int		li_create_path(t_board board, int **matrice);
void	li_reset_bfs(t_board board, int **matrice);
void	li_print_matrice(t_board board, int **matrice);
void	li_distance_path(t_board board, int *distance, int size);
			void	li_print_path(t_board board);

#endif