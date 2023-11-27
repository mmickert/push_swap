/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:22:01 by mickert           #+#    #+#             */
/*   Updated: 2023/11/27 19:05:28 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse(int argc, char **argv, t_list **stack_a, int index)
{
	int		i;
	int		*array_numbers;
	char	**input_numbers;
	int		array_len;

	array_len = 0;
	while (index < argc)
	{
		input_numbers = ft_split(argv[index], ' ');
		i = 0;
		if (check(*input_numbers, stack_a) == 1)
			return (free_input_numbers(input_numbers), 1);
		// put_in_array_stack(input_numbers, stack_a, i);
		while (input_numbers[i] != NULL)
		{
			array_numbers = ft_calloc(1 + i, sizeof(int));
			if (!array_numbers)
				return (ft_printf("Error: Memory allocation failed\n"), 1);
			array_numbers[i] = ft_atoi_push_swap(input_numbers[i]);
			array_len++;
			if (has_duplicate(*stack_a, *array_numbers) == 1)
				return (free(array_numbers), free_input_numbers(input_numbers),
					1);
			ft_lstadd_back(stack_a, ft_pslstnew(array_numbers));
			i++;
		}
		if (input_numbers)
			free_input_numbers(input_numbers);
		index++;
	}
	// sort_index(array_numbers, array_len);
	return (0);
}

// int	put_in_array_stack(char **input_numbers, t_list **stack_a, int i)
// {
// 	int		*array_numbers;

// 	while (input_numbers[i] != NULL)
// 	{
// 		array_numbers = ft_calloc(1, sizeof(int));
// 		if (!array_numbers)
// 			return (ft_printf("Error: Memory allocation failed\n"), 1);
// 		array_numbers[0] = ft_atoi_push_swap(input_numbers[i]);
// 		if (has_duplicate(*stack_a, array_numbers[0]) == 1)
// 			return (free(array_numbers), free_input_numbers(input_numbers), 1);
// 		ft_lstadd_front(stack_a, ft_pslstnew(array_numbers));
// 		i++;
// 	}
// 	return (0);
// }

void	free_input_numbers(char **input_numbers)
{
	int	i;

	i = 0;
	while (input_numbers[i] != NULL)
	{
		free(input_numbers[i]);
		i++;
	}
	free(input_numbers);
}

int	check(char *str, t_list **stack_a)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			i++;
		if (ft_isdigit(str[i]) == 0)
		{
			ft_printf("Error: invalid input\n");
			ft_lstclear(stack_a, custom_del);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi_push_swap(const char *str)
{
	int i;
	int nbr;

	nbr = 0;
	i = 0;
	if (str[i] == '-')
	{
		ft_printf("-");
		i++;
	}
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr);
}