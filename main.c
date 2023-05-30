/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:56:52 by tpenalba          #+#    #+#             */
/*   Updated: 2023/05/30 16:36:47 by tpenalba         ###   ########.fr       */
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
	ft_fill(&data, pile_a, pile_b);
	system("leaks a.out");
	exit (0);
	ft_free(&data);
	return (0);
}
