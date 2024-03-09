/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelna <mabdelna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:06:26 by mabdelna          #+#    #+#             */
/*   Updated: 2024/03/09 09:27:34 by mabdelna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	ft_putstr_fd(str, 1);
	exit(0);
}

int	ft_atoi(const char *strn)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (strn[i] == 32 || (strn[i] >= 9 && strn[i] <= 13))
		i++;
	if (strn[i] == '-' || strn[i] == '+')
	{
		if (strn[i] == '-')
			sign = -1;
		i++;
	}
	if (strn[i] == '-' || strn[i] == '+')
		return (0);
	while (strn[i] >= '0' && strn[i] <= '9')
	{
		res = (res * 10) + (strn[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
	write(fd, "\n", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2147483648", 10);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		n %= 10;
		n += 48;
		write(fd, &n, 1);
	}
	else
	{
		n = n + 48;
		write(fd, &n, 1);
	}
	return ;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
