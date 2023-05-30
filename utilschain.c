/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilschain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 20:38:50 by tpenalba          #+#    #+#             */
/*   Updated: 2023/05/30 16:08:41 by tpenalba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// algo de radix : on trie par les unites puis par les dizaines puis par les centaines etc ...
// on est obliges de convertir les entiers en binaires car il n y a que 2 piles 
//et qu on trie d abord par 9, puis par 8, puis par 7, etc ...
// a faire :
// - remplir une liste chainee depuis mon tab d entier
// - coder les mouvements necessaires a radix : push a, push b, rotate a, rotate b
// - exceptions a gerer pour plus tard : les 3 et les 5 (radix ne fonctionne pas)

int	ft_fill(t_data *data, t_pile *pile_a, t_pile *pile_b)
{
	int	i;

	i = 0;
	printf("%d\n", data->len);
	while (i < data->len)
	{
		printf("%d\n", data->index[i]);
		add_data_to_list(&pile_a, data->index[i]);
		i++;
	}
	printf("Pile A:\n");
	print_list(pile_a);
	printf("Pile B:\n");
	print_list(pile_b);
	return (0);
}

void	add_data_to_list(t_pile **list, int value)
{
	t_pile	*new_element;
	t_pile	*last_element;

	new_element = malloc(sizeof(t_pile));
	if (!new_element)
		return ;
	new_element->data = value;
	new_element->next = NULL;
	if (*list == NULL)
	{
		*list = new_element;
		return ;
	}
	last_element = *list;
	while (last_element->next != NULL)
		last_element = last_element->next;
	last_element->next = new_element;
}

void	print_list(t_pile *pile_a)
{
	t_pile	*copy;

	copy = pile_a;
	while (copy)
	{
		printf(" %ld ->", copy->data);
		copy = copy->next;
	}
	printf ("NULL\n");
}

void	ft_indexation(t_data *data)
{
	int	i;
	int	j;
	int	count_index;

	i = 0;
	j = 0;
	count_index = 0;
	data->index = malloc(sizeof(int) * data->len + 1);
	if (!data->index)
		exit (0);
	while (i < data->len)
	{
		j = 0;
		while (j < data->len)
		{
			if (data->tab[i] > data->tab[j])
				count_index++;
			j++;
		}
		data->index[i] = count_index;
		count_index = 0;
		i++;
	}
}
