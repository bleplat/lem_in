/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi32check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:51:15 by bleplat           #+#    #+#             */
/*   Updated: 2020/02/28 14:00:54 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_atoi32check_p2(int *out, long long total)
{
	if (total > FT_INT32_MAX || total < FT_INT32_MIN)
		return (-2);
	(*out) = (int)total;
	return (0);
}

/*
** Same as dt_atoi32check() but count a char as a valid end of integer.
*/

int			ft_atoi32checkc(int *out, const char *str, char end)
{
	int				i;
	long long		sign;
	long long		total;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	total = 0;
	if (str[i] == '\0')
		return (-1);
	while (str[i] != end)
	{
		if (!ft_isdigit(str[i]))
			return (-1);
		total = (total * 10) + (str[i] - '0');
		if (total > ((long long)FT_INT32_MAX + 1))
			return (-2);
		i++;
	}
	return (ft_atoi32check_p2(out, total * sign));
}

/*
** Read an int as ft_atoi, but return 0 on success, and a negative value if the
** string is not a valid int32.
** Return -1 on invalid character.
** Return -2 on out of integer limits.
*/

int			ft_atoi32check(int *out, const char *str)
{
	return (ft_atoi32checkc(out, str, '\0'));
}
