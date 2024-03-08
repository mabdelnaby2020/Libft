/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelna <mabdelna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 20:06:37 by mabdelna          #+#    #+#             */
/*   Updated: 2024/03/07 17:14:12 by mabdelna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

int	ft_do_commands_2(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(line, "ra\n"))
		rotat(stack_a);
	else if (!ft_strcmp(line, "rb\n"))
		rotat(stack_b);
	else if (!ft_strcmp(line, "rr\n"))
	{
		rotat(stack_a);
		rotat(stack_b);
	}
	else if (!ft_strcmp(line, "rra\n"))
		rev_rotat(stack_a);
	else if (!ft_strcmp(line, "rrb\n"))
		rev_rotat(stack_b);
	else if (!ft_strcmp(line, "rrr\n"))
	{
		rev_rotat(stack_a);
		rev_rotat(stack_b);
	}
	return (0);
}

int	ft_do_commands(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!line)
		return (1);
	if (!ft_strcmp(line, "pa\n"))
		push(stack_a, stack_b);
	else if (!ft_strcmp(line, "pb\n"))
		push(stack_b, stack_a);
	else if (!ft_strcmp(line, "sa\n"))
		swap(stack_a);
	else if (!ft_strcmp(line, "sb\n"))
		swap(stack_b);
	else if (!ft_strcmp(line, "ss\n"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else
		ft_do_commands_2(line, stack_a, stack_b);
	return (0);
}

void	ft_checker(t_list **stack_a, t_list **stack_b, char *new_line)
{
	while (new_line)
	{
		if ((ft_do_commands(new_line, stack_a, stack_b)) != 0)
		{
			ft_putstr_fd("ERROR:", 1);
			free(new_line);
			return ;
		}
		new_line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	char	*new_line;

	if (argc < 2)
		return (0);
	ft_args_check(argc, argv);
	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_a || !stack_b)
		return (-1);
	ft_stack_intiat(stack_a, argc, argv);
	if (ft_is_sorted(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	new_line = get_next_line(0);
	ft_checker(stack_a, stack_b, new_line);
	ft_checker_res(stack_a, stack_b, new_line);
	return (0);
}

void	ft_checker_res(t_list **stack_a, t_list **stack_b, char *new_line)
{
	if ((ft_is_sorted(stack_a) != 0) && (ft_lstsize(*stack_b)) == 0)
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	free(new_line);
}
