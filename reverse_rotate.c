/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:54:00 by tpenalba          #+#    #+#             */
/*   Updated: 2023/05/31 17:54:40 by tpenalba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_pile **pile)
{
	t_pile	*last;
	t_pile	*tmp;

	last = *pile;
	tmp = *pile;
	if (*pile == NULL)
		exit(0);
	while (tmp->next->next)
	{
		tmp = tmp->next;
	}
	while (last->next)
		last = last->next;
	last->next = *pile;
	*pile = last;
	tmp->next = NULL;
	tmp->next = NULL;
}

void	reverse_rotate_a(t_pile **pile_a)
{
	reverse_rotate(pile_a);
	write(1, "rra\n", 3);
}

void	reverse_rotate_b(t_pile **pile_b)
{
	reverse_rotate(pile_b);
	write(1, "rrb\n", 3);
}

void	reverse_rotate_both(t_pile **pile_a, t_pile **pile_b)
{
	reverse_rotate(pile_a);
	reverse_rotate(pile_b);
	write(1, "rrr\n", 3);
}
