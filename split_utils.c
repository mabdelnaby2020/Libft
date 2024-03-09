/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelna <mabdelna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:19:24 by mabdelna          #+#    #+#             */
/*   Updated: 2024/03/05 22:23:06 by mabdelna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	index;

	index = ft_strlen(src);
	i = 0;
	if (!dst || !siz)
		return (index);
	if ((index + 1 < siz))
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	else if (siz != 0)
	{
		while (i < siz - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (index);
}
