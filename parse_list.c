/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:22:56 by mickert           #+#    #+#             */
/*   Updated: 2023/12/01 12:34:37 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicate(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*next_temp;
	int		*content;
	int		*next_content;

	temp = *stack_a;
	while (temp)
	{
		content = &temp->content;
		next_temp = temp->next;
		while (next_temp)
		{
			next_content = &next_temp->content;
			if (*content == *next_content)
			{
				ft_printf("Error: Duplicate number.\n");
				stackclear(stack_a);
				return (1);
			}
			next_temp = next_temp->next;
		}
		temp = temp->next;
	}
	return (0);
}
