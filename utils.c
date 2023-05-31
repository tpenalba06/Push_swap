/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpenalba <tpenalba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:57:33 by tpenalba          #+#    #+#             */
/*   Updated: 2023/05/30 19:16:08 by tpenalba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *str, char c)
{
	size_t	j;
	int		i;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] != c && str[i] != '\0')
			&& (str[i + 1] == c || str[i + 1] == '\0'))
			j++;
		i++;
	}
	return (j);
}

static char	*ft_copystring(char const *s, char c, int i)
{
	char	*copy;
	int		j;
	int		len;
	int		k;

	j = i;
	while (s[j] && s[j] != c)
		j++;
	len = j - i;
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	k = 0;
	while (k < len)
	{
		copy[k] = s[i];
		k++;
		i++;
	}
	copy[k] = '\0';
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;

	strs = malloc((sizeof(char *)) * ((count_words(s, c)) + 1));
	if (!strs)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			strs[j] = ft_copystring(s, c, i);
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
		while (s[i] == c && s[i])
			i++;
	}
	strs[j] = 0;
	return (strs);
}

static int	ft_is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long long	result;

	i = 0;
	minus = 0;
	result = 0;
	while (ft_is_sign(str[i]) == 1)
	{
		if (str[i] == '-')
	minus++;
	i++;
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			error404();
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (minus % 2)
	result = result * -1;
	if ((result > 2147483647) || (result < -2147483648))
		error404 ();
	return (result);
}
