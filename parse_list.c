/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:22:56 by mickert           #+#    #+#             */
/*   Updated: 2023/11/25 12:53:19 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	custom_del(void *content)
{
	int	*number;

	number = (int *)content;
	free(number);
}

t_list	*ft_pslstnew(void *c)
{
	t_list	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->content = c;
	lst->next = NULL;
	return (lst);
}

int	has_duplicate(t_list *stack_a, int new_number)
{
	t_list	*current;
	int		*content;

	current = stack_a;
	while (current)
	{
		content = (int *)current->content;
		if (*content == new_number)
		{
			ft_printf("Error: Duplicate number %d\n", new_number);
			return (1);
		}
		current = current->next;
	}
	return (0);
}