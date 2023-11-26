/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 13:46:16 by mickert           #+#    #+#             */
/*   Updated: 2023/11/26 13:47:39 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*temp;
	t_list	*first;

	if (stack_b && (*stack_b) && (*stack_b)->next)
	{
		first = *stack_b;
		last = *stack_b;
		while (last->next)
			last = last->next;
		temp = first;
		*stack_b = first->next;
		last->next = temp;
		first->next = NULL;
		ft_printf("rrb\n");
	}
}
