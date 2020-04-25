/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthierce <jthierce@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:53:38 by bleplat           #+#    #+#             */
/*   Updated: 2020/04/25 15:09:17 by jthierce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					li_perror(int code, const char *message)
{
	(void)message;
	if (message == NULL)
		ft_dprintf(2, "ERROR\n");
	else
		ft_dprintf(2, message);
	return (code);
}
