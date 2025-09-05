/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                         :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: galhajaj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:24:36 by galhajaj          #+#    #+#             */
/*   Updated: 2024/08/26 16:26:59 by galhajaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}
