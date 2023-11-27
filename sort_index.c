/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:16:25 by mickert           #+#    #+#             */
/*   Updated: 2023/11/27 18:54:26 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_index(int *array_numbers, int array_len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = 0;
	ft_printf("Read value: %d\n", *array_numbers);
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
	// for (int i = 0; i < array_len; i++)
	//     {
	//         ft_printf("array in sort_ind: %d\n", array_numbers[i]);
	//     }
	return (array_numbers);
}

// int	main(void)
// {
// 	int array_numbers[] = {1, 9, 3, 6, 7, 4, 8};
// 	int array_length = sizeof(array_numbers) / sizeof(array_numbers[0]);
// 	sort_index(array_numbers, array_length);
//  for (int i = 0; i < array_length; i++)
//     {
//         printf("%d ", array_numbers[i]);
//     }	return (0);
// }