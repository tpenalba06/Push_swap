/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:56:52 by tpenalba          #+#    #+#             */
/*   Updated: 2023/05/31 17:56:33 by tpenalba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error404(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
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
	print_list(pile_a);
	print_list(pile_b);
	push_pb(&pile_a, &pile_b);
	print_list(pile_a);
	push_pa(&pile_a, &pile_b);
	swap_b(&pile_b);
	print_list(pile_a);
	print_list(pile_b);
	rotate_a(&pile_a);
	print_list(pile_a);
	// rotate_b(&pile_b);
	// print_list(pile_b);
	// system("leaks a.out");
	// exit (0);
	//ft_free(&data);
	reverse_rotate_a(&pile_a);
	print_list(pile_a);
	return (0);
}
