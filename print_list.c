/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelna <mabdelna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:24:39 by mabdelna          #+#    #+#             */
/*   Updated: 2024/03/05 22:24:40 by mabdelna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Prints the Linked List
void	ft_print_list(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->data, 1);
		ft_putstr_fd("", 1);
		tmp = tmp->next;
	}
}
