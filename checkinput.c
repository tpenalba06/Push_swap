/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 17:07:10 by tpenalba          #+#    #+#             */
/*   Updated: 2023/07/13 17:35:03 by tpenalba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkargs(int argc, char **argv, t_data *data)
{
	int	c;
	int	i;

	if (argc <= 1)
		exit (0);
	if (argc > 2)
		data->output = ft_alloc_output(argv, data, argc);
	data->nbr = 0;
	c = 1;
	i = 0;
	if (argc == 2)
	{
		c = 0;
		onearg(argc, argv, data);
		while (data->output[data->nbr])
			data->nbr++;
		argc = data->nbr;
	}
	data->len = convert(argc, data->output, data);
	ft_checkoccurence(data->tab, data);
	return (0);
}

int	convert(int argc, char **argv, t_data *data)
{
	int	c;
	int	len;

	len = 0;
	c = 1;
	if (argc == data->nbr)
		c = 0;
	data->tab = malloc(sizeof(int) * argc + 1);
	while (c < argc)
	{
		data->tab[len] = ft_atoi(argv[c]);
		if ((data->tab[len] > 2147483647) || (data->tab[len] < -2147483648))
			error404();
		c++;
		len++;
	}
	return (len);
}

void	ft_checkoccurence(int *tab, t_data *data)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 0;
	i = 0;
	while (i < data->len -1)
	{
		j = i + 1;
		while (j < data->len)
		{
			if (tab[i] == tab[j])
				error404();
			j++;
		}
		i++;
	}
}

// gerer one arge il continue de segfault donc il faut reajuster argc et c 

void	onearg(int argc, char **argv, t_data *data)
{
	int		c;
	int		nbr;

	nbr = 0;
	if (argc == 2)
	{
		data->output = ft_split(argv[1], ' ');
		c = 0;
	}
	else
		error404();
}
