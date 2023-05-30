/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:59:06 by tpenalba          #+#    #+#             */
/*   Updated: 2023/05/30 16:24:05 by tpenalba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strdup(char *src)
{
	int		size;
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	size = ft_strlen(src);
	dest = malloc ((size + 1) * sizeof (char));
	if (dest == NULL)
		return (0);
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_free(t_data *data)
{
	free(data->tab);
	free(data->index);
	free(data->output);
}

char	**ft_alloc_output(char **argv, t_data *data, int argc)
{
	int	i;

	i = 0;
	data->output = malloc(argc * sizeof (char *));
	while (argv[i])
	{
		data->output[i] = ft_strdup(argv[i]);
		i++;
	}
	return (data->output);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
