/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:22:01 by mickert           #+#    #+#             */
/*   Updated: 2023/12/06 15:53:30 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse(int argc, char **argv, t_stack **stack_a, int array_len)
{
	int		i;
	int		j;
	char	**input_numbers;

	i = 1;
	array_len = 0;
	while (i < argc)
	{
		input_numbers = ft_split(argv[i], ' ');
		j = 0;
		while (input_numbers[j] != NULL)
		{
			check(input_numbers[j], stack_a);
			stackadd_back(stack_a, stacknew(ft_atoi_push_swap(stack_a,
						input_numbers[j])));
			j++;
			array_len++;
		}
		if (input_numbers)
			free_input_numbers(input_numbers);
		i++;
	}
	stack_to_index(stack_a, array_len);
	return (array_len);
}

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

int	check(char *str, t_stack **stack_a)
{
	int	i;

	i = 0;
	if (!str)
		exit(0);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (ft_isdigit(str[i]) == 0)
		{
			ft_printf("Error\n");
			stackclear(stack_a);
			exit(1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi_push_swap(t_stack **stack_a, const char *str)
{
	int		i;
	long	nbr;
	int		minus;

	nbr = 0;
	i = 0;
	minus = 1;
	if (str[i] == '-')
	{
		i++;
		minus = -1;
	}
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	nbr *= minus;
	check_atoi(nbr, stack_a);
	return (nbr);
}

void	check_atoi(long nbr, t_stack **stack_a)
{
	if (nbr < -2147483648 || nbr > 2147483647)
	{
		ft_printf("Error\n");
		stackclear(stack_a);
		exit(1);
	}
}
