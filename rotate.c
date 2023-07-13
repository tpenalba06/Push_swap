/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 19:12:21 by tpenalba          #+#    #+#             */
/*   Updated: 2023/07/12 18:01:06 by tpenalba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ra (rotate a) : Décale d’une position 
//vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.
// rb (rotate b) : Décale d’une position 
//vers le haut tous les élements de la pile b.
// Le premier élément devient le dernier.
// rr : ra et rb en même temps.

#include "push_swap.h"

void	rotate(t_pile **pile)
{
	t_pile	*first;
	t_pile	*tmp;

	first = *pile;
	tmp = *pile;
	if (*pile == NULL)
		exit(0);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = first;
	*pile = (*pile)->next;
	first->next = NULL;
}

void	rotate_a(t_pile **pile_a)
{
	rotate(pile_a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_pile **pile_b)
{
	rotate(pile_b);
	write(1, "rb\n", 3);
}

void	rotate_both(t_pile **pile_a, t_pile **pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
	write(1, "rr\n", 3);
}
