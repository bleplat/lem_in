/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   li_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <bleplat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:53:38 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/27 20:27:54 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					li_perror(int code, const char *message)
{
	(void)message;
	if (code == 0 && message == NULL)
		ft_dprintf(2, "ERROR");
	return (code);
}
