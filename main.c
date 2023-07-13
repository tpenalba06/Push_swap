/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:56:52 by tpenalba          #+#    #+#             */
/*   Updated: 2023/07/13 18:10:18 by tpenalba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error404(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	sort(t_pile **pile_a, t_pile **pile_b, long int size)
{
	if (size == 2 && !is_sort(pile_a))
		swap_a(pile_a);
	else if (size == 3 && !is_sort(pile_a))
		sort_three(pile_a);
	else if (size == 5 && !is_sort(pile_a))
		sort_five(pile_a, pile_b);
	else
		radix(pile_a, pile_b, size);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	ft_checkargs(argc, argv, &data);
	ft_indexation(&data);
	ft_fill(&data, &pile_a);
	sort(&pile_a, &pile_b, data.len);
	return (0);
}
