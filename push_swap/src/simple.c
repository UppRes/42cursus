/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykuru <ykuru@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 17:59:21 by ykuru             #+#    #+#             */
/*   Updated: 2022/11/30 17:59:33 by ykuru            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_small_sort(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
	}
	else if (ft_lstsize(*stack_a) == 3)
		ft_sort_three(stack_a);
	else if (ft_lstsize(*stack_a) == 4)
		ft_sort_four(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) == 5)
		ft_sort_five(stack_a, stack_b);
}
