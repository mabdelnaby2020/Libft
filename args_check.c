/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelna <mabdelna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:03:44 by mabdelna          #+#    #+#             */
/*   Updated: 2024/03/09 10:27:51 by mabdelna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_iscontains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

void	ft_args_checker(char **args, int i)
{
	long	temp;

	while (args[i])
	{
		temp = ft_atoi(args[i]);
		if (ft_isnum(args[i]))
			ft_error("ERROR:");
		if (ft_iscontains(temp, args, i))
			ft_error("ERROR:");
		if (temp <= -2147483648 || temp >= 2147483647)
			ft_error("ERROR:");
		i++;
	}
}

void	ft_args_check(int argc, char **argv)
{
	char	**args;
	int		i;

	i = 1;
	if (argc < 2)
		ft_error("ERROR:");
	if (argc == 2)
	{
		args = ft_split(argv[1], 32);
		i = 0;
	}
	else
		args = argv;
	ft_args_checker(args, i);
	if (argc == 2)
		free(args);
}

int	ft_is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
	}
	return (1);
}
