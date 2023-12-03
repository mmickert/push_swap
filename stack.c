/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:32:11 by mickert           #+#    #+#             */
/*   Updated: 2023/12/03 14:42:26 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacknew(int c)
{
	t_stack	*lst;

	lst = malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->content = c;
	lst->next = NULL;
	return (lst);
}

void	stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*lastlst;

	if (lst != NULL && new != NULL)
	{
		lastlst = stacklast(*lst);
		if (lastlst == NULL)
		{
			*lst = new;
		}
		else
		{
			lastlst->next = new;
		}
	}
}

t_stack	*stacklast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	stackclear(t_stack **lst)
{
	t_stack	*next_temp;

	if (!lst)
		return ;
	while (*lst)
	{
		next_temp = (*lst)->next;
		free(*lst);
		*lst = next_temp;
	}
	*lst = NULL;
}
