/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_calc_step.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 15:15:26 by jthierce          #+#    #+#             */
/*   Updated: 2020/03/03 19:56:17 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LI_CALC_STEP_H
# define LI_CALC_STEP_H
#include <string.h>

typedef struct s_li_calc_step	t_li_calc_step;
typedef t_li_calc_step			t_calc_step;
struct			s_li_calc_step
{
	int			step;
	int			*distance;
	ssize_t		size;
};

#endif