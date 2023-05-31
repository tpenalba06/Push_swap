/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:55:14 by tpenalba          #+#    #+#             */
/*   Updated: 2023/05/30 19:06:57 by tpenalba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_pile **src, t_pile **dst)
{
	t_pile	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	if (!*dst)
		(*src)->next = NULL;
	else
		(*src)->next = (*dst);
	*dst = *src;
	*src = tmp;
}

void	push_pa(t_pile **pile_b, t_pile **pile_a)
{
	push(pile_b, pile_a);
	write(1, "pa\n", 3);
}

void	push_pb(t_pile **pile_a, t_pile **pile_b)
{
	push(pile_a, pile_b);
	write(1, "pb\n", 3);
}
