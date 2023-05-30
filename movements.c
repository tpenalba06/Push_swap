/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:55:14 by tpenalba          #+#    #+#             */
/*   Updated: 2023/05/30 16:40:32 by tpenalba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_pile **pile_a, t_pile **pile_a)
{
	t_pile *copy;
	int swap_one;
	int swap_two;

	//pile_a->value = la premiere valeur de la pile a

	copy = **pile_a;

	swap_one = copy->value;
	copy = copy->next;
	swap_two = copy_value;

}
void	push(t_pile **src, t_pile **dst,)
{
	t_pile *tmp;
	
	if (*src = NULL)
		return ;
	tmp = *src_a->next;
	*dst = *src;
	*src->next = *dst;
	*src = tmp;
}

void	push_pa(t_pile **pile_a)
(
	push(stack_b, stack_a);
	ft_putstr("pa\n");
)

void push_pb(t_pile **pile_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}
