/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:22:10 by mickert           #+#    #+#             */
/*   Updated: 2023/11/20 12:40:38 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	int		index;

	index = 1;
	stack_a = NULL;
	if (parse(argc, argv, &stack_a, index) == 1)
		return (1);
	return (0);
}

int	parse(int argc, char **argv, t_list **stack_a, int index)
{
	int		i;
	int		*array_numbers;
	char	**input_numbers;

	while (index < argc)
	{
		input_numbers = ft_split(argv[index], ' ');
		i = 0;
		if (check(*input_numbers) == 1)
			return (free(input_numbers), 1);
		while (input_numbers[i] != NULL)
		{
			array_numbers = ft_calloc(1, sizeof(int));
			if (!array_numbers)
				return (ft_printf("Error: Memory allocation failed\n"), 1);
			if ((array_numbers[0] = ft_atoi_push_swap(input_numbers[i])) == 1)
				return (free(array_numbers), 1);
			ft_lstadd_front(stack_a, ft_lstnew(array_numbers));
			ft_printf("number in new_node: %d\n", *(int *)array_numbers);
			i++;
		}
		i = 0;
		while (input_numbers[i++] != NULL)
			free(input_numbers[i]);
		free(input_numbers);
		index++;
	}
	return (0);
}

// Add a free all the allocated nodes if there is one invalid. and dont do anything else afterwards

// void	ft_lstclear(t_list **lst, void (*del)(void*))
// {
// 	t_list	*current;
// 	t_list	*next;

// 	current = *lst;
// 	if (lst != NULL && del != NULL)
// 	{
// 		while (current)
// 		{
// 			next = current->next;
// 			del(current->content);
// 			free(current);
// 			current = next;
// 		}
// 	}
// 	*lst = NULL;
// }

// void custom_del(void *content)
// {
// 	if (content != NULL)
// 		free(content);
// }

// void	free_stuff(char **input_numbers, t_list **s_list)
// {
// 	int	i;

// 	i = 0;
// 	while (input_numbers[i] != NULL)
// 	{
// 		free(input_numbers);
// 		i++;
// 	}
// 	free(input_numbers);
// 	ft_lstclear(s_list, custom_del);
// }

int	check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			ft_printf("Error: invalid input\n");
			return (1);
		}
		if (ft_isdigit(str[i]) == 0)
		{
			ft_printf("Error: invalid input\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi_push_swap(const char *str)
{
	int	i;
	int	nbr;

	nbr = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] && ft_isdigit(str[i]) == 1)
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr);
}

// int	parse(int argc, char **argv, t_list **stack_a, int index)
// {
// 	int		i;
// 	int		*array_numbers;
// 	char	**input_numbers;

// 	while (index < argc)
// 	{
// 		input_numbers = ft_split(argv[index], ' ');
// 		i = 0;
// 		while (input_numbers[i] != NULL)
// 		{
// 			if (check(*input_numbers) == 1)
// 				return (1);
// 		}
// 		while (input_numbers[i] != NULL)
// 		{
// 			array_numbers = ft_calloc(1, sizeof(int));
// 			if (!array_numbers)
// 				return (ft_printf("Error: Memory allocation failed\n"), 1);
// 			if ((array_numbers[0] = ft_atoi_push_swap(input_numbers[i])) == 1)
// 				return (free(array_numbers), 1);
// 			ft_lstadd_front(stack_a, ft_lstnew(array_numbers));
// 			ft_printf("number in new_node: %d\n", *(int *)array_numbers);
// 			i++;
// 		}
// 		i = 0;
// 		while (input_numbers[i++] != NULL)
// 			free(input_numbers[i]);
// 		free(input_numbers);
// 		index++;
// 	}
// 	return (0);
// } 
//nichts passiert

// int	parse(int argc, char **argv, t_list **stack_a, int index)
// {
// 	int		i;
// 	int		*array_numbers;
// 	char	**input_numbers;

// 	while (index < argc)
// 	{
// 		input_numbers = ft_split(argv[index], ' ');
// 		i = 0;
// 		while (input_numbers[i] != NULL)
// 		{
// 			if (check(input_numbers[i]) == 1)
// 				return (1);
// 			array_numbers = ft_calloc(1, sizeof(int));
// 			if (!array_numbers)
// 				return (ft_printf("Error: Memory allocation failed\n"), 1);
// 			*array_numbers = ft_atoi_push_swap(input_numbers[i]);
// 			i++;
// 		}
// 		// while (input_numbers[i--] != NULL)
// 		// 	free(input_numbers[i]);
// 		// free(input_numbers);
// 		index++;
// 	}
// 	ft_lstadd_front(stack_a, ft_lstnew(array_numbers));
// 	ft_printf("number in new_node: %d\n", *(int *)array_numbers);
// 	return (0);
// }

// int	parse(int argc, char **argv, int index)
// {
// 	int		i;
// 	char	**input_numbers;
// 	char	*temp = NULL;

// 	while (index < argc)
// 	{
// 		input_numbers = ft_split(argv[index], ' ');
// 		i = 0;
// 		while (input_numbers[i] != NULL)
// 		{
// 			temp = ft_strjoin(temp, input_numbers[i]);
// 			i++;
// 		}
// 		free(input_numbers);
// 		index++;
// 	}
// 	ft_printf(" %s\n", temp);
// 	return (0);
// }

// int	parse(int argc, char **argv, t_list **stack_a, int index)
// {
// 	int		i;
// 	int		*array_numbers;
// 	char	**input_numbers;
// 	int		*temp;

// 	while (index < argc)
// 	{
// 		input_numbers = ft_split(argv[index], ' ');
// 		i = 0;
// 		temp = 0;
// 		if (check(*input_numbers) == 1)
// 			return (free(input_numbers), 1);
// 		while (input_numbers[i] != NULL)
// 		{
// 			array_numbers = ft_calloc(1, sizeof(int));
// 			if (!array_numbers)
// 				return (ft_printf("Error: Memory allocation failed\n"), 1);
// 			if ((array_numbers[0] = ft_atoi_push_swap(input_numbers[i])) == 1)
// 				return (free(array_numbers), 1);
// 			temp += array_numbers[0];
// 			i++;
// 		}
// 		ft_printf("temp: %d\n", temp);
// 		i = 0;
// 		while (input_numbers[i++] != NULL)
// 			free(input_numbers[i]);
// 		free(input_numbers);
// 		index++;
// 	}
// 	ft_lstadd_front(stack_a, ft_lstnew(temp));
// 	ft_printf("number in new_node: %d\n", *(int *)temp);
// 	return (0);
// }
//segfault