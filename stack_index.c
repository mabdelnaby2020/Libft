/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelna <mabdelna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 13:45:39 by mabdelna          #+#    #+#             */
/*   Updated: 2024/02/25 16:42:06 by mabdelna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int		h_min;

	min = NULL;
	h_min = 0;
	head = *stack;
	if (head != NULL)
	{
		while (head != NULL)
		{
			if (head->index == -1 && (h_min == 0 || head->data < min->data))
			{
				min = head;
				h_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	ft_stack_index(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = ft_get_next_min(stack);
	while (head != NULL)
	{
		head->index = index++;
		head = ft_get_next_min(stack);
	}
}
