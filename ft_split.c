/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelna <mabdelna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:18:34 by mabdelna          #+#    #+#             */
/*   Updated: 2024/03/05 20:18:34 by mabdelna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_subs_count(const char *s, char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		if (*s != c)
		{
			n++;
			while (*s && *s != c)
				s++;
		}
		else
		{
			s++;
		}
	}
	return (n);
}
// Allocate memory for substrings and handle free the memory on failure

char	**alloct_subs_array(size_t n)
{
	char	**subs_array;

	subs_array = (char **)malloc(sizeof(char *) * (n + 1));
	if (subs_array == NULL)
		return (NULL);
	subs_array[n] = NULL;
	return (subs_array);
}

// Create substrings and handle cleanup on allocation failure
int	sub_str_cpy(char **sub_str, const char *p0, size_t le, size_t i)
{
	size_t	j;

	j = 0;
	sub_str[i] = (char *)malloc(le + 1);
	if (sub_str[i] == NULL)
	{
		while (j < i)
		{
			free(sub_str[j]);
			j++;
		}
		free(sub_str);
		return (0);
	}
	ft_strlcpy(sub_str[i], p0, le + 1);
	return (1);
}

char	**ft_split(const char *s1, char c)
{
	char			**sub_str;
	const char		*p;
	const char		*p0;
	size_t			i;

	i = 0;
	p = s1;
	sub_str = alloct_subs_array(ft_subs_count(s1, c));
	if (sub_str == NULL)
		return (NULL);
	while (*p != '\0')
	{
		if (*p != c)
		{
			p0 = p;
			while (*p != c && *p != '\0')
				p++;
			if (!sub_str_cpy(sub_str, p0, (p - p0), i))
				return (NULL);
			i++;
		}
		else
			p++;
	}
	return (sub_str);
}
