/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mickert <mickert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:23:06 by mickert           #+#    #+#             */
/*   Updated: 2023/11/20 11:46:49 by mickert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_libft/libft.h"


# define TRUE 1
# define FALSE 0

// typedef struct s_list
// {
// 	int				unordered_numbers;
// 	struct s_list	*next;
// }				t_list;

int		main(int argc, char *argv[]);
int		parse(int argc, char **argv, t_list **stack_a, int index);
int		ft_atoi_push_swap(const char *str);
int		check(char *str);
void	free_stuff(char **input_numbers, t_list **s_list);
void	custom_del(void *content);


#endif