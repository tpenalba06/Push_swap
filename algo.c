/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:00:58 by tpenalba          #+#    #+#             */
/*   Updated: 2023/07/13 17:32:31 by tpenalba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_pile **data)
{
	t_pile		*copy;
	long int	temp;

	copy = (*data);
	temp = 0;
	while (copy)
	{
		if (copy->value < temp)
			return (0);
		temp = copy->value;
		copy = copy->next;
	}
	return (1);
}

void	radix(t_pile **pile_a, t_pile **pile_b, long int size)
{
	long int	i;
	int			shift;

	shift = 0;
	while (!is_sort(pile_a))
	{
		i = 0;
		while (i < size)
		{
			if ((*pile_a)->value >> shift & 1)
				rotate_a(pile_a);
			else
				push_pb(pile_a, pile_b);
			i++;
		}
		while ((*pile_b))
			push_pa(pile_b, pile_a);
		shift++;
	}
}

void	sort_three(t_pile **pile_a)
{
	if ((*pile_a)->value > (*pile_a)->next->value
		&& (*pile_a)->next->value > (*pile_a)->next->next->value)
	{
		swap_a(pile_a);
		reverse_rotate_a(pile_a);
	}
	else if ((*pile_a)->value < (*pile_a)->next->next->value
		&& (*pile_a)->next->value > (*pile_a)->next->next->value)
	{
		swap_a(pile_a);
		rotate_a(pile_a);
	}
	else if ((*pile_a)->value > (*pile_a)->next->value
		&& (*pile_a)->value < (*pile_a)->next->next->value)
		swap_a(pile_a);
	else if ((*pile_a)->value < (*pile_a)->next->value
		&& (*pile_a)->value > (*pile_a)->next->next->value)
		reverse_rotate_a(pile_a);
	else if ((*pile_a)->next->next->value > (*pile_a)->next->value
		&& (*pile_a)->value > (*pile_a)->next->next->value)
		rotate_a(pile_a);
}

void	sort_five(t_pile **pile_a, t_pile **pile_b)
{
	int	i;
	int	min;
	int	bef_min;

	i = 0;
	min = 0;
	bef_min = 1;
	while (i < 2)
	{
		while ((*pile_a)->value != min && (*pile_a)->value != bef_min)
			rotate_a(pile_a);
		push_pb(pile_a, pile_b);
		i++;
	}
	if (!is_sort(pile_a))
		sort_three(pile_a);
	if (is_sort(pile_b))
		swap_b(pile_b);
	while (*pile_b)
		push_pa(pile_b, pile_a);
}
