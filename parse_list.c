/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:22:56 by mickert           #+#    #+#             */
/*   Updated: 2023/11/28 15:08:27 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_stack *stack_a, int new_number)
{
	t_stack	*current;
	int		*content;

	current = stack_a;
	while (current)
	{
		content = &current->content;
		if (*content == new_number)
		{
			ft_printf("Error: Duplicate number %d\n", new_number);
			return (1);
		}
		current = current->next;
	}
	return (0);
}