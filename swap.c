/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 18:15:26 by tpenalba          #+#    #+#             */
/*   Updated: 2023/05/30 19:16:44 by tpenalba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile **pile)
{
	long		swap_one;

	if ((*pile) == NULL || (*pile)->next == NULL)
		return ;
	swap_one = (*pile)->value;
	(*pile)->value = (*pile)->next->value;
	(*pile)->next->value = swap_one;
}

void	swap_a(t_pile **pile_a)
{
	swap(pile_a);
	write(1, "sa\n", 3);
}

void	swap_b(t_pile **pile_b)
{
	swap(pile_b);
	write(1, "sb\n", 3);
}
