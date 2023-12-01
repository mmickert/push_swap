/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:16:25 by mickert           #+#    #+#             */
/*   Updated: 2023/12/01 12:22:53 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_to_index(t_stack **stack_a, int array_len)
{
	t_stack	*current;
	int		*array_numbers;
	int		i;

	i = 0;
	current = *stack_a;
	array_numbers = ft_calloc(array_len + 1, sizeof(int));
	if (!array_numbers)
	{
		ft_printf("Error: Memory allocation failed\n");
		stackclear(stack_a);
		exit(1);
	}
	while (i < array_len)
	{
		array_numbers[i] = current->content;
		current = current->next;
		i++;
	}
	sort_index(array_numbers, array_len);
	assign_index(stack_a, array_numbers);
	if (array_numbers)
		free(array_numbers);
}

int	*sort_index(int *array_numbers, int array_len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	while (i < array_len - 1)
	{
		while (j < array_len - i - 1)
		{
			if (array_numbers[j] > array_numbers[j + 1])
			{
				temp = array_numbers[j];
				array_numbers[j] = array_numbers[j + 1];
				array_numbers[j + 1] = temp;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (array_numbers);
}

void	assign_index(t_stack **stack_a, int *array_numbers)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *stack_a;
	while (temp)
	{
		if (temp->content == array_numbers[i])
		{
			temp->index = i + 1;
			i = 0;
			temp = temp->next;
		}
		else
			i++;
	}
}
