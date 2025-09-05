/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galhajaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 17:35:27 by galhajaj          #+#    #+#             */
/*   Updated: 2024/08/26 17:35:28 by galhajaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v'
		|| c == '\n' || c == '\r' || c == '\f');
}

int	ft_atoi(const char *nptr)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10 + (*nptr - '0');
		if (sign * num > MAXINT)
			return (-1);
		if (sign * num < MININT)
			return (0);
		nptr++;
	}
	return ((int)(sign * num));
}
