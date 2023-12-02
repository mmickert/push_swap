/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:25:02 by mickert           #+#    #+#             */
/*   Updated: 2023/12/02 15:12:25 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b, int array_len)
{
	int	middle;

	middle = square(array_len);
	if (array_len == 2)
		sort_2(stack_a);
	if (array_len == 3)
		sort_3(stack_a);
	else if (array_len > 3)
		sort_more(stack_a, stack_b, array_len, middle);
}

void	sort_2(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a, 0);
}

void	sort_3(t_stack **stack_a)
{
	while (!((*stack_a)->index == 1 && (*stack_a)->next->index == 2
			&& (*stack_a)->next->next->index == 3))
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a, 0);
		if ((*stack_a)->next->index > (*stack_a)->next->next->index)
			rra(stack_a, 0);
	}
}

void	sort_more(t_stack **stack_a, t_stack **stack_b,
			int array_len, int middle)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index <= middle + i)
		{
			pb(stack_a, stack_b);
			i++;
			if (((*stack_b)->next)
				&& (*stack_b)->index <= i)
				rb(stack_b, 0);
		}
		else
			ra(stack_a, 0);
	}
	while (*stack_b)
	{
		if ((*stack_b)->index == array_len)
		{
			pa(stack_a, stack_b);
			array_len--;
		}
		else
			rrb(stack_b, 0);
	}
	print_stack_a(stack_a);
	print_stack_b(stack_b);
}

// print_stack_a(stack_a);
// print_stack_b(stack_b);

// void	sort_more(t_stack **stack_a, t_stack **stack_b, int array_len)
// {
// 	int		middle;
// 	int		i;
// 	t_stack	*last;

// 	i = 0;
// 	middle = square(array_len) * 1.4;
// 	while (*stack_a)
// 	{
// 		if ((*stack_a)->index <= middle + i)
// 		{
// 			pb(stack_a, stack_b);
// 			i++;
// 			if (((*stack_b)->next)
// 				&& (*stack_b)->index <= (*stack_b)->next->index)
// 				rb(stack_b, 0);
// 		}
// 		else
// 			ra(stack_a, 0);
// 	}
// 	last = *stack_b;
// 	while (last->next)
// 		last = last->next;
// 	while (*stack_b)
// 	{
// 		if (((*stack_b)->index > last->index) || ((*stack_b)->next == NULL))
// 		{
// 			pa(stack_a, stack_b);
// 		}
// 		else if ((*stack_b)->index < last->index)
// 		{
// 			rrb(stack_b, 0);
// 			last = *stack_b;
// 			while (last->next)
// 				last = last->next;
// 		}
// 	}
// }

// void	sort_more(t_stack **stack_a, t_stack **stack_b, int array_len)
// {
// 	int		middle;
// 	int		i;

// 	i = 0;
// 	middle = square(array_len) * 1.4;
// 	while (*stack_a)
// 	{
// 		if ((*stack_a)->index <= middle + i)
// 		{
// 			pb(stack_a, stack_b);
// 			i++;
// 			if (((*stack_b)->next)
// 				&& (*stack_b)->index <= i)
// 				rb(stack_b, 0);
// 		}
// 		else
// 			ra(stack_a, 0);
// 	}
// 	print_stack_a(stack_a);
// 	print_stack_b(stack_b);
// 	while (array_len--)
// 	{
// 		i = biggest_index(*stack_b, array_len);
// 		print_stack_a(stack_a);
// 		print_stack_b(stack_b);
// 		if ((*stack_b)->index != array_len)
// 		{
// 			if (i <= array_len - i)
// 				rb(stack_b, 0);
// 			else
// 				rrb(stack_b, 0);
// 		}
// 		pa(stack_a, stack_b);
// 	}
// }

// wenn a kleiner als mitte, dann nach b push,
// dort, wenn b grosser als b next, dass b nach unten rotieren.

// jetzt schauen, ob b grosser als letzter in b,
// wenn ja, dann nach a push, wenn nein, dann rotieren b letzter wird b erster.
// wenn jetzt erster grosser als letzter, dann nach a push