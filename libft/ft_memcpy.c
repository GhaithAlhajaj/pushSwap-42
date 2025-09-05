/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galhajaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:58:14 by galhajaj          #+#    #+#             */
/*   Updated: 2024/08/26 14:59:03 by galhajaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dp;
	const char	*sp;

	if (!dst && !src)
		return (0);
	if (n == 0 || (dst == src))
		return (dst);
	dp = (char *)dst;
	sp = (const char *)src;
	while (n != 0)
	{
		if (*dp != *sp)
			*dp = *sp;
		dp++;
		sp++;
		n--;
	}
	return (dst);
}
