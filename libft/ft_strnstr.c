/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galhajaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:13:01 by galhajaj          #+#    #+#             */
/*   Updated: 2024/08/26 16:14:39 by galhajaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] != '\0' && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (little[j] != '\0' && j + i < len)
			{
				if (big[i + j] == little[j] && little[j + 1] == '\0')
					return ((char *)&big[i]);
				else if (big[i + j] != little[j])
					break ;
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
